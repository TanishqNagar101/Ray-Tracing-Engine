#pragma once
#include "vec3.h"

using point=vec3;

class ray{
	point orig;
	point dir;
public:
	ray() {}
	ray(const point& origin, const point& direction):orig(origin), dir(direction) {}

	const point& origin() const {return orig;}
	const point& direction() const {return dir;}

	point at(double t) const{
		return orig + (t*dir);
	}


};
