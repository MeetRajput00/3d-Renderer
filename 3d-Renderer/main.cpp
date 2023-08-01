#include<iostream>
#include"color.h"
#include"vec3.h"
int main() {
	//image properties
	const int image_height = 256;
	const int image_width = 256;

	std::cout << "PPM image " << image_height << "x" << image_width << '\n';
	//display image
	for (int j = image_height - 1; j >= 0; j--) {
		std::cerr << "Lines remaining " << j << ' '<<std::flush;
		for (int i = 0; i < image_width; i++) {
			color pixel_colors(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
			write_line(std::cout, pixel_colors);
		}
	}
	std::cerr << "Render finished!";
	return 0;
}