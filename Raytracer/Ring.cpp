//
//  Ring.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Ring.h"

Ring::Ring(const Vec3& center,
		   const Vec3& normal,
		   const float& innerRadius,
		   const float& outerRadius,
		   const Color4f& color)
:	center(center),
	normal(normal.normal()),
	innerRadiusSquare(innerRadius * innerRadius),
	outerRadiusSquare(outerRadius * outerRadius),
	color(color)
{}

AxisAlignedBoundingBox Ring::axisAlignedBoundingBox() const
{
	return AxisAlignedBoundingBox();
}

bool Ring::hit(const Ray& ray,
			   const float& tmin,
			   const float& tmax,
			   const float& time,
			   HitRecord& hitRecord) const
{
	//  o => origin of ray
	//  d => direction of ray
	//  p = o + t.d => equation of ray
	//
	//  p => point on ring
	//  c => center of ring
	//  n => normal of ring
	//  ir => inner radius of ring
	//  or => outer radius of ring
	//  (p - c).n = 0 => equation of plane containing ring
	//
	//  (o + t.d - c).n = 0
	//  o.n + t.d.n - c.n = 0
	//  t = (c - o).n / d.n
	//
	//  p = o + t.d
	//  ir.ir < (p - c).(p - c) & (p - c).(p - c) < or.or

	float rdMultiplyRn = dot(ray.direction, normal);

	if (rdMultiplyRn != 0.0f)	// TODO Epsilon
	{
		float t = dot((center - ray.origin), normal) / rdMultiplyRn;
		
		if (t >= tmin && t <= tmax)
		{
			Vec3 cp = ray.pointAtParameter(t) - center;
			float cpSquare = dot(cp, cp);
			if (innerRadiusSquare < cpSquare && cpSquare < outerRadiusSquare)
			{
				hitRecord = HitRecord(t, normal, color);
				return true;
			}
		}
	}
	return false;
}

bool Ring::shadowHit(const Ray& ray,
					 const float& tmin,
					 const float& tmax,
					 const float& time) const
{
	//  o => origin of ray
	//  d => direction of ray
	//  p = o + t.d => equation of ray
	//
	//  p => point on ring
	//  c => center of ring
	//  n => normal of ring
	//  ir => inner radius of ring
	//  or => outer radius of ring
	//  (p - c).n = 0 => equation of plane containing ring
	//
	//  (o + t.d - c).n = 0
	//  o.n + t.d.n - c.n = 0
	//  t = (c - o).n / d.n
	//
	//  p = o + t.d
	//  ir.ir < (p - c).(p - c) & (p - c).(p - c) < or.or

	float rdMultiplyRn = dot(ray.direction, normal);

	if (rdMultiplyRn != 0.0f)	// TODO Epsilon
	{
		float t = dot((center - ray.origin), normal) / rdMultiplyRn;

		if (t >= tmin && t <= tmax)
		{
			Vec3 cp = ray.pointAtParameter(t) - center;
			float cpSquare = dot(cp, cp);
			if (innerRadiusSquare < cpSquare && cpSquare < outerRadiusSquare)
			{
				return true;
			}
		}
	}
	return false;
}
