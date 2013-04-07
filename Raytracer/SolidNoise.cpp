//
//  SolidNoise.cpp
//  Raytracer
//
//  Created by Narendra Umate on 4/7/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "SolidNoise.h"

SolidNoise::SolidNoise()
{
	Random random;

	grad[0]  = Vec3( 1.0f, 1.0f, 0.0f);
	grad[1]  = Vec3(-1.0f, 1.0f, 0.0f);
	grad[2]  = Vec3( 1.0f,-1.0f, 0.0f);
	grad[3]  = Vec3(-1.0f,-1.0f, 0.0f);

	grad[4]  = Vec3( 1.0f, 0.0f, 1.0f);
	grad[5]  = Vec3(-1.0f, 0.0f, 1.0f);
	grad[6]  = Vec3( 1.0f, 0.0f,-1.0f);
	grad[7]  = Vec3(-1.0f, 0.0f,-1.0f);

	grad[8]  = Vec3( 0.0f, 1.0f, 1.0f);
	grad[9]	 = Vec3( 0.0f,-1.0f, 1.0f);
	grad[10] = Vec3( 0.0f, 1.0f,-1.0f);
	grad[11] = Vec3( 0.0f,-1.0f,-1.0f);

	grad[12] = Vec3( 1.0f, 1.0f, 0.0f);
	grad[13] = Vec3(-1.0f, 1.0f, 0.0f);
	grad[14] = Vec3( 0.0f,-1.0f, 1.0f);
	grad[15] = Vec3( 0.0f,-1.0f,-1.0f);

	for (int i = 0; i < 16; i++)
	{
		phi[i] = i;
	}

	// shuffle phi
	for (int i = 14; i >= 0; i--)
	{
		int target = int(random() * i);
		int temp = phi[i + 1];
		phi[i + 1] = phi[target];
		phi[target] = temp;
	}
}

float SolidNoise::noise(const Vec3& p) const
{
	Vec3 v;
	float sum = 0.0f;

	float fi = floorf(p.x);
	float fj = floorf(p.y);
	float fk = floorf(p.z);

	float fu = p.x - float(fi);
	float fv = p.y - float(fj);
	float fw = p.z - float(fk);

	v = Vec3(fu, fv, fw);
	sum += knot(fi, fj, fk, v);

	v = Vec3(fu - 1, fv, fw);
	sum += knot(fi + 1, fj, fk, v);

	v = Vec3(fu, fv - 1, fw);
	sum += knot(fi, fj + 1, fk, v);

	v = Vec3(fu, fv, fw - 1);
	sum += knot(fi, fj, fk - 1, v);

	v = Vec3(fu - 1, fv - 1, fw);
	sum += knot(fi + 1, fj + 1, fk, v);

	v = Vec3(fu - 1, fv, fw - 1);
	sum += knot(fi + 1, fj, fk + 1, v);

	v = Vec3(fu, fv - 1, fw - 1);
	sum += knot(fi, fj + 1, fk + 1, v);

	v = Vec3(fu - 1, fv - 1, fw - 1);
	sum += knot(fi + 1, fj + 1, fk + 1, v);

	return sum;
}

float SolidNoise::turbulence(const Vec3& p, const int& depth) const
{
	Vec3 ptemp(p);
	float weight = 1.0f;

	float sum = fabsf(noise(ptemp));

	for (int i = 1; i < depth; i++)
	{
		weight *= 2;
		ptemp = p * weight;
		sum += fabsf(noise(ptemp)) / weight;
	}
	return sum;
}

float SolidNoise::dturbulence(const Vec3& p, const int& depth,
							  const float& d) const
{
	Vec3 ptemp(p);
	float weight = 1.0f;

	float sum = fabsf(noise(ptemp)) / d;

	for (int i = 1; i < depth; i++)
	{
		weight *= d;
		ptemp = p * weight;
		sum += fabsf(noise(ptemp)) / d;
	}
	return sum;
}

float SolidNoise::omega(const float& t) const
{
	float tl = fabsf(t);
	return (tl < 1.0) ?
			(1 - 6*tl*tl*tl*tl*tl + 15*tl*tl*tl*tl - 10*tl*tl*tl) : 0.0f;
}

Vec3 SolidNoise::gamma(const int& i, const int& j, const int& k) const
{
	int idx;
	idx = phi[(int)fabs(k) % 16];
	idx = phi[(int)fabs(j + idx) % 16];
	idx = phi[(int)fabs(i + idx) % 16];
	return grad[idx];
}

int SolidNoise::intGamma(const int& i, const int& j) const
{
	int idx;
	idx = phi[(int)fabs(j) % 16];
	idx = phi[(int)fabs(i + idx) % 16];
	return idx;
}

float SolidNoise::knot(const int& i, const int& j, const int& k,
					   const Vec3& v) const
{
  return (dot(gamma(i, j, k), v) * omega(v.x) * omega(v.y) * omega(v.z));
}

Vec3 SolidNoise::vecKnot(const int& i, const int& j, const int& k,
						 const Vec3& v) const
{
	return (gamma(i, j, k) * omega(v.x) * omega(v.y) * omega(v.z));
}
