#pragma once
#ifndef COMMON_CONSTANTS_H
#define COMMON_CONSTANTS_H


//includes
#include<math.h>
#include<limits>
#include<memory>
#include<vector>
#include<random>

//usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;
using std::vector;

//constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi= 3.1415926535897932385;

//utility functions
inline double degrees_to_radians(double degrees) {
	return degrees * pi / 180.0;
}

inline double random_double() {
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937 generator; // Mersenne Twister 19937 generator
	return distribution(generator);
}
inline double random_double(double min, double max) {
	return min + (max - min) * random_double();
}
inline double clamp(double x, double min, double max) {
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

#endif // !Common_Constants_H
