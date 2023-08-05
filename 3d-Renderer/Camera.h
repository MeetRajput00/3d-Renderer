#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include"Common_Constants.h"

class Camera {
public:
	Camera() {
		auto viewport_height = 2.0;
		auto viewport_width = viewport_height;
		auto focal_length = 1.0;

		origin = Point3(0, 0, 0);
		horizontal = Vec3(viewport_width, 0, 0);
		vertical = Vec3(0, viewport_height, 0);
		focal = Vec3(0, 0, focal_length);
		lower_left_corner = origin - (horizontal / 2.0) - (vertical / 2.0) - focal;
	}
	Ray get_ray(double u, double v) {
		return Ray(origin, lower_left_corner + u * horizontal + v * vertical);
	}
public:
	Point3 origin;
	Vec3 horizontal;
	Vec3 vertical;
	Point3 lower_left_corner;
	Vec3 focal;
};
#endif CAMERA_H