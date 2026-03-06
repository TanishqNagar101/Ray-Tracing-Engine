#pragma once
#include "vec3.h"

using point3=vec3;

class ray{
	point3 orig;
	point3 dir;
public:
	ray() {}
	ray(const point3& origin, const point& direction):orig(origin), dir(direction) {}

	const point3& origin() const {return orig;}
	const point3& direction() const {return dir;}

	point3 at(double t) const{
		return orig + (t*dir);
	}


};
