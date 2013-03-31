//
//  OrthonormalBasis.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/30/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "OrthonormalBasis.h"

OrthonormalBasis::OrthonormalBasis()
{ }

OrthonormalBasis::OrthonormalBasis(const Vec3 &a, const Vec3 &b, const Vec3 &c)
{ }

OrthonormalBasis::~OrthonormalBasis()
{ }

void OrthonormalBasis::set(const Vec3 &a, const Vec3 &b, const Vec3 &c)
{
	u = a;
	v = b;
	w = c;
}

void OrthonormalBasis::initFromU(const Vec3& u)
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

void OrthonormalBasis::initFromV(const Vec3& v)
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

void OrthonormalBasis::initFromW(const Vec3& w)
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

void OrthonormalBasis::initFromUV(const Vec3& u, const Vec3& v)
{
	this->u = u.normal();
	this->w = cross(this->u, this->v).normal();
	this->v = cross(this->w, this->u).normal();
}

void OrthonormalBasis::initFromVU(const Vec3& v, const Vec3& u)
{
	this->v = v.normal();
	this->w = cross(this->u, this->v).normal();
	this->u = cross(this->v, this->w).normal();
}

void OrthonormalBasis::initFromUW(const Vec3& u, const Vec3& w)
{
	this->u = u.normal();
	this->v = cross(this->w, this->u).normal();
	this->v = cross(this->u, this->v).normal();
}

void OrthonormalBasis::initFromWU(const Vec3& w, const Vec3& u)
{
	this->w = w.normal();
	this->v = cross(w, u).normal();
	this->u = cross(v, w).normal();
}

void OrthonormalBasis::initFromVW(const Vec3& v, const Vec3& w)
{
	this->v = v.normal();
	this->u = cross(v, w).normal();
	this->w = cross(u, v).normal();
}

void OrthonormalBasis::initFromWV(const Vec3& w, const Vec3& v)
{
	this->w = w.normal();
	this->u = cross(v, w).normal();
	this->v = cross(w, u).normal();
}

bool OrthonormalBasis::operator==(const OrthonormalBasis &a) const
{
	return (u == a.u && v == a.v && w == a.w);
}

bool OrthonormalBasis::operator!=(const OrthonormalBasis &a) const
{
	return (u != a.u && v != a.v && w != a.w);
}
