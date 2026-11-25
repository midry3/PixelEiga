#include "Font.h"

namespace PixelEiga {
	Font::~Font() {
		for (const auto& [_, font] : _fontCaches) {
			TTF_CloseFont(font);
		}
	}

	TTF_Font* Font::CreateFont(float size) {
		if (not _fontCaches.contains(size)) {
			TTF_Font* font = TTF_OpenFont(_path.c_str(), size);
			if (font) {
				_fontCaches[size] = font;
			}
			else {
				SDL_Log("Faild to create, %s", _path);
				return NULL;
			}
		}

		return _fontCaches.at(size);
	}
}