//
//  Camera.h
//  Raytracer
//
//  Created by Narendra Umate on 4/1/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Camera__
#define __Raytracer__Camera__

#include "OrthonormalBasis.h"
#include "Ray.h"
#include "Vector.h"

class Camera
{
public:
	Camera();
	Camera(const Camera& other);
	Camera(const Vec3& center, const Vec3& gaze, const Vec3& vup,
		   const float& aperture, const float& left, const float& right,
		   const float& bottom, const float& top, const float& distance);
	Ray getRay(const float& a, const float& b,
			   const float& xi1, const float& xi2);

	Vec3 center, corner, across, up;
	OrthonormalBasis uvw;
	float lensRadius;
	float left, right, bottom, top, distance;
};

#endif /* defined(__Raytracer__Camera__) */
