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
	aperture(other.aperture),
	lensRadius(other.lensRadius),
	left(other.left),
	right(other.right),
	bottom(other.bottom),
	top(other.top),
	distance(other.distance),
	lensType(other.lensType)
{ }

Camera::Camera(const Vec3& center, const Vec3& gaze, const Vec3& vup,
	   const float& aperture, const float& left, const float& right,
	   const float& bottom, const float& top, const float& distance,
	   const LensType& lensType)
:	center(center),
	aperture(aperture),
	lensRadius(aperture / 2.0f),
	left(left),
	right(right),
	bottom(bottom),
	top(top),
	distance(distance),
	lensType(lensType)
{
	uvw.initFromWV(-gaze, vup);

	corner	= center
			+ (uvw.u * left)
			+ (uvw.v * bottom)
			- (uvw.w * distance);

	across = uvw.u * (right - left);

	up = uvw.v * (top - bottom);
}

// a and b are pixel positions
// seedx and seedy are lens samples in square range (0, 1) ^ 2
Ray Camera::getRay(const float& a, const float& b,
		   const float& seedX, const float& seedY)
{
	float seedXLocal = seedX;
	float seedYLocal = seedY;
	
	switch (lensType)
	{
		case Square:
			break;
		case PolarDisc:
			fromUnitSquareToUnitPolarDisc(seedXLocal, seedYLocal);
			break;
		case ConcentricDisc:
			fromUnitSquareToUnitConcentricDiscDC(seedXLocal, seedYLocal);
		default:
			break;
	}

	// TODO ??
	
	// To go from pixel coordinates (x, y) to (a, b) we map
	// [-0.5, nx - 0.5] to [0, 1] and [-0.5, ny - 0.5] to [0, 1]
	
	// a = (x + 0.5) / nx
	// b = (y + 0.5) / ny
	// x = a * nx - 0.5
	// y = a * ny - 0.5

	//	Vec3 origin = center
	//				+ (uvw.u * 2.0f * (seedXLocal - 0.5f) * lensRadius)
	//				+ (uvw.v * 2.0f * (seedYLocal - 0.5f) * lensRadius);

	Vec3 origin = center
	+ (uvw.u * (seedXLocal - 0.5f) * aperture)
	+ (uvw.v * (seedYLocal - 0.5f) * aperture);

	// TODO ??

	Vec3 target = corner
				+ (across * a)
				+ (up * b);

	return Ray(origin, (target - origin).normal());
}

// Untested
void fromUnitSquareToUnitPolarDisc(float& x, float& y)
{
	float r = sqrtf(x);
	float phi = 2.0f * M_PI * y;

	x = r * cos(phi);
	y = r * sin(phi);
}

// Untested
void fromUnitPolarDiscToUnitSquare(float& x, float& y)
{
	float r = sqrtf(x * x + y * y);
	float phi = atanf(y / x);

	x = r * r;
	y = phi / 2.0f / M_PI;
}

// Peter Shirley, Ken Chiu
void fromUnitSquareToUnitConcentricDiscPSKC(float& x, float& y)
{
	// (a,b) is now on [-1,1]^2
	float a = 2.0f * x - 1.0f;
	float b = 2.0f * y - 1.0f;

	float r = 0.0f;
	float phi = 0.0f;

	if (a > -b)	// region 1 or 2
	{
		if (a > b)	// region 1, also |a| > |b|
		{
			r = a;
			phi = M_PI_4 * (b/a);
		}
		else		// region 2, also |b| > |a|
		{
			phi = M_PI_4 * (2 - (a/b));
		}
	}
	else	// region 3 or 4
	{
		if (a < b)	// region 3, also |a| >= |b|, a != 0
		{
			r = -a;
			phi = M_PI_4 * (4 + (b/a));
		}
		else		// region 4, |b| >= |a|, but a==0 and b==0 could occur
		{
			r = -b;
			if (b != 0)
			{
				phi = M_PI_4 * (6 - (a/b));
			}
			else
			{
				phi = 0;
			}
		}
	}

	x = r * cos(phi);
	y = r * sin(phi);
}

// Peter Shirley, Ken Chiu
void fromUnitConcentricDiscToUnitSquarePSKC(float& x, float& y)
{
	float r = sqrtf(x * x + y * y);
	float phi = atan2f(y, x);

	float a = 0.0f;
	float b = 0.0f;

	if (phi < -M_PI_4)	// in rage [-pi/4, 7pi/4]
	{
		phi += 2.0f * M_PI;
	}

	if (phi < M_PI_4)			// region 1
	{
		a = r;
		b = phi * a / M_PI_4;
	}
	else if (phi < 3 * M_PI_4)	// region 2
	{
		b = r;
		a = (M_PI_2 - phi) * b / M_PI_4;
	}
	else if (phi < 5 * M_PI_4)	// region 3
	{
		a = -r;
		b = (phi - M_PI) * a / M_PI_4;
	}
	else if (phi < 3 * M_PI_4)	// region 4
	{
		b = -r;
		a = (3 * M_PI_2 - phi) * b / M_PI_4;
	}

	x = (a + 1.0f) / 2.0f;
	y = (b + 1.0f) / 2.0f;
}

// Dave Cline
void fromUnitSquareToUnitConcentricDiscDC(float& x, float& y)
{
	// (a,b) is now on [-1,1]^2
	float a = 2.0f * x - 1.0f;
	float b = 2.0f * y - 1.0f;

	float r = 0.0f;
	float phi = 0.0f;

	if (a * a > b * b)	// use squares instead of absolute values
	{
		r = a;
		phi = (M_PI_4 * b / a);
	}
	else
	{
		r = b;
		phi = M_PI_2 + (M_PI_4 * a / b);	// Dave Cline
		//phi = M_PI_2 - (M_PI_4 * a / b);	// Franz fix for Hammersley Sequence
	}

	x = r * cos(phi);
	y = r * sin(phi);
}

// Dave Cline
void fromUnitConcentricDiscToUnitSquareDC(float& x, float& y)
{
	// TODO Complete this by reversing code above and meanwhile use PSKC
	
	fromUnitConcentricDiscToUnitSquarePSKC(x, y);
}

