//
//  Sample.h
//  Raytracer
//
//  Created by Narendra Umate on 4/6/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Sample__
#define __Raytracer__Sample__

#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

#include "Random.h"
#include "Vector.h"

class Sample1
{
public:
	virtual int generate(float* samples) = 0;
};

class Random1 : public Sample1
{
public:
	Random1(int n);
	virtual int generate(Vec1* samples);

	int n;
	Random* random;
};

class Jitter1 : public Sample1
{
public:
	Jitter1(int n);
	virtual int generate(Vec1* samples);

	int n;
	Random* random;
};

class Sample2
{
public:
	virtual int generate(Vec2* samples) = 0;
};

class Random2 : public Sample2
{
public:
	Random2(int n);
	virtual int generate(Vec2* samples);

	int n;
	Random* random;
};

class Jitter2 : public Sample2
{
public:
	Jitter2(int m, int n);
	virtual int generate(Vec2* samples);

	int m, n;
	Random* random;
};

class Hammersley2 : public Sample2
{
public:
	Hammersley2(int n);
	virtual int generate(Vec2* samples);

	int n;
	Random* random;
};

void shuffle(Vec1* samples, const int& count);
void shuffle(Vec2* samples, const int& count);

/*
// 1D Sampling
//void random	(Vec1* samples, const int& count);
//void jitter	(Vec1* samples, const int& count);

// 2D Sampling
//void random			(Vec2* samples, const int& count);
//void jitter			(Vec2* samples, const int& count);// count perfect sq
void multiJitter		(Vec2* samples, const int& count);// count perfect sq
void nrooks				(Vec2* samples, const int& count);
void halton				(Vec2* samples, const int& count);
//void hammersley		(Vec2* samples, const int& count);

void boxFilter			(Vec2* samples, const int& count);
void tentFilter			(Vec2* samples, const int& count);
void cubicSplineFilter	(Vec2* samples, const int& count);
*/

#endif /* defined(__Raytracer__Sample__) */
