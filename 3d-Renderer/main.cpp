#include<iostream>

int main() {
	//image properties
	const int image_height = 256;
	const int image_width = 256;

	std::cout << "PPM image " << image_height << "x" << image_width << '\n';
	//display image
	for (int j = image_height - 1; j >= 0; j--) {
		std::cerr << "Lines remaining " << j << ' '<<std::flush;
		for (int i = 0; i < image_width; i++) {
			auto r = double(i) / (image_width - 1);
			auto g = double(j) / (image_height - 1);
			auto b = 0.25;

			int ir = static_cast<int>(255.999*r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << " " << ig << " " << ib << '\n';
		}
	}
	std::cerr << "Render finished!";
	return 0;
}