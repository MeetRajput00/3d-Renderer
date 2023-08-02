#include<iostream>
#include"color.h"
#include"vec3.h"
#include"ray.h"
#include"Sphere.h"
double hit_sphere(const point3& center, double radius, const Ray& r);
color ray_color(const Ray& r) {
	auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
	if (t > 0.0) {
		vec3 N = dot_product(r.at(t) - vec3(0, 0, -1));
		return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
	}
	vec3 unit_direction = dot_product(r.direction());
	t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}
double hit_sphere(const point3& center, double radius, const Ray& r) {
	vec3 oc = r.origin() - center;
	auto a = r.direction().length_squared();
	auto b = dot(oc, r.direction());
	auto c = oc.length_squared() - radius * radius;
	auto discriminant = b * b - a * c;
	if (discriminant < 0)
		return -1.0;
	return (-b - sqrt(discriminant)) / a;
}
int main() {
	//image 
	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 256;
	const int image_height = image_width;

	//camera

	auto viewport_height = 2.0;
	auto viewport_width = viewport_height;
	auto focal_length = 1.0;

	auto origin = point3(0, 0, 0);
	auto horizontal = vec3(viewport_width, 0, 0);
	auto vertical = vec3(0, viewport_height, 0);
	auto focal = vec3(0, 0, focal_length);
	vec3 lower_left_corner = origin-(horizontal / 2.0) -(vertical / 2.0) - focal;
	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
	//display image
	for (int j = image_height - 1; j >= 0; j--) {
		std::cerr << "Lines remaining " << j << '\n';
		for (int i = 0; i < image_width; i++) {
			auto u = double(i) / (image_width - 1);
			auto v = double(j) / (image_height - 1);
			Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			color pixel_color = ray_color(r);
			write_line(std::cout, pixel_color);
		}
	}
	std::cerr << "Render finished!"<<std::flush;
	return 0;
}