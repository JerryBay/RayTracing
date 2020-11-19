#pragma once
#include "hittable.h"
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list:public hittable
{
public:
	hittable_list() {}
	hittable_list(shared_ptr<hittable> object) {}

	void add(shared_ptr<hittable> object)
	{
		objects.push_back(object);
	}

	void clear()
	{
		objects.clear();
	}

	 virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
private:
	std::vector<shared_ptr<hittable>> objects;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec)const
{
	hit_record temp_rec;
	bool hit_anything = false;
	double closet_so_far = t_max;

	for (const shared_ptr<hittable>& object:objects )
	{
		if (object->hit(r,t_min,closet_so_far, temp_rec))
		{
			hit_anything = true;
			closet_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}

	return hit_anything;
}