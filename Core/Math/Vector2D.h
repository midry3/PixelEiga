#pragma once
#include <cmath>
#include <functional>

namespace PixelEiga {
	bool IsColliding1D(float a1, float a2, float b1, float b2);

	class Vector2D {
	public:
		float x = 0.0, y = 0.0;
		constexpr Vector2D() : x(0), y(0) {}
		constexpr Vector2D(float x, float y) : x(x), y(y) {}
		Vector2D operator+(const Vector2D& other) const {
			return Vector2D(x + other.x, y + other.y);
		}
		Vector2D operator-() const {
			return Vector2D(-x, -y);
		}
		Vector2D operator-(const Vector2D& other) const {
			return Vector2D(x - other.x, y - other.y);
		}
		Vector2D operator*(float a) const {
			return Vector2D(x * a, y * a);
		}
		Vector2D operator*(const Vector2D& other) const {
			return Vector2D(x * other.x, y * other.y);
		}
		Vector2D operator/(float a) const {
			return Vector2D(x / a, y / a);
		}
		Vector2D operator/(const Vector2D& other) const {
			return Vector2D(x / other.x, y / other.y);
		}
		Vector2D& operator+=(const Vector2D& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
		Vector2D operator-=(const Vector2D& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		Vector2D operator*=(float a) {
			x *= a;
			y *= a;
			return *this;
		}
		Vector2D operator*=(const Vector2D& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}
		bool operator==(const Vector2D& other) const {
			return x == other.x && y == other.y;
		}
		bool operator!=(const Vector2D& other) const {
			return !(*this == other);
		}
		float Product(const Vector2D& other) const {
			return x * other.y - y * other.x;
		}
		float Dot(const Vector2D& other) const {
			return x * other.x + y * other.y;
		}
		float Length() const {
			return sqrt(x * x + y * y);
		}
		Vector2D Normalized() const {
			auto length = Length();
			if (length == 0) return Vector2D(0, 0);
			return Vector2D(x / length, y / length);
		}
		Vector2D Normalized(float length) const {
			return Normalized() * length;
		}
		void NormalizeTo(float length) {
			float abs = Length();
			if (abs != 0) {
				x /= abs;
				y /= abs;
				x *= length;
				y *= length;
			}
		}
		Vector2D Perpendicular() const {
			return Vector2D(-y, x);
		}
		Vector2D Perpendicular(const Vector2D& line) const {
			return *this - line * (this->Dot(line) / line.Dot(line));
		}
		Vector2D Sign() const {
			int sx, sy;
			if (x > 0) sx = 1;
			else if (x < 0) sx = -1;
			else sx = 0;
			if (y > 0) sy = 1;
			else if (y < 0) sy = -1;
			else sy = 0;
			return Vector2D(sx, sy);
		}
		Vector2D Abs() const {
			return Vector2D(std::abs(x), std::abs(y));
		}

		template <typename T>
		T* ToArray() const {
			T arr[2];
			arr[0] = static_cast<T>(x);
			arr[1] = static_cast<T>(y);
			return arr;
		}

		template <typename T>
		void AssignToArray(T* target) const {
			target[0] = static_cast<T>(x);
			target[1] = static_cast<T>(y);
		}
	};

	Vector2D operator*(int a, const Vector2D& v);
	Vector2D operator*(float a, const Vector2D& v);

	Vector2D Sign(const Vector2D& v);

	constexpr Vector2D Vec2D_0(0.0, 0.0);
	constexpr Vector2D Vec2D_1(1.0, 1.0);
	constexpr Vector2D Vec2D_Up(0.0, -1.0);
	constexpr Vector2D Vec2D_Down(0.0, 1.0);
	constexpr Vector2D Vec2D_Left(-1.0, 0.0);
	constexpr Vector2D Vec2D_Right(1.0, 0.0);

	class Vector2DFunction : public Vector2D {
	protected:
		std::function<float(float)> funcX;
		std::function<float(float)> funcY;
		bool _sumMode = false;
	public:
		Vector2DFunction() = default;
		Vector2DFunction(std::function<float(float)> funcX, std::function<float(float)> funcY, bool sumMode = false) : funcX(funcX), funcY(funcY), _sumMode(sumMode) {}
		Vector2D operator()(float t) {
			Update(t);
			return Vector2D(x, y);
		}
		void Update(float t) {
			if (_sumMode) {
				x += funcX(t);
				y += funcY(t);
			}
			else {
				x = funcX(t);
				y = funcY(t);
			}
		}
	};

	using Vec2 = Vector2D;
}