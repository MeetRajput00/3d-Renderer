#pragma once
#ifndef COMMON_CONSTANTS_H
#define COMMON_CONSTANTS_H


//includes
#include<math.h>
#include<limits>
#include<memory>
#include<vector>
#include"Ray.h"
#include"Vec3.h"

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



#endif // !Common_Constants_H
