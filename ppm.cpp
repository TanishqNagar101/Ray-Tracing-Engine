//This is for ppm file format
#include "header_files/ppm.h"
#include "header_files/vec3.h"
#include <iostream>
#include <fstream>
#include <algorithm>

bool generate(const std::vector<vec3>& v, int width,int height){
	if(v.size() != static_cast<size_t>(width*height)){
		std::cerr<<"Buffer size mismatch\n";
		return false;
	};

	std::ofstream file("image.ppm");
	if(!file){
		std::cerr<<"Failed to open file\n";
		return false;
	};

	file<<"P3\n"<<width<<" "<<height<<"\n255\n";
	
	int total_pixel=static_cast<int>(v.size());
	
	for(int i=0;i<total_pixel;i++){
		const vec3& p=v[i];
		double tr = std::clamp(p.x,0.0,0.999);
		double tg = std::clamp(p.y,0.0,0.999);
		double tb = std::clamp(p.z,0.0,0.999);
		int r = static_cast<int>(tr*255.999);
		int g = static_cast<int>(tg*255.999);
		int b = static_cast<int>(tb*255.999);
		file<<r<<" "<<g<<" "<<b<<"\n";
	};
	return true;
	
};
