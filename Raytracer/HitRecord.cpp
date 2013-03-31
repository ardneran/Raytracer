//
//  HitRecord.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/31/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "HitRecord.h"

HitRecord::HitRecord()
{ }

HitRecord::HitRecord(const float& t, const Vec3& normal, const Color4f& color)
:	t(t),
	normal(normal),
	color(color)
{ }

HitRecord::~HitRecord()
{ }
