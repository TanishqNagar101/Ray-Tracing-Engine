#ifndef VECTOR3_H
#define VECTOR3_H
#include <cmath>
#include <iosfwd>
constexpr double EPS=1e-8;

struct vec3{
	double x,y,z;
	vec3();
	vec3(double x_,double y_,double z_);
	double length() const;
	double length_squared() const;
	bool near_zero() const;
	vec3 operator-() const;
};
vec3 operator+(const vec3&, const vec3&);
vec3 operator*(const vec3&, const vec3&);
vec3 operator/(const vec3&, const double);
vec3 operator-(const vec3&, const vec3&);

double dot(const vec3&, const vec3&);
vec3 cross(const vec3&, const vec3&);

vec3& operator+=(vec3&, const vec3&);
vec3& operator-=(vec3&, const vec3&);
vec3& operator*=(const vec3&, const vec3&);

vec3 operator*(const vec3&, double);
vec3 normalize(const vec3&);
vec3 operator*(double, const vec3&);

vec3& operator/=(const vec3&, double);

std::ostream& operator<<(std::ostream&, const vec3&);
//vec3 operator(const vec3&, const vec3&);
//vec3 operator(const vec3&, const vec3&);
#endif
