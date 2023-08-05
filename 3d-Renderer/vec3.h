#ifndef VEC3_H
#define VEC3_H

#include<math.h>
#include<iostream>
#include"Common_Constants.h"
class Vec3 {
public:
	Vec3() :e{ 0,0,0 }{}
	Vec3(double e0, double e1, double e2) : e{ e0,e1,e2 } {}
	
	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

	Vec3& operator+=(const Vec3& v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;
	}

	Vec3& operator*=(const double t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}

	Vec3& operator/=(const double t) {
		return *this *= 1 / t;
	}
	double magnitude() const {
		return sqrt(length_squared());
	}
	double length_squared() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	inline static Vec3 random() {
		return Vec3(random_double(), random_double(), random_double());
	}
	inline static Vec3 random(double min, double max) {
		return Vec3(random_double(min, max), random_double(min, max), random_double(min, max));
	}

public:
	double e[3];
};

inline std::ostream& operator<<(std::ostream &out, const Vec3 h) {
	return out << h.e[0] << " " << h.e[1] << " " << h.e[2];
}
inline Vec3 operator+(const Vec3& i, const Vec3& j){
	return Vec3(i.e[0] + j.e[0], i.e[1] + j.e[1], i.e[2] + j.e[2]);
}
inline Vec3 operator-(const Vec3& i, const Vec3& j) {
	return Vec3(i.e[0] - j.e[0], i.e[1] - j.e[1], i.e[2] - j.e[2]);
}
inline Vec3 operator*(const Vec3& i, const Vec3& j) {
	return Vec3(i.e[0] * j.e[0], i.e[1] * j.e[1], i.e[2] * j.e[2]);
}
inline Vec3 operator*(double t,const Vec3& i) {
	return Vec3(t*i.e[0], t*i.e[1], t*i.e[2]);
}
inline Vec3 operator*(const Vec3& i, double t) {
	return t * i;
}
inline Vec3 operator/(const Vec3& i, double t) {
	return Vec3(i.x() / t, i.y() / t, i.z() / t);
}
inline double dot(const Vec3& i, const Vec3& j) {
	return (i.e[0] * j.e[0],
		+i.e[1] * j.e[1]
		+ i.e[2] * j.e[2]
		);
}
inline Vec3 cross(const Vec3& u, const Vec3& v) {
	return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}
inline Vec3 dot_product(const Vec3& i) {
	return i / i.magnitude();
}
Vec3 random_in_unit_sphere() {
	while (true) {
		auto p = Vec3::random(-1, 1);
		if (p.length_squared() > 1) continue;
		return p;
	}
}
Vec3 random_unit_vector() {
	return dot_product(random_in_unit_sphere());
}
//type aliases for 3d point and rgb color
using Point3 = Vec3;
using Color = Vec3;
#endif
