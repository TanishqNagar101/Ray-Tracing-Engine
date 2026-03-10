#pragma once

#include"ray.h"

class hit_record{
public:
	point3 p;
	vec3 normal;
	double t;
	bool front_face;

	void set_front_normal(const ray& r, const vec3& outward_normal){
		//For the set record normal
		//Outward normal is assumed to have unit length. Why?? 
		front_face = dot(r.direction(),outward_normal)<0 ;
		normal = front_face?outward_normal:-outward_normal;
	}


};

class hittable{
public:
	virtual ~hittable() = default;
	virtual bool hit(const ray& r, double ray_min, double ray_max, const hit_record& rec ) const =0;


};


