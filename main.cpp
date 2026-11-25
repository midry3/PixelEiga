#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "AppState.h"
#include "Config.h"
#include <Drawing/Drawing.h>
#include <Component/Component.h>
#include <Component/DialogBox.h>

using namespace PixelEiga;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	AppState* state = new AppState();
    *appstate = state;

    SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.example.renderer-clear");

    if (not SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

	if (not TTF_Init()) {
		SDL_Log("Couldn't initialize SDL_ttf: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

    if (not SDL_CreateWindowAndRenderer("examples/renderer/clear", 1280, 720, SDL_WINDOW_RESIZABLE, &state->window, &state->renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(state->renderer, 1280, 720, SDL_LOGICAL_PRESENTATION_LETTERBOX);
	state->drawing = new Drawing(state->renderer);
	Config conf = Config();

	state->fontManager = new FontManager();

	for (const auto& font : conf.useFonts) {
		state->fontManager->AddFont(new Font(font.path));
	}
	auto dialogBox = new DialogBox(state);
	dialogBox->Initialize();
	dialogBox->SetTextBoxPosition({ 0.0f, 500.0f });
	dialogBox->SetTextBoxSize({ 1280.0f, 220.0f });
	dialogBox->SetSpeakerPosition({ 10.0f, 510.0f });
	dialogBox->SetTextPosition({ 10.0f, 540.0f });
	state->components.emplace_back(dialogBox);
    state->prevTime = (static_cast<float>(SDL_GetTicks())) / 1000.0f;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
	AppState* state = static_cast<AppState*>(appstate);

    const float now = (SDL_GetTicks()) / 1000.0f;
	state->deltaTime = now - state->prevTime;
    state->prevTime = now;

    SDL_SetRenderDrawColorFloat(state->renderer, 0.0, 0.0, 0.0, SDL_ALPHA_OPAQUE_FLOAT);  /* new color, full alpha. */
    SDL_RenderClear(state->renderer);

	for (const auto& component : state->components) {
		component->Update(state->deltaTime);
	}
    for (const auto& component : state->components) {
        component->Draw();
    }

    SDL_RenderPresent(state->renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
	AppState* state = static_cast<AppState*>(appstate);

	TTF_Quit();
	SDL_DestroyRenderer(state->renderer);
	SDL_DestroyWindow(state->window);

	delete state;
	SDL_Quit();
}