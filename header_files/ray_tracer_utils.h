#pragma once

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

//Common headers
#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "ppm.h"
// using common names
using color = vec3;
using point3 = vec3;

//Constants 
const double inf = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//utility_functions
inline double degree_to_radians(double degree){
	return degree *pi/180.0;
};


