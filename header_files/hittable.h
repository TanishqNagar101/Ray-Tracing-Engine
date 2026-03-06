#pragma once

#include"ray.h"

class hit_record{
public:
	point3 p;
	vec3 normal;
	double t;


};

class hittable{
public:
	virtual ~hittable() = default;
	virtual bool hit(const ray& ray, )


};


