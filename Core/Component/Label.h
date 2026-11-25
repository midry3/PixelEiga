#pragma once
#include "VisualComponent.h"
#include <SDL3_ttf/SDL_ttf.h>

namespace PixelEiga
{
	class Label : public VisualComponent {
	private:
		std::string _text;
		Vec4 _color;
		TTF_Font* _font;
		SDL_Texture* _texture;
		int _width = 0, _readLength = 0;

		void ConstructTexture();
		void FreeTexture();
	public:
		Label() = default;
		~Label();
		Label(AppState* appState)
			: VisualComponent(appState) {}
		Label(AppState* appState, const std::string& text, const Vec2& position, const Vec4& color, TTF_Font* font)
			: VisualComponent(appState, position), _text(text), _color(color), _font(font) {}
		void SetText(const std::string& text);
		void SetColor(const Vec4& color) { _color = color; }
		void SetFont(TTF_Font* font);
		void SetWidth(int width);
		void SetReadLength(int length);
		void Draw() override;
		void Update(float dt) override {}
		void Initialize() override {}
		[[nodiscard]] const std::string& GetText() const { return _text; }
		[[nodiscard]] const Vec4& GetColor() const { return _color; }
		[[nodiscard]] TTF_Font* GetFont() const { return _font; }
		[[nodiscard]] int GetWidth() const { return _width; }
		[[nodiscard]] int GetReadLength() const { return _readLength; }
	};
}