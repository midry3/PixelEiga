#pragma once
#include <AppState.h>
#include <Drawing/Drawing.h>

namespace PixelEiga
{
	class Component {
	private:
		AppState* _appState = nullptr;
	public:
		Component() = default;
		Component(AppState* appState) : _appState(appState) {}
		~Component() = default;

		virtual void Initialize() {};
		virtual void Update(float dt) {};
		virtual void Draw() {};

		void SetAppState(AppState* appState) { _appState = appState; }
		[[nodiscard]] AppState* GetAppState() const { return _appState; }
		[[nodiscard]] Drawing* GetDrawing() const { return _appState->drawing; }
		[[nodiscard]] FontManager* GetFontManager() const { return _appState->fontManager; }
	};
}