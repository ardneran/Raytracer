//
//  Random.h
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Random__
#define __Raytracer__Random__

class Random
{
public:
	Random(unsigned long long seed = 7564231ULL);
	float operator()();
	
	unsigned long long seed;
	unsigned long long mult;
	unsigned long long llong_max;
	float float_max;
};

#endif /* defined(__Raytracer__Random__) */
