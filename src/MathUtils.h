#pragma once
#include "raylib.h"
#include <cstdlib>
#include <algorithm>

inline float randomf()
{
	return (float)rand() / RAND_MAX;
}

inline float randomf(float max)
{
	return randomf() * max;
}

inline float randomf(float min, float max)
{
	if (min > max) std::swap(min, max);
	return min + randomf() * (max - min);
}

inline Vector2 randomOnUnitCircle()
{
	float theta = randomf(0, 2 * PI);

	return { cosf(theta), sinf(theta) };
}