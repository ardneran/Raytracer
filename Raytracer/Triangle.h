//
//  Triangle.h
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Triangle__
#define __Raytracer__Triangle__

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(const Vec3& a, const Vec3& b, const Vec3& c, const Color4f& color);
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

	Vec3 a;
	Vec3 b;
	Vec3 c;
	Color4f color;

	Vec3 ab;
	Vec3 bc;
	Vec3 ca;
	Vec3 normal;
};

#endif /* defined(__Raytracer__Triangle__) */
