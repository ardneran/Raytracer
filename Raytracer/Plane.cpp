//
//  Plane.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Plane.h"

Plane::Plane(const Vec3& fixedPoint, const Vec3& normal, const Color4f& color)
:	fixedPoint(fixedPoint),
	normal(normal.normal()),
	color(color)
{}

AABB Plane::AABB() const
{
	return AABB();
}

bool Plane::hit(const Ray& ray,
				const float& tmin,
				const float& tmax,
				const float& time,
				HitRecord& hitRecord) const
{
	//  o => origin of ray
	//  d => direction of ray
	//  p = o + t.d => equation of ray
	//
	//  p => point on plane
	//  f => fixed point on plane
	//  (p - f).n = 0 => equation of plane
	//
	//  (o + t.d - f).n = 0
	//  o.n + t.d.n - f.n = 0
	//  t = (f - o).n / d.n

	float rdMultiplyPn = dot(ray.direction, normal);
	if (rdMultiplyPn != 0.0f)	// TODO Epsilon
	{
		float t = dot((fixedPoint - ray.origin), normal) / rdMultiplyPn;

		if (t >= tmin && t <= tmax)
		{
			hitRecord = HitRecord(t, normal, color);
			return true;
		}
	}
	return false;
}

bool Plane::shadowHit(const Ray& ray,
					  const float& tmin,
					  const float& tmax,
					  const float& time) const
{
	//  o => origin of ray
	//  d => direction of ray
	//  p = o + t.d => equation of ray
	//
	//  p => point on plane
	//  f => fixed point on plane
	//  (p - f).n = 0 => equation of plane
	//
	//  (o + t.d - f).n = 0
	//  o.n + t.d.n - f.n = 0
	//  t = (f - o).n / d.n

	float rdMultiplyPn = dot(ray.direction, normal);
	if (rdMultiplyPn != 0.0f)	// TODO Epsilon
	{
		float t = dot((fixedPoint - ray.origin), normal) / rdMultiplyPn;

		if (t >= tmin && t <= tmax)
		{
			return true;
		}
	}
	return false;
}
