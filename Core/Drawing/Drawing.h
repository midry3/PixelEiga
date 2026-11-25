#pragma once
#include <PixelEigaCore.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <string>
#include <Math/Vector4D.h>

namespace PixelEiga
{
	class Drawing {
	private:
		SDL_Renderer* _renderer;
	public:
		Drawing() = default;
		~Drawing() = default;
		Drawing(SDL_Renderer* renderer) : _renderer(renderer) {}

		void SetRenderer(SDL_Renderer* renderer) { _renderer = renderer; }
		[[nodiscard]] SDL_Renderer* GetRenderer() const { return _renderer; }

		void DrawRect(const Vec2& position, const Vec2& size, const Vec4& color);
		void DrawTexture(SDL_Texture* texture, const Vec2& position, const Vec2& scale, const Vec4& color);
	};
}