#include<iostream>
#include"Common_Constants.h"
#include"color.h"
#include"Hittable_list.h"
#include"Sphere.h"
Color ray_color(const Ray& r, const Hittable_List& world) {
	Hit_Record rec;
	if (world.hit(r, infinity, 0, rec)) 
	{
		return 0.5 * (rec.normal + Color(1, 1, 1));
	}
	Vec3 unit_direction = dot_product(r.direction());
	auto t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}
int main() {
	Hittable_List world;
	world.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5));
	world.add(make_shared<Sphere>(Point3(0, -100.5, -1), 100));
	
	//image 
	const int image_width = 256;
	const int image_height = image_width;

	//camera

	auto viewport_height = 2.0;
	auto viewport_width = viewport_height;
	auto focal_length = 1.0;

	auto origin = Point3(0, 0, 0);
	auto horizontal = Vec3(viewport_width, 0, 0);
	auto vertical = Vec3(0, viewport_height, 0);
	auto focal = Vec3(0, 0, focal_length);
	Vec3 lower_left_corner = origin-(horizontal / 2.0) -(vertical / 2.0) - focal;
	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
	//display image
	for (int j = image_height - 1; j >= 0; j--) {
		std::cerr << "Lines remaining " << j << '\n';
		for (int i = 0; i < image_width; i++) {
			auto u = double(i) / (image_width - 1);
			auto v = double(j) / (image_height - 1);
			Ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			Color pixel_color = ray_color(r,world);
			write_line(std::cout, pixel_color);
		}
	}
	std::cerr << "Render finished!"<<std::flush;
	return 0;
}