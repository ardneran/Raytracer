//
//  Camera.h
//  Raytracer
//
//  Created by Narendra Umate on 4/1/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Camera__
#define __Raytracer__Camera__

#include "ONB.h"
#include "Ray.h"
#include "Vector.h"

class Camera
{
	enum LensType
	{
		Square,
		PolarDisc,
		ConcentricDisc
	};

public:
	Camera();
	Camera(const Camera& other);
	Camera(const Vec3& center, const Vec3& gaze, const Vec3& vup,
		   const float& aperture, const float& left, const float& right,
		   const float& bottom, const float& top, const float& distance,
		   const LensType& lensType);
	Ray getRay(const float& a, const float& b,
			   const float& seedX, const float& seedY);

	Vec3 center, corner, across, up;
	ONB uvw;
	float aperture, lensRadius;
	float left, right, bottom, top, distance;
	LensType lensType;
};

void fromUnitSquareToUnitPolarDisc(float& x, float& y);
void fromUnitPolarDiscToUnitSquare(float& x, float& y);
void fromUnitSquareToUnitConcentricDiscPSKC(float& x, float& y);
void fromUnitConcentricDiscToUnitSquarePSKC(float& x, float& y);
void fromUnitSquareToUnitConcentricDiscDC(float& x, float& y);
void fromUnitConcentricDiscToUnitSquareDC(float& x, float& y);

#endif /* defined(__Raytracer__Camera__) */
