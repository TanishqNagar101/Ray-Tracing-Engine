#pragma once

#include "ray_tracer_utils.h"
#include "hittable.h"

class sphere:public hittable{
public:
	sphere(const point3& center, double radius):center(center),radius(std::fmax(0,radius)) {}
	
	bool hit(const ray& r, interval ray_t, hit_record& rec )const override{
		vec3 oc = center-r.origin();
		double a=dot(r.direction(),r.direction());
		double h=dot(r.direction(),oc);
		double c=oc.length_squared()- (radius*radius);
		double D=h*h-a*c;
	
		if(D<0) return false;
		
		auto sqrtD = std::sqrt(D);

		//Nearest Root
		auto root = (h-sqrtD)/a;
		if(!ray_t.surrounds(root)){
			root = (h+sqrtD)/a;
			if (!ray_t.surrounds(root)) return false;
		};

		rec.t = root;
		rec.p = r.at(root);
		vec3 outward_normal = (rec.p - center)/radius;
		rec.set_face_normal(r, outward_normal);

		return true;

	};
private:
	point3 center;
	double radius;
	
	
};
