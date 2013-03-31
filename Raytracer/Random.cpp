//
//  Random.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Random.h"

Random::Random(unsigned long long seed)
:	seed(seed),
	mult(62089911ULL),
	llong_max(4294967295ULL),
	float_max(4294967295.0f)
{ }

float Random::operator()()
{
	seed = mult * seed;
	return float(seed % llong_max) / float_max;
}
