#include ".\header_files\vec3.h"
#include <ostream>
//Implementation of vec3.h or programming logic 

vec3::vec3():x(0),y(0),z(0) {}
vec3::vec3(double x,double y, double z):x(x),y(y),z(z) {}
	
//Length of a vector
double vec3::length() const{
	return std::sqrt(x*x+y*y+z*z);
}

//Length Squared
double vec3::length_squared() const{
	return x*x+y*y+z*z;
}
	
//Near-Zero check
bool vec3::near_zero() const{
	double e=EPS;
	return (std::abs(x)<e && std::abs(y)<e && std::abs(z)<e);
}

//Vector Sign flip operation
vec3 vec3::operator-() const{
	return vec3(-x,-y,-z);
}

std::ostream& operator<<(std::ostream& os, const vec3& v){
	return os<<"x:"<<v.x<<"\n"<<"y:"<<v.y<<"\n"<<"z:"<<v.z;

};
//Basic operation of Vec3 with Vec3

//Addition of vec3+vec3
vec3 operator+(const vec3& v1, const vec3& v2){
	return vec3(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
};
//Mul of vec3 x vec3
vec3 operator*(const vec3& v1, const vec3& v2){
	return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
};
//Sub of vec3 - vec3
vec3 operator-(const vec3& v1,const vec3& v2){
	return vec3(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
};
//Dot product of two vectors
double dot(const vec3& v1, const vec3& v2){
	return (v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z); 
};
//Dot product of two vectors
vec3 cross(const vec3& v1,const vec3& v2){
	return vec3(v1.y*v2.z-v1.z*v2.y,
		    v1.z*v2.x-v1.x*v2.z,
		    v1.x*v2.y-v1.y*v2.x);

};

//Single vector operation

//Normalize the vector
vec3 normalize(const vec3& v){
	if(v.near_zero()) return vec3(0.0,0.0,0.0);
	double mag = v.length();
	return vec3(v.x/mag,v.y/mag,v.z/mag);
};

// Operation of vector by constant

//division by const
vec3 operator/(const vec3& v1, const double d){
	return vec3(v1.x/d, v1.y/d, v1.z/d);
};
vec3 operator*(const vec3& v, const double m){
	return vec3(v.x*m,v.y*m,v.z*m);
};
vec3 operator*(const double m, const vec3& v){
	return vec3(v.x*m,v.y*m,v.z*m);
};


//Operator overloading between vectors
vec3& operator*=(vec3& v1, const vec3& v2){
	v1.x*=v2.x;
	v1.y*=v2.y;
	v1.z*=v2.z;
	return v1;
};
vec3& operator+=(vec3& v1,const vec3& v2){
	v1.x+=v2.x;
	v1.y+=v2.y;
	v1.z+=v2.z;
	return v1;
};
vec3& operator-=(vec3& v1, const vec3& v2){
	v1.x-=v2.x;
	v1.y-=v2.y;
	v1.z-=v2.z;
	return v1;
};
vec3& operator/=(vec3& v, const double d){
	v.x/=d;
	v.y/=d;
	v.z/=d;
	return v;
};

