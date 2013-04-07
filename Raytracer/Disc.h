//
//  Disc.h
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Disc__
#define __Raytracer__Disc__

#include "Shape.h"

class Disc : public Shape
{
public:
	Disc(const Vec3& center,
		 const Vec3& normal,
		 const float& radius,
		 const Color4f& color);
	AABB AABB() const;
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
	Vec3 normal;
	float radiusSquare;
	Color4f color;
};

#endif /* defined(__Raytracer__Disc__) */
