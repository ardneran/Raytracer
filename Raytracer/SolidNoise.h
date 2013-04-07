//
//  SolidNoise.h
//  Raytracer
//
//  Created by Narendra Umate on 4/7/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__SolidNoise__
#define __Raytracer__SolidNoise__

#include "Random.h"
#include "Vector.h"

class SolidNoise
{
public:
	SolidNoise();
	float noise(const Vec3& p) const;
	float turbulence(const Vec3& p, const int& depth) const;
	float dturbulence(const Vec3& p, const int& depth, const float& d) const;
	float omega(const float& t) const;
	Vec3 gamma(const int& i, const int& j, const int& k) const;
	int intGamma(const int& i, const int& j) const;
	float knot(const int& i, const int& j, const int& k, const Vec3& v) const;
	Vec3 vecKnot(const int& i, const int& j, const int& k, const Vec3& v) const;

	Vec3 grad[16];
	int phi[16];
};

#endif /* defined(__Raytracer__SolidNoise__) */
