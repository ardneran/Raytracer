//
//  ONB.h
//  Raytracer
//
//  Created by Narendra Umate on 3/30/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__ONB__
#define __Raytracer__ONB__

#include "Vector.h"

#define ONB_EPSILON 0.01f

class ONB
{
public:
	Vec3 u;
	Vec3 v;
	Vec3 w;

	ONB();
	ONB(const Vec3 &a, const Vec3 &b, const Vec3 &c);
	~ONB();

	void set(const Vec3 &a, const Vec3 &b, const Vec3 &c);

	void initFromU(const Vec3& u);
	void initFromV(const Vec3& v);
	void initFromW(const Vec3& w);

	void initFromUV(const Vec3& u, const Vec3& v);
	void initFromVU(const Vec3& v, const Vec3& u);

	void initFromUW(const Vec3& u, const Vec3& w);
	void initFromWU(const Vec3& w, const Vec3& u);

	void initFromVW(const Vec3& v, const Vec3& w);
	void initFromWV(const Vec3& w, const Vec3& v);

	bool operator==(const ONB &a) const;
	bool operator!=(const ONB &a) const;
};

#endif /* defined(__Raytracer__ONB__) */
