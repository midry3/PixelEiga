#pragma once

namespace PixelEiga {
	class Vector4D {
	public:
		float x;
		float y;
		float z;
		float w;
		constexpr Vector4D() : x(0), y(0), z(0), w(0) {}
		constexpr Vector4D(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		Vector4D operator+(const Vector4D& other) const {
			return Vector4D(x + other.x, y + other.y, z + other.z, w + other.w);
		}
		Vector4D operator-() const {
			return Vector4D(-x, -y, -z, -w);
		}
		Vector4D operator-(const Vector4D& other) const {
			return Vector4D(x - other.x, y - other.y, z - other.z, w - other.w);
		}
		Vector4D operator*(float a) const {
			return Vector4D(x * a, y * a, z * a, w * a);
		}
		Vector4D operator/(float a) const {
			return Vector4D(x / a, y / a, z / a, w / a);
		}
	};

	using Vec4 = Vector4D;
}