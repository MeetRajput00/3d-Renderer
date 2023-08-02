#pragma once
#ifndef HITTABLE_H
#define HITTABLE_H

#include"ray.h"

struct hit_record {
	point3 p;
	vec3 normal;
	double t;
};

class Hittable {
public:
	virtual bool hit(const Ray& r, double t_max, double t_min, hit_record& rec) const = 0;
};


#endif // !HITTABLE_H
