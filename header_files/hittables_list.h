#pragma once

#include "hittable.h"
#include "ray_tracer_utils.h"

#include <vector>

class hittables_list:public hittable{
public:
	std::vector<std::shared_ptr<hittable>> objects;

	hittables_list() {}
	hittables_list(std::shared_ptr<hittable> object) {add(object);}

	void clear() {objects.clear();}

	void add(std::shared_ptr<hittable> object) { objects.push_back(object);}

	bool hit(const ray& r, double ray_min, double ray_max, hit_record& rec) const override{
		hit_record temp_rec;
		bool hit_anything = false;
		auto closest_so_far = ray_max;

		for (const auto& object:objects){
			if(object->hit(r,ray_min,closest_so_far,temp_rec)){
				hit_anything = true;
				closest_so_far = temp_rec.t;
				rec = temp_rec;
				
			}	
		}
		return hit_anything;

	}



};
