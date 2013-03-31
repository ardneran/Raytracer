//
//  Shape.h
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Shape__
#define __Raytracer__Shape__

#include "AxisAlignedBoundingBox.h"
#include "Color.h"
#include "HitRecord.h"
#include "Ray.h"
#include "Vector.h"

class Shape
{
public:
	virtual bool hit(const Ray& ray,
					 const float& tmin,
					 const float& tmax,
					 const float& time,
					 HitRecord& record) const = 0;
	virtual bool shadowHit(const Ray& ray,
						   const float& tmin,
						   const float& tmax,
						   const float& time) const = 0;
};

#endif /* defined(__Raytracer__Shape__) */
