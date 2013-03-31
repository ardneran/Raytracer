//
//  Vector.h
//  Camaleao
//
//  Created by Narendra Umate on 10/4/12.
//  Copyright (c) 2012 Narendra Umate. All rights reserved.
//

#ifndef __Camaleao__Vector__
#define __Camaleao__Vector__

#include "Matrix.h"

class Mat3;
class Mat4;

//  Vec1

class Vec1
{
public:
	union
	{
		float x;
		float data[1];
	};
	
	Vec1(void);
	Vec1(const float &x);
	
	void	set(const float &x);
	void	zero(void);
	Vec1	abs(void) const;
	float   sqr(void) const;
	float   norm(void) const;
	Vec1	normal(void) const;
	void	normalize(void);

	float   operator[](const int index) const;
	float&  operator[](const int index);
	Vec1	operator-() const;
	float   operator*(const Vec1 &a) const;
	Vec1	operator*(const float &a) const;
	Vec1	operator/(const float &a) const;
	Vec1	operator+(const Vec1 &a) const;
	Vec1	operator-(const Vec1 &a) const;
	void	operator+=(const Vec1 &a);
	void	operator-=(const Vec1 &a);
	void	operator/=(const Vec1 &a);
	void	operator/=(const float &a);
	void	operator*=(const float &a);
	bool	operator==(const Vec1 &a) const;
	bool	operator!=(const Vec1 &a) const;

	float	minComponent() const;
	float	maxComponent() const;
	float	minAbsComponent() const;
	float	maxAbsComponent() const;
	int		indexMinComponent() const;
	int		indexMaxComponent() const;
	int		indexMinAbsComponent() const;
	int		indexMaxAbsComponent() const;

	virtual operator float() {return x;}
};

//  Vec2

class Vec2
{
public:
	union
	{
		struct
		{
			union
			{
				float x;// s, u;
			};
		
			union
			{
				float y;// t, v;
			};
		};
		float data[2];
	};
	
	Vec2(void);
	Vec2(const float &x, const float &y);
	
	void	set(const float &x, const float &y);
	void	zero(void);
	Vec2	abs(void) const;
	float   sqr(void) const;
	float   norm(void) const;
	Vec2	normal(void) const;
	void	normalize(void);

	float   operator[](const int index) const;
	float&  operator[](const int index);
	Vec2	operator-() const;
	float   operator*(const Vec2 &a) const;
	Vec2	operator*(const float &a) const;
	Vec2	operator/(const float &a) const;
	Vec2	operator+(const Vec2 &a) const;
	Vec2	operator-(const Vec2 &a) const;
	void	operator+=(const Vec2 &a);
	void	operator-=(const Vec2 &a);
	void	operator/=(const Vec2 &a);
	void	operator/=(const float &a);
	void	operator*=(const float &a);
	bool	operator==(const Vec2 &a) const;
	bool	operator!=(const Vec2 &a) const;
	//TODO Fix these
	float	minComponent() const;
	float	maxComponent() const;
	float	minAbsComponent() const;
	float	maxAbsComponent() const;
	int		indexMinComponent() const;
	int		indexMaxComponent() const;
	int		indexMinAbsComponent() const;
	int		indexMaxAbsComponent() const;
};

//  Vec3

class Vec3
{
public:
	union
	{
		struct
		{
			union
			{
				float x;// u;
			};
	
			union
			{
				float y;// v;
			};
	
			union
			{
				float z;// w;
			};
		};
		float data[3];
	};
	
	Vec3(void);
	Vec3(const float &x, const float &y, const float &z);

	void	set(const float &x, const float &y, const float &z);
	void	zero(void);
	Vec3	abs(void) const;
	float   sqr(void) const;
	float   norm(void) const;
	Vec3	normal(void) const;
	void	normalize(void);
	
	float   operator[](const int index) const;
	float&  operator[](const int index);
	Vec3	operator-() const;
	float   operator*(const Vec3 &a) const;
	Vec3	operator*(const float &a) const;
	Vec3	operator/(const float &a) const;
	Vec3	operator+(const Vec3 &a) const;
	Vec3	operator-(const Vec3 &a) const;
	void	operator+=(const Vec3 &a);
	void	operator-=(const Vec3 &a);
	void	operator/=(const Vec3 &a);
	void	operator/=(const float &a);
	void	operator*=(const float &a);
	bool	operator==(const Vec3 &a) const;
	bool	operator!=(const Vec3 &a) const;

