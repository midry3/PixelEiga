#pragma once

namespace PixelEiga {
	class Vector3D {
	public:
		float x;
		float y;
		float z;
		constexpr Vector3D() : x(0), y(0), z(0) {}
		constexpr Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}
		Vector3D operator+(const Vector3D& other) const {
			return Vector3D(x + other.x, y + other.y, z + other.z);
		}
		Vector3D operator-() const {
			return Vector3D(-x, -y, -z);
		}
		Vector3D operator-(const Vector3D& other) const {
			return Vector3D(x - other.x, y - other.y, z - other.z);
		}
		Vector3D operator*(float a) const {
			return Vector3D(x * a, y * a, z * a);
		}
		Vector3D operator/(float a) const {
			return Vector3D(x / a, y / a, z / a);
		}
	};

	using Vec3 = Vector3D;
}