//
//  Sphere.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Sphere.h"

Sphere::Sphere(const Vec3& center, const float& radius, const Color4f& color)
:	center(center),
	radiusSquare(radius * radius),
	color(color)
{}

AABB Sphere::AABB() const
{
	return AABB();
}

bool Sphere::hit(const Ray& ray,
				 const float& tmin,
				 const float& tmax,
				 const float& time,
				 HitRecord& hitRecord) const
{
	//  Fast Ray Sphere Intersection - Jeff Hultquist
	//  Graphics Gems I - Andrew S. Glassner - Page 388
	Vec3 scSubtractRo = center - ray.origin;
	float scSubtractRoSquare = dot(scSubtractRo, scSubtractRo);
	float projection = dot(scSubtractRo, ray.direction);
	float discriminant = radiusSquare -
	(scSubtractRoSquare - (projection * projection));

	if (discriminant > 0.0f)
	{
		//	TODO Switch tmin tmax if required
		//tmin = projection - sqrt(discriminant);
		//tmax = projection + sqrt(discriminant);
		
		float discriminantSqrt = sqrtf(discriminant);
		
		float t = projection - discriminantSqrt;
		if (t < tmin)
		{
			t = projection + discriminantSqrt;
		}

		if (t >= tmin && t <= tmax)
		{
			// valid hit
			hitRecord = HitRecord(t,
								  (ray.direction * t - scSubtractRo).normal(),
								  color);
			return true;
		}
	}
	return false;
}

bool Sphere::shadowHit(const Ray& ray,
					   const float& tmin,
					   const float& tmax,
					   const float& time) const
{
	//  Fast Ray Sphere Intersection - Jeff Hultquist
	//  Graphics Gems I - Andrew S. Glassner - Page 388
	Vec3 scSubtractRo = center - ray.origin;
	float scSubtractRoSquare = dot(scSubtractRo, scSubtractRo);
	float projection = dot(scSubtractRo, ray.direction);
	float discriminant = radiusSquare -
	(scSubtractRoSquare - (projection * projection));

	if (discriminant > 0.0f)
	{
		//	TODO Switch tmin tmax if required
		//tmin = projection - sqrt(discriminant);
		//tmax = projection + sqrt(discriminant);

		float discriminantSqrt = sqrtf(discriminant);

		float t = projection - discriminantSqrt;
		if (t < tmin)
		{
			t = projection + discriminantSqrt;
		}

		if (t >= tmin && t <= tmax)
		{
			// valid hit
			return true;
		}
	}
	return false;
}
