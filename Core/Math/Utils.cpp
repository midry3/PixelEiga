#include "Utils.h"

namespace PixelEiga {
	double ToDouble(const std::variant<double, float, int>& v) {
		if (std::holds_alternative<double>(v)) {
			return std::get<double>(v);
		}
		else if (std::holds_alternative<float>(v)) {
			return static_cast<double>(std::get<float>(v));
		}
		else if (std::holds_alternative<int>(v)) {
			return static_cast<double>(std::get<int>(v));
		}
		return 0.0;
	}

	int Abs(int a) {
		return (a < 0) ? -a : a;
	}

	double Abs(double a) {
		return (a < 0) ? -a : a;
	}

	int Max(int a, int b) {
		return (a > b) ? a : b;
	}

	double Max(double a, double b) {
		return (a > b) ? a : b;
	}

	Vector2D Max(const Vector2D& a, const Vector2D& b) {
		return Vector2D(Max(a.x, b.x), Max(a.y, b.y));
	}

	int Min(int a, int b) {
		return (a < b) ? a : b;
	}

	double Min(double a, double b) {
		return (a < b) ? a : b;
	}

	Vector2D Min(const Vector2D& a, const Vector2D& b) {
		return Vector2D(Min(a.x, b.x), Min(a.y, b.y));
	}

	int Clamp(int value, int min, int max) {
		if (value < min) return min;
		if (value > max) return max;
		return value;
	}

	double Clamp(double value, double min, double max) {
		if (value < min) return min;
		if (value > max) return max;
		return value;
	}

	Vector2D Clamp(const Vector2D& value, const Vector2D& min, const Vector2D& max) {
		return Vector2D(Clamp(value.x, min.x, max.x), Clamp(value.y, min.y, max.y));
	}

	int Sign(double x) {
		if (x > 0) return 1;
		if (x < 0) return -1;
		return 0;
	}

	int GetRandomInt(int min, int max) {
		return min + rand() % (max - min);
	}

	double GetRandomDouble(double min, double max) {
		return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
	}

	Vector2D GetRandomVector2D(Vector2D min, Vector2D max) {
		double x = min.x + static_cast<double>(rand()) / RAND_MAX * (max.x - min.x);
		double y = min.y + static_cast<double>(rand()) / RAND_MAX * (max.y - min.y);
		return Vector2D(x, y);
	}

	Vector2D GetRandomIntVector2D(Vector2D min, Vector2D max) {
		int x = static_cast<int>(min.x) + rand() % static_cast<int>(max.x - min.x);
		int y = static_cast<int>(min.y) + rand() % static_cast<int>(max.y - min.y);
		return Vector2D(x, y);
	}
}