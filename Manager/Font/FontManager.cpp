#include "FontManager.h"

namespace PixelEiga {
	FontManager::~FontManager() {
		_fonts.clear();
	}

	void FontManager::AddFont(Font* font) {
		_fonts.push_back(font);
	}

	Font* FontManager::Get(int index) {
		if (_fonts.size() <= index) {
			SDL_Log("Invalid font index, %d", index);
			return NULL;
		}

		return _fonts[index];
	}
}