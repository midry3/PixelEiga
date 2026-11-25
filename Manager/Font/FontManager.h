#pragma once
#include "Font.h"
#include <vector>

namespace PixelEiga {
	class FontManager {
	private:
		std::vector<Font*> _fonts;
	public:
		FontManager() = default;
		~FontManager();

		void AddFont(Font* font);
		Font* Get(int index);
	};
}