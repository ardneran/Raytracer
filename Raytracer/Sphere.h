//
//  Sphere.h
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Sphere__
#define __Raytracer__Sphere__

#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere(const Vec3& center, const float& radius, const Color4f& color);
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

	Vec3 center;
	float radiusSquare;
	Color4f color;
};

#endif /* defined(__Raytracer__Sphere__) */
