#pragma once
#include <SDL3/SDL.h>
#include <Manager/Font/FontManager.h>
#include <vector>
#include <memory>

namespace PixelEiga {
	class Drawing;
	class Component;

	struct AppState {
		SDL_Window* window;
		SDL_Renderer* renderer;
		PixelEiga::FontManager* fontManager;
		PixelEiga::Drawing* drawing;
		std::vector<PixelEiga::Component*> components;
		float prevTime, deltaTime;
	};
}