#pragma once
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include"Hittable.h"
#include<memory>
#include<vector>

using std::vector;
using std::shared_ptr;
using std::make_shared;

class Hittable_List:public Hittable{
public:
	Hittable_List(){}
	Hittable_List(shared_ptr<Hittable> obj) { add(obj); }

	void clear() { objects.clear(); }
	void add(shared_ptr<Hittable> obj) { objects.push_back(obj); }

	virtual bool hit(const Ray& r, double t_max, double t_min, hit_record& rec) const override;
	
public:
	vector<shared_ptr<Hittable>> objects;
};
bool Hittable_List::hit(const Ray& r, double t_max, double t_min, hit_record& rec) const {
	hit_record temp_rec;//not sure about this--hit_record &temp_rec=rec; i think this should be here
	bool hit_anything = false;
	double closest_so_far = t_max;
	for(const auto& object:objects) {
		if (object->hit(r, t_max, closest_so_far, temp_rec)) {
			hit_anything=true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return hit_anything;
}
#endif // !HITTABLE_LIST_H
