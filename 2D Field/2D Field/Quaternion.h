#pragma once

#include "Vector2.h"

class Quaternion
{
public:
	float x, y, z, w;

	Quaternion() : x(0), y(0), z(0), w(1) {}
	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	static Quaternion Euler(float z);

	Quaternion Normalized() const;

	float Dot(const Quaternion& q) const;

	float SqrMagnitude() const;
	float Magnitude() const;

	Quaternion Conjugate() const;
	Quaternion Inverse() const;


	bool operator == (const Quaternion& q) const { return x == q.x && y == q.y && z == q.z && w == q.w; }
	bool operator != (const Quaternion& q) const { return x != q.x || y != q.y || z != q.z || w != q.w; }

	Quaternion& operator = (const Quaternion& value);

	Quaternion& operator += (const Quaternion& aQuat);
	Quaternion& operator -= (const Quaternion& aQuat);
	Quaternion& operator *= (float aScalar);
	Quaternion& operator *= (const Quaternion& aQuat);
	Quaternion& operator /= (float aScalar);

	Quaternion operator * (float aScalar) const;
	Quaternion operator / (float aScalar) const;

	Quaternion operator * (const Quaternion& aQuat) const;

	Quaternion operator * (const Vector2& aQuat) const;

	friend Vector2 operator * (const Vector2& aVec, const Quaternion& bQuat);

	static Quaternion identity;
};
