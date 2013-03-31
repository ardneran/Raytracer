//
//  Camera.cpp
//  Raytracer
//
//  Created by Narendra Umate on 4/1/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Camera.h"

Camera::Camera()
{ }

Camera::Camera(const Camera& other)
:	center(other.center),
	corner(other.corner),
	across(other.across),
	up(other.up),
	uvw(other.uvw),
	lensRadius(other.lensRadius),
	left(other.left),
	right(other.right),
	bottom(other.bottom),
	top(other.top),
	distance(other.distance)
{ }

Camera::Camera(const Vec3& center, const Vec3& gaze, const Vec3& vup,
	   const float& aperture, const float& left, const float& right,
	   const float& bottom, const float& top, const float& distance)
:	center(center),
	lensRadius(aperture / 2.0f),
	left(left),
	right(right),
	bottom(bottom),
	top(top),
	distance(distance)
{
	uvw.initFromWV(-gaze, vup);

	corner	= center
			+ (uvw.u * left)
			+ (uvw.v * bottom)
			- (uvw.w * distance);

	across = uvw.u * (right - left);

	up = uvw.v * (top - bottom);
}

Ray Camera::getRay(const float& a, const float& b,
		   const float& xi1, const float& xi2)
{
	Vec3 origin = center
				+ (uvw.u * 2.0f * (xi1 - 0.5f) * lensRadius)
				+ (uvw.v * 2.0f * (xi2 - 0.5f) * lensRadius);

	Vec3 target = corner
				+ (across * a)
				+ (up * b);

	return Ray(origin, (target - origin).normal());
}
