//
//  Sample.cpp
//  Raytracer
//
//  Created by Narendra Umate on 4/6/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Sample.h"

Random1::Random1(int n)
:	n(n)
{
	struct timeval tv;
	gettimeofday(&tv, nullptr);
	random = new Random(tv.tv_usec);
}

int Random1::generate(Vec1 *samples)
{
	for (int j = 0; j < n; j++)
	{
		samples[j].x = (*random)();
	}
	return n;
}

Jitter1::Jitter1(int n)
:	n(n)
{
	struct timeval tv;
	gettimeofday(&tv, nullptr);
	random = new Random(tv.tv_usec);
}

int Jitter1::generate(Vec1 *samples)
{
	for (int j = 0; j < n; j++)
	{
		samples[j].x = (j + (*random)()) / n;
	}
	return n;
}

Random2::Random2(int n)
:	n(n)
{
	struct timeval tv;
	gettimeofday(&tv, nullptr);
	random = new Random(tv.tv_usec);
}

int Random2::generate(Vec2 *samples)
{
	for (int j = 0; j < n; j++)
	{
		samples[j].x = (*random)();
		samples[j].y = (*random)();
	}
	return n;
}

Jitter2::Jitter2(int m, int n)
:	m(m), n(n)
{
	struct timeval tv;
	gettimeofday(&tv, nullptr);
	random = new Random(tv.tv_usec);
}

int Jitter2::generate(Vec2 *samples)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			samples[i * n + j].x = (i + (*random)()) / m;
			samples[i * n + j].y = (j + (*random)()) / n;
		}
	}
	return m * n;
}

Hammersley2::Hammersley2(int n)
:	n(n)
{
	struct timeval tv;
	gettimeofday(&tv, nullptr);
	random = new Random(tv.tv_usec);
}

int Hammersley2::generate(Vec2 *samples)
{
	float p = 0.0f;
	float u = 0.0f;
	float v = 0.0f;

	float offu = (*random)();
	float offv = (*random)();

	for (int k = 0; k < n; k++)
	{
		for (int kk = k; kk; p *= 0.5, kk >>= 1)
		{
			if (kk & 1)
			{
				u += p;	// kk mod 2 == 1
			}
		}

		v = ((float)k + 0.5) / (float)n;
		u += offu;
		v += offv;
		u -= int(u);
		v -= int(v);
		samples[k].x = u;
		samples[k].y = v;
	}

	return n;
}

void shuffle(Vec1* samples, const int& count)
{
	for (int i = count; i >= 0; i--)
	{
		int target = int(drand48() * (double)i);
		Vec1 temp = samples[i + 1];
		samples[i + 1] = samples[target];
		samples[target] = temp;
	}
}

void shuffle(Vec2* samples, const int& count)
{
	for (int i = count; i >= 0; i--)
	{
		int target = int(drand48() * (double)i);
		Vec2 temp = samples[i + 1];
		samples[i + 1] = samples[target];
		samples[target] = temp;
	}
}
