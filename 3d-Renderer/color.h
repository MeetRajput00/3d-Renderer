#ifndef COLOR_H
#define COLOR_H

#include"vec3.h"
#include<iostream>

void write_line(std::ostream& out, Color pixel_colors) {
	out<< static_cast<int>(255.999 * pixel_colors.e[0])<<" "<<static_cast<int>(255.999*pixel_colors.e[1])<<" "<<static_cast<int>(255.999*pixel_colors.e[2])<<'\n';
}
double linear_to_gamma(double linear_component) {
	return sqrt(linear_component);
}

void write_color(std::ostream& out, Color pixel_color, int samples_per_pixel) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	auto scale = 1.0 / samples_per_pixel;
	r *= scale;
	g *= scale;
	b *= scale;

	r = linear_to_gamma(r);
	g = linear_to_gamma(g);
	b = linear_to_gamma(b);

	out << static_cast<int>(256 * clamp(r,0.0,999.0) )<< " " << static_cast<int>(256 * clamp(g, 0.0, 999.0)) << " " << static_cast<int>(256 * clamp(b, 0.0, 999.0)) << '\n';
}

#endif COLOR_H