	float	minComponent() const;
	float	maxComponent() const;
	float	minAbsComponent() const;
	float	maxAbsComponent() const;
	int		indexMinComponent() const;
	int		indexMaxComponent() const;
	int		indexMinAbsComponent() const;
	int		indexMaxAbsComponent() const;

	Vec3	operator*(const Mat3 &m) const;
};

//  Vec4

class Vec4
{
public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float data[4];
	};

	Vec4(void);
	Vec4(const float &x, const float &y, const float &z, const float &w);
	
	void	set(const float &x, const float &y, const float &z, const float &w);
	void	zero(void);
	Vec4	abs(void) const;
	float   sqr(void) const;
	float   norm(void) const;
	Vec4	normal(void) const;
	void	normalize(void);
	Vec3	project(void);
	
	float   operator[](const int index) const;
	float&  operator[](const int index);
	Vec4	operator-() const;
	float   operator*(const Vec4 &a) const;
	Vec4	operator*(const float &a) const;
	Vec4	operator/(const float &a) const;
	Vec4	operator+(const Vec4 &a) const;
	Vec4	operator-(const Vec4 &a) const;
	void	operator+=(const Vec4 &a);
	void	operator-=(const Vec4 &a);
	void	operator/=(const Vec4 &a);
	void	operator/=(const float &a);
	void	operator*=(const float &a);
	bool	operator==(const Vec4 &a) const;
	bool	operator!=(const Vec4 &a) const;
	//TODO Fix these
	float	minComponent() const;
	float	maxComponent() const;
	float	minAbsComponent() const;
	float	maxAbsComponent() const;
	int		indexMinComponent() const;
	int		indexMaxComponent() const;
	int		indexMinAbsComponent() const;
	int		indexMaxAbsComponent() const;
		
	Vec4	operator*(const Mat4 &m) const;
};

//  Functions

Vec4 freeVector(const Vec3 &v);
Vec4 pointVector(const Vec3 &v);

Vec1 min(const Vec1 &u, const Vec1 &v);
Vec2 min(const Vec2 &u, const Vec2 &v);
Vec3 min(const Vec3 &u, const Vec3 &v);
Vec4 min(const Vec4 &u, const Vec4 &v);

Vec1 max(const Vec1 &u, const Vec1 &v);
Vec2 max(const Vec2 &u, const Vec2 &v);
Vec3 max(const Vec3 &u, const Vec3 &v);
Vec4 max(const Vec4 &u, const Vec4 &v);

float dot(const Vec1 &u, const Vec1 &v);
float dot(const Vec2 &u, const Vec2 &v);
float dot(const Vec3 &u, const Vec3 &v);
float dot(const Vec4 &u, const Vec4 &v);

Vec3  cross(const Vec3 &l, const Vec3 &r);

float dist(const Vec1 &u, const Vec1 &v);
float dist(const Vec2 &u, const Vec2 &v);
float dist(const Vec3 &u, const Vec3 &v);
float dist(const Vec4 &u, const Vec4 &v);

float distsqr(const Vec1 &u, const Vec1 &v);
float distsqr(const Vec2 &u, const Vec2 &v);
float distsqr(const Vec3 &u, const Vec3 &v);
float distsqr(const Vec4 &u, const Vec4 &v);

Vec1 lerp(const Vec1 &a, const Vec1 &b, const float &t);
Vec2 lerp(const Vec2 &a, const Vec2 &b, const float &t);
Vec3 lerp(const Vec3 &a, const Vec3 &b, const float &t);
Vec4 lerp(const Vec4 &a, const Vec4 &b, const float &t);

Vec1 reflect(const Vec1 &incident, const Vec1 &normal);
Vec2 reflect(const Vec2 &incident, const Vec2 &normal);
Vec3 reflect(const Vec3 &incident, const Vec3 &normal);
Vec4 reflect(const Vec4 &incident, const Vec4 &normal);

Vec3  vectorTripleProduct(const Vec3 &u, const Vec3 &v, const Vec3 &w);
float scalarTripleProduct(const Vec3 &u, const Vec3 &v, const Vec3 &w);

#endif
