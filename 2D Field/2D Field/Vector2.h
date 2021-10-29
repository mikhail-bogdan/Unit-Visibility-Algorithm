#pragma once

class Vector2
{
public:
	float x, y;

	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}

	float Magnitude();
	float SqrMagnitude();

	Vector2 operator+(const Vector2& value) const;
	Vector2 operator-(const Vector2& value) const;

	static float SqrDistance(const Vector2& a, const Vector2& b);

	static Vector2 zero;
	static Vector2 up;
	static Vector2 down;
	static Vector2 right;
	static Vector2 left;
};