//
//  Triangle.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Triangle.h"

Triangle::Triangle(const Vec3& a, const Vec3& b, const Vec3& c,
				   const Color4f& color)
:	a(a),
	b(b),
	c(c),
	color(color),
	ab(b - a),
	bc(c - b),
	ca(a - c),
	normal(cross(b - a, c - a).normal())
{}

AABB Triangle::AABB() const
{
	return AABB();
}

bool Triangle::hit(const Ray& ray,
				 const float& tmin,
				 const float& tmax,
				 const float& time,
				 HitRecord& hitRecord) const
{
	//  o => origin of ray
	//  d => direction of ray
	//  p = o + t.d => equation of ray
	//
	//  p => point on plane of triangle
	//  a => any vertex of triangle
	//  (p - a).n = 0 => equation of plane
	//
	//  (o + t.d - a).n = 0
	//  o.n + t.d.n - a.n = 0
	//  t = (a - o).n / d.n
	//
	//  p = o + t.d
	//  (b - a)x(p - a).n >= 0 &
	//  (c - b)x(p - b).n >= 0 &
	//  (a - c)x(p - c).n >= 0

	float rdDotTn = dot(ray.direction, normal);
	if (rdDotTn != 0.0f)	// TODO Epsilon Check
	{
		float t = dot((a - ray.origin), normal) / rdDotTn;

		if (t >= tmin && t <= tmax)
		{
			Vec3 p = ray.pointAtParameter(t);

			if (dot(cross(ab, p - a), normal) >= 0.0f)
			{
				if (dot(cross(bc, p - b), normal) >= 0.0f)
				{
					if (dot(cross(ca, p - c), normal) >= 0.0f)
					{
						hitRecord = HitRecord(t, normal, color);
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Triangle::shadowHit(const Ray& ray,
					   const float& tmin,
					   const float& tmax,
					   const float& time) const
{
	//  o => origin of ray
	//  d => direction of ray
	//  p = o + t.d => equation of ray
	//
	//  p => point on plane of triangle
	//  a => any vertex of triangle
	//  (p - a).n = 0 => equation of plane
	//
	//  (o + t.d - a).n = 0
	//  o.n + t.d.n - a.n = 0
	//  t = (a - o).n / d.n
	//
	//  p = o + t.d
	//  (b - a)x(p - a).n >= 0 &
	//  (c - b)x(p - b).n >= 0 &
	//  (a - c)x(p - c).n >= 0

	float rdDotTn = dot(ray.direction, normal);
	if (rdDotTn != 0.0f)	// TODO Epsilon Check
	{
		float t = dot((a - ray.origin), normal) / rdDotTn;

		if (t >= tmin && t <= tmax)
		{
			Vec3 p = ray.pointAtParameter(t);

			if (dot(cross(ab, p - a), normal) >= 0.0f)
			{
				if (dot(cross(bc, p - b), normal) >= 0.0f)
				{
					if (dot(cross(ca, p - c), normal) >= 0.0f)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
