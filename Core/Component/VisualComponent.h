#pragma once
#include "Component.h"
#include <Math/Vector2D.h>

namespace PixelEiga
{
	class VisualComponent : public Component {
	private:
		Vec2 _position = Vec2(0.0, 0.0);
	public:
		VisualComponent() = default;
		VisualComponent(AppState* appState) : Component(appState) {}
		VisualComponent(AppState* appState, const Vec2& position) : Component(appState), _position(position) {}
		~VisualComponent() = default;
		void SetPosition(const Vec2& position) { _position = position; }
		[[nodiscard]] const Vec2& GetPosition() const { return _position; }
	};
}