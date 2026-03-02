#pragma once
#include "vec3.h"

using point=vec3;

class ray{
	point orig;
	point dir;
public:
	ray() {}
	ray(const point& origin, const point& direction):orig(origin), dir(direction) {}

	const point& origin() {return orig};
	const point& direction() {return dir};

	point at(double t){
		return orig + (t*dir);
	}


};
