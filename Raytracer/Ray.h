//
//  Ray.h
//  Raia
//
//  Created by Narendra Umate on 1/9/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raia__Ray__
#define __Raia__Ray__

#include "Vector.h"

class Ray
{
public:
	Ray();
	Ray(const Vec3& origin, const Vec3& direction);
	Ray(const Ray& rhs);
	
	void normalize();
	Vec3 pointAtParameter(const float& t) const;

	Vec3 origin;
	Vec3 direction;
};

#endif /* defined(__Raia__Ray__) */
