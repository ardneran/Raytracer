//
//  Disc.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Disc.h"

Disc::Disc(const Vec3& center,
		   const Vec3& normal,
		   const float& radius,
		   const Color4f& color)
:	center(center),
	normal(normal.normal()),
	radiusSquare(radius * radius),
	color(color)
{}

AABB Disc::AABB() const
{
	return AABB();
}

bool Disc::hit(const Ray& ray,
				 const float& tmin,
				 const float& tmax,
				 const float& time,
				 HitRecord& hitRecord) const
{
	//  o => origin of ray
	//  d => direction of ray
	//  p = o + t.d => equation of ray
	//
	//  p => point on disc
	//  c => center of disc
	//  n => normal of disc
	//  r => radius of disc
	//  (p - c).n = 0 => equation of plane containing disc
	//
	//  (o + t.d - c).n = 0
	//  o.n + t.d.n - c.n = 0
	//  t = (c - o).n / d.n
	//
	//  p = o + t.d
	//  (p - c).(p - c) < r.r

	float rdMultiplyDn = dot(ray.direction, normal);
	
	if (rdMultiplyDn != 0.0f)	// TODO Epsilon
	{
		float t = dot((center - ray.origin), normal) / rdMultiplyDn;

		if (t >= tmin && t <= tmax)
		{
			Vec3 cp = ray.pointAtParameter(t) - center;

			if (dot(cp, cp) < radiusSquare)
			{
				hitRecord = HitRecord(t, normal, color);
				return true;
			}
		}
	}
	return false;
}

bool Disc::shadowHit(const Ray& ray,
					   const float& tmin,
					   const float& tmax,
					   const float& time) const
{
	//  o => origin of ray
	//  d => direction of ray
	//  p = o + t.d => equation of ray
	//
	//  p => point on disc
	//  c => center of disc
	//  n => normal of disc
	//  r => radius of disc
	//  (p - c).n = 0 => equation of plane containing disc
	//
	//  (o + t.d - c).n = 0
	//  o.n + t.d.n - c.n = 0
	//  t = (c - o).n / d.n
	//
	//  p = o + t.d
	//  (p - c).(p - c) < r.r

	float rdMultiplyDn = dot(ray.direction, normal);

	if (rdMultiplyDn != 0.0f)	// TODO Epsilon
	{
		float t = dot((center - ray.origin), normal) / rdMultiplyDn;

		if (t >= tmin && t <= tmax)
		{
			Vec3 cp = ray.pointAtParameter(t) - center;

			if (dot(cp, cp) < radiusSquare)
			{
				return true;
			}
		}
	}
	return false;
}
