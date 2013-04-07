//
//  ONB.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/30/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "ONB.h"

ONB::ONB()
{ }

ONB::ONB(const Vec3 &a, const Vec3 &b, const Vec3 &c)
{ }

ONB::~ONB()
{ }

void ONB::set(const Vec3 &a, const Vec3 &b, const Vec3 &c)
{
	u = a;
	v = b;
	w = c;
}

void ONB::initFromU(const Vec3& u)
{
	Vec3 n(1.0f, 0.0f, 0.0f);
	Vec3 m(0.0f, 1.0f, 0.0f);

	this->u = u.normal();
	this->v = cross(this->u, n);
	if (this->v.sqr() < ONB_EPSILON)
	{
		this->v = cross(this->u, m);
	}
	this->w = cross(this->u, this->v);
}

void ONB::initFromV(const Vec3& v)
{
	Vec3 n(1.0f, 0.0f, 0.0f);
	Vec3 m(0.0f, 1.0f, 0.0f);

	this->v = v.normal();
	this->u = cross(this->v, n);
	if (this->u.sqr() < ONB_EPSILON)
	{
		this->u = cross(this->v, m);
	}
	this->w = cross(this->u, this->v);
}

void ONB::initFromW(const Vec3& w)
{
	Vec3 n(1.0f, 0.0f, 0.0f);
	Vec3 m(0.0f, 1.0f, 0.0f);

	this->w = w.normal();
	this->u = cross(this->w, n);
	if (this->u.sqr() < ONB_EPSILON)
	{
		this->u = cross(this->w, m);
	}
	this->v = cross(this->w, this->u);
}

void ONB::initFromUV(const Vec3& u, const Vec3& v)
{
	this->u = u.normal();
	this->w = cross(this->u, this->v).normal();
	this->v = cross(this->w, this->u).normal();
}

void ONB::initFromVU(const Vec3& v, const Vec3& u)
{
	this->v = v.normal();
	this->w = cross(this->u, this->v).normal();
	this->u = cross(this->v, this->w).normal();
}

void ONB::initFromUW(const Vec3& u, const Vec3& w)
{
	this->u = u.normal();
	this->v = cross(this->w, this->u).normal();
	this->v = cross(this->u, this->v).normal();
}

void ONB::initFromWU(const Vec3& w, const Vec3& u)
{
	this->w = w.normal();
	this->v = cross(w, u).normal();
	this->u = cross(v, w).normal();
}

void ONB::initFromVW(const Vec3& v, const Vec3& w)
{
	this->v = v.normal();
	this->u = cross(v, w).normal();
	this->w = cross(u, v).normal();
}

void ONB::initFromWV(const Vec3& w, const Vec3& v)
{
	this->w = w.normal();
	this->u = cross(v, w).normal();
	this->v = cross(w, u).normal();
}

bool ONB::operator==(const ONB &a) const
{
	return (u == a.u && v == a.v && w == a.w);
}

bool ONB::operator!=(const ONB &a) const
{
	return (u != a.u && v != a.v && w != a.w);
}
