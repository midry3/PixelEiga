#pragma once
#include "Vector2D.h"
#include <variant>

namespace PixelEiga {
	double ToDouble(const std::variant<double, float, int>& v);

	int Abs(int a);
	double Abs(double a);

	int Max(int a, int b);
	double Max(double a, double b);
	Vector2D Max(const Vector2D& a, const Vector2D& b);
	template <typename T>
	T Max(const T& a, const T& b) {
		return a > b ? a : b;
	}

	int Min(int a, int b);
	double Min(double a, double b);
	Vector2D Min(const Vector2D& a, const Vector2D& b);
	template <typename T>
	T Min(const T& a, const T& b) {
		return a < b ? a : b;
	}

	int Clamp(int value, int min, int max);
	double Clamp(double value, double min, double max);
	Vector2D Clamp(const Vector2D& value, const Vector2D& min, const Vector2D& max);

	int Sign(double x);

	template<typename... Args>
		requires (std::is_arithmetic_v<Args> && ...)
	double GetNearest(double base, Args... args) {
		double min = (std::numeric_limits<double>::max)();
		double res = base;
		for (double value : { static_cast<double>(args)... }) {
			double diff = std::abs(value - base);
			if (diff < min) {
				res = value;
				min = diff;
			}
		}
		return res;
	}

	int GetRandomInt(int min, int max);
	double GetRandomDouble(double min, double max);

	Vector2D GetRandomVector2D(Vector2D min, Vector2D max);
	Vector2D GetRandomIntVector2D(Vector2D min, Vector2D max);

	template <typename... Args>
	bool MatchAny(const int n, Args... args) {
		return ((n == args) || ...);
	}
}