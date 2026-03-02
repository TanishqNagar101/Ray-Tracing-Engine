#include "header_files\color.h"
#include "header_files\vec3.h"
#include <iostream>

using color=vec3;

void write_color(std::ostream& out,const color& pixel){
	double r = pixel.x;
	double g = pixel.y;
	double b = pixel.z;

	int rbyte = int(255.999*r);
	int gbyte = int(255.999*g);
	int bbyte = int(255.999*b);

	out<<rbyte<<' '<<gbyte<<' '<<bbyte<<'\n';

};
