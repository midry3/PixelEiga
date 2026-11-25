#include "Drawing.h"

namespace PixelEiga
{
	void Drawing::DrawRect(const Vec2& position, const Vec2& size, const Vec4& color) {
		SDL_FRect rect;
		rect.x = position.x;
		rect.y = position.y;
		rect.w = size.x;
		rect.h = size.y;
		SDL_SetRenderDrawColorFloat(GetRenderer(), color.x, color.y, color.z, color.w);
		SDL_RenderFillRect(GetRenderer(), &rect);
	}

	void Drawing::DrawTexture(SDL_Texture* texture, const Vec2& position, const Vec2& scale, const Vec4& color) {
		if (texture == nullptr) {
			return;
		}

		float texW = 0.0f, texH = 0.0f;
		if (not SDL_GetTextureSize(texture, &texW, &texH)) {
			return;
		}

		int logicalW = 0, logicalH = 0;
		SDL_RendererLogicalPresentation mode;
		SDL_GetRenderLogicalPresentation(GetRenderer(), &logicalW, &logicalH, &mode);

		SDL_FRect dst;
		dst.w = texW * scale.x;
		dst.h = texH * scale.y;
		dst.x = position.x + (logicalW - dst.w) / 2.0f;
		dst.y = position.y + (logicalH - dst.h) / 2.0f;

		SDL_SetTextureColorModFloat(texture, color.x, color.y, color.z);
		SDL_SetTextureAlphaModFloat(texture, color.w);
		SDL_RenderTexture(GetRenderer(), texture, nullptr, &dst);
		SDL_SetTextureColorModFloat(texture, 1.0f, 1.0f, 1.0f);
		SDL_SetTextureAlphaModFloat(texture, 1.0f);
	}
}