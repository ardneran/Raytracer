//
//  Ray.cpp
//  Raia
//
//  Created by Narendra Umate on 1/9/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Ray.h"

Ray::Ray()
{
	origin.zero();
	direction.zero();
}

Ray::Ray(const Vec3& origin, const Vec3& direction)
:	origin(origin),
	direction(direction)
{ }

Ray::Ray(const Ray& rhs)
{
	*this = rhs;
}

void Ray::normalize()
{
	direction.normalize();
}

Vec3 Ray::pointAtParameter(const float& t) const
{
	return (origin + (direction * static_cast<float>(t)));
}
