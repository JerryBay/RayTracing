#pragma once
#include<iostream>
#include<limits>
#include<random>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees)
{
	return degrees * pi / 180.0;
}

inline double clamp(double x, double min, double max) {
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

inline double random_double()
{
	static std::uniform_real_distribution<double> distribute(0.0, 1.0);
	static std::mt19937 generator;
	return distribute(generator);
}

inline double random_double(double min,double max)
{
	return min + (max - min) * random_double();
}