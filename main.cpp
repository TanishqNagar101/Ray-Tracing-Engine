#include <vector>
#include "header_files/ray_tracer_utils.h"

#include "header_files/hittable.h"
#include "header_files/hittables_list.h"
#include "header_files/sphere.h"


color ray_color(const ray& r, const hittable& world){
	hit_record rec;
	if(world.hit(r, 0, inf, rec)){
		return 0.5*(rec.normal+color(1,1,1));
	}
	
	vec3 unit_vector = normalize(r.direction());
	auto t = 0.5*(unit_vector.y+1);
	auto mix = (1.0-t)*color(1,1,1) + t*color(0.5, 0.7, 1.0);
	return mix;

};

int main(){
	auto aspect_ratio=16.0/9.0;
	int image_width = 400;
	//Calculating Height
	int image_height = image_width/aspect_ratio;
	image_height = image_height<1?1:image_height;
	
	//Creating the view port
	auto viewport_height = 2.0;//This is an arbritary number
	auto viewport_width = viewport_height * (double(image_width)/image_height);
	
	//World
	hittables_list world;
	world.add(std::make_shared<sphere>(point3(0,0,-1), 0.5));
	world.add(std::make_shared<sphere>(point3(0,-100.5,-1),100));


	//Camera setup
	point3 camera_center = point3(0,0,0);
	
	//Viewport vector setup
	vec3 viewport_u = vec3(viewport_width,0,0);
	vec3 viewport_v = vec3(0,-viewport_height,0);

	//Movement setup
	auto delta_u = viewport_u/image_width;
	auto delta_v = viewport_v/image_height;

	//Position the cursor to top left and vec3(0,0,1) here we are going camera to viewpoint the distance
	auto top_left = camera_center - vec3(0,0,1) - viewport_u/2.0 - viewport_v/2.0; 

	//First Pixel Location
	auto pixel00_loc = top_left + 0.5 * (delta_u+delta_v);

	//Vector array creation
	std::vector<vec3> img(image_width*image_height);
	for(int r=0;r<image_height;r++){
		for(int c=0;c<image_width;c++){
			auto pixel_center = pixel00_loc + (c*delta_u) + (r*delta_v);
			auto ray_direction = pixel_center - camera_center;
			
			ray current_ray(camera_center, ray_direction);
			
			color pixel_color = ray_color(current_ray, world);
			// Array Filling
			int idx = (image_width*r) + c;
			img[idx] = pixel_color;
		};
	};
	generate(img,image_width,image_height);
}
