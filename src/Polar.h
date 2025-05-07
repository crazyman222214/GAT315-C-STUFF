#pragma once
#include "raymath.h"
struct Polar
{
public:
	Polar() = default;
	Polar(float angle, float radius) :
		angle{ angle },
		radius{ radius }
	{
	}

	Polar(const Vector2& v) :
		angle{ atan2(v.y, v.x)},//!!get angle from Vector2 !!},
		radius{ Vector2Length(v) }//!!get vector length !!}
	{
	}

	Polar& operator = (const Vector2& v)
	{
		angle = atan2(v.y, v.x);
		radius = Vector2Length(v);
		return *this;
	}

	operator Vector2() const
	{
		Vector2 v;
		v.x = cos(angle)* radius;
		v.y = sin(angle)* radius;

		return v;
	}

public:
	float angle{ 0 };
	float radius{ 0 };
};