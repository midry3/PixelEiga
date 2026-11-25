#include "Vector2D.h"
#include "Utils.h"

namespace  PixelEiga {
	bool IsColliding1D(float a1, float a2, float b1, float b2) {
		return b1 <= a2 && a1 <= b2;
	}

	Vector2D Sign(const Vector2D& v) {
		return Vector2D(Sign(v.x), Sign(v.y));
	}

	Vector2D operator*(int a, const Vector2D& v) {
		return Vector2D(a * v.x, a * v.y);
	}

	Vector2D operator*(float a, const Vector2D& v) {
		return Vector2D(a * v.x, a * v.y);
	}
}