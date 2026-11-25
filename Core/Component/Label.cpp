#include "Label.h"

namespace PixelEiga
{
	Label::~Label() {
		FreeTexture();
	}

	void Label::FreeTexture() {
		if (_texture) {
			SDL_DestroyTexture(_texture);
			_texture = nullptr;
		}
	}

	void Label::ConstructTexture() {
		if (not _font) return;
		FreeTexture();

		if (_text.empty()) {
			return;
		}

		SDL_Surface* surface;
		if (0 < _width) {
			surface = TTF_RenderText_Solid_Wrapped(_font, _text.c_str(), _readLength, { static_cast<Uint8>(_color.x * 255), static_cast<Uint8>(_color.y * 255), static_cast<Uint8>(_color.z * 255), static_cast<Uint8>(_color.w * 255) }, _width);
		}
		else {
			surface = TTF_RenderText_Solid(_font, _text.c_str(), _readLength, { static_cast<Uint8>(_color.x * 255), static_cast<Uint8>(_color.y * 255), static_cast<Uint8>(_color.z * 255), static_cast<Uint8>(_color.w * 255) });
		}

		if (surface) {
			_texture = SDL_CreateTextureFromSurface(GetDrawing()->GetRenderer(), surface);
			SDL_DestroySurface(surface);

			if (not _texture) {
				SDL_Log("Couldn't create texture from surface: %s", SDL_GetError());
				return;
			}
		}
	}

	void Label::SetText(const std::string& text) {
		_text = text;
		ConstructTexture();
	}
	void Label::SetFont(TTF_Font* font) {
		_font = font;
		ConstructTexture();
	}
	void Label::SetWidth(int width) {
		_width = width;
		ConstructTexture();
	}
	void Label::SetReadLength(int length) {
		_readLength = Clamp(length, 0, static_cast<int>(_text.size()));
		ConstructTexture();
	}
	void Label::Draw() {
		if (_texture) {
			GetDrawing()->DrawTexture(_texture, GetPosition(), { 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f });
		}
	}
}