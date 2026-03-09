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
	virtual bool hit(const ray& r, double ray_min, double ray_max, const hit_record& rec ) const =0;


};


