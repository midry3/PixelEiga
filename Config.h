#pragma once
#include <string>
#include <vector>

namespace PixelEiga {
	struct FontInfo {
		std::string path;
		std::vector<float> sizes;
	};

	struct Config {
		int windowWidth = 1280;
		int windowHeight = 720;
		bool fullscreen = false;
		bool vsync = true;
		bool debugMode = false;

		FontInfo useFonts[1] = {
			{
				"_Assets/fonts/x8y12pxDenkiChip.ttf",
				{ 36 }
			}
		};
	};
}