//
//  HitRecord.h
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__HitRecord__
#define __Raytracer__HitRecord__

#include "Color.h"
#include "Vector.h"

class HitRecord
{
public:
	float t;
	Vec3 normal;
	Color4f color;

	HitRecord();
	HitRecord(const float& t, const Vec3& normal, const Color4f& color);
	~HitRecord();
};

#endif /* defined(__Raytracer__HitRecord__) */
