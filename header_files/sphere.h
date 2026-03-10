#pragma once

#include "vec3.h"
#include "hittable.h"

class sphere:public hittable{
public:
	sphere(cosnt point3& center, double radius):center(center),radius(std::fmax(0,radius)) {}
	
	bool hit(const ray& r, double t_min, double t_max, const hit_record& rec )const override{
		vec3 oc = center-r.origin();
		double a=dot(r.direction(),r.direction());
		double h=dot(r.direction(),oc);
		double c=dot(oc,oc)- (radius*radius);
		double D=h*h-a*c;
	
		if(D<0) return false;
		
		auto sqrtD = std::sqrt(D);

		//Nearest Root
		auto root = (h-sqrtD)/a;
		if(root<=t_min || root<=t_max){
			root = (h+sqrtD)/a;
			if(root<=t_min || root<=t_max) return false;
		};

		rec.t = root;
		rec.p = r.at(root);
		vec3 outward_normal = (rec.p - center)/radius;
		rec.set_face_normal(r, outward_normal);

		return true

	}
private:
	point 3 center;
	double radius;
	
	
};
