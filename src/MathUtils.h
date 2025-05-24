#pragma once
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