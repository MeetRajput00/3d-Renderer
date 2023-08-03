#ifndef COLOR_H
#define COLOR_H

#include"vec3.h"
#include<iostream>

void write_line(std::ostream& out, Color pixel_colors) {
	out<< static_cast<int>(255.999 * pixel_colors.e[0])<<" "<<static_cast<int>(255.999*pixel_colors.e[1])<<" "<<static_cast<int>(255.999*pixel_colors.e[2])<<'\n';
}


#endif COLOR_H