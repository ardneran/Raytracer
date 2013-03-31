//
//  Plane.h
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Plane__
#define __Raytracer__Plane__

#include "Shape.h"

class Plane : public Shape
{
public:
	Plane(const Vec3& fixedPoint, const Vec3& normal, const Color4f& color);
	AxisAlignedBoundingBox axisAlignedBoundingBox() const;
	bool hit(const Ray& ray,
			 const float& tmin,
			 const float& tmax,
			 const float& time,
			 HitRecord& record) const;
	bool shadowHit(const Ray& ray,
				   const float& tmin,
				   const float& tmax,
				   const float& time) const;

	Vec3 fixedPoint;
	Vec3 normal;
	Color4f color;
};

#endif /* defined(__Raytracer__Plane__) */
