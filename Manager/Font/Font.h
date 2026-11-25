#pragma once
#include <SDL3_ttf/SDL_ttf.h>
#include <memory>
#include <string>
#include <map>


namespace PixelEiga {
	class Font {
	private:
		std::string _path;
		std::map<float, TTF_Font*> _fontCaches;
	public:
		Font(std::string path) : _path(path) {}
		~Font();

		TTF_Font* CreateFont(float size);
	};
}