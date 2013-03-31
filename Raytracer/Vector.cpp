//
//  Vector.cpp
//  Camaleao
//
//  Created by Narendra Umate on 10/4/12.
//  Copyright (c) 2012 Narendra Umate. All rights reserved.
//

#include "Vector.h"

//  Vec1

Vec1::Vec1(void)
:	x(0.0f)
{ }

Vec1::Vec1(const float &x)
:	x(x)
{ }

void Vec1::set(const float &x)
{
	this->x = x;
}

void Vec1::zero(void)
{
	x = 0.0f;
}

Vec1 Vec1::abs(void) const
{
	return max(*this, -*this);
}

float Vec1::sqr(void) const
{
	return dot(*this, *this);
}

float Vec1::norm(void) const
{
	return fabs(x);//return x > 0.0f ? x : -x;//return sqrtf(dot(*this, *this));
}

Vec1 Vec1::normal(void) const
{
	float magnitude = norm();
	return (magnitude > 1.0f) ? (*this / magnitude) : (*this);
}

void Vec1::normalize(void)
{
	float magnitude = norm();
	if (magnitude > 1.0f)
	{
		*this /= norm();
	}
}

float Vec1::operator[](const int index) const
{
	return (&x)[index];
}

float& Vec1::operator[](const int index)
{
	return (&x)[index];
}

Vec1 Vec1::operator-() const
{
	return Vec1(-x);
}

float Vec1::operator*(const Vec1 &a) const
{
	return x * a.x;
}

Vec1 Vec1::operator*(const float &a) const
{
	return Vec1(x * a);
}

Vec1 Vec1::operator/(const float &a) const
{
	return Vec1(x / a);
}

Vec1 Vec1::operator+(const Vec1 &a) const
{
	return Vec1(x + a.x);
}

Vec1 Vec1::operator-(const Vec1 &a) const
{
	return Vec1(x - a.x);
}

void Vec1::operator+=(const Vec1 &a)
{
	x += a.x;
}

void Vec1::operator-=(const Vec1 &a)
{
	x -= a.x;
}

void Vec1::operator/=(const Vec1 &a)
{
	x /= a.x;
}

void Vec1::operator/=(const float &a)
{
	x /= a;
}

void Vec1::operator*=(const float &a)
{
	x *= a;
}

bool Vec1::operator==(const Vec1 &a) const
{
	return (x == a.x);
}

bool Vec1::operator!=(const Vec1 &a) const
{
	return (x != a.x);
}

float Vec1::minComponent() const
{
	return x;
}

float Vec1::maxComponent() const
{
	return x;
}

float Vec1::minAbsComponent() const
{
	return fabs(x);
}

float Vec1::maxAbsComponent() const
{
	return fabs(x);
}

int	Vec1::indexMinComponent() const
{
	return 0;
}

int	Vec1::indexMaxComponent() const
{
	return 0;
}

int	Vec1::indexMinAbsComponent() const
{
	return 0;
}

int	Vec1::indexMaxAbsComponent() const
{
	return 0;
}

//  Vec2

Vec2::Vec2(void)
:	x(0.0f),
	y(0.0f)
{ }

Vec2::Vec2(const float &x, const float &y)
:	x(x),
	y(y)
{ }

void Vec2::set(const float &x, const float &y)
{
	this->x = x;
	this->y = y;
}

void Vec2::zero(void)
{
	x = y = 0.0f;
}

Vec2 Vec2::abs(void) const
{
	return max(*this, -*this);
}

float Vec2::sqr(void) const
{
	return dot(*this, *this);
}

float Vec2::norm(void) const
{
	return sqrtf(dot(*this, *this));
}

Vec2 Vec2::normal(void) const
{
	float magnitude = norm();
	return (magnitude > 1.0f) ? (*this / magnitude) : (*this);
}

void Vec2::normalize(void)
{
	float magnitude = norm();
	if (magnitude > 1.0f)
	{
		*this /= norm();
	}
}

float Vec2::operator[](const int index) const
{
	return (&x)[index];
}

float& Vec2::operator[](const int index)
{
	return (&x)[index];
}

Vec2 Vec2::operator-() const
{
	return Vec2(-x, -y);
}

float Vec2::operator*(const Vec2 &a) const
{
	return x * a.x + y * a.y;
}

Vec2 Vec2::operator*(const float &a) const
{
	return Vec2(x * a, y * a);
}

Vec2 Vec2::operator/(const float &a) const
{
	return Vec2(x / a, y / a);
}

Vec2 Vec2::operator+(const Vec2 &a) const
{
	return Vec2(x + a.x, y + a.y);
}

Vec2 Vec2::operator-(const Vec2 &a) const
{
	return Vec2(x - a.x, y - a.y);
}

void Vec2::operator+=(const Vec2 &a)
{
	x += a.x;
	y += a.y;
}

void Vec2::operator-=(const Vec2 &a)
{
	x -= a.x;
	y -= a.y;
}

void Vec2::operator/=(const Vec2 &a)
{
	x /= a.x;
	y /= a.y;
}

void Vec2::operator/=(const float &a)
{
	x /= a;
	y /= a;
}

void Vec2::operator*=(const float &a)
{
	x *= a;
	y *= a;
}

bool Vec2::operator==(const Vec2 &a) const
{
	return (x == a.x && y == a.y);
}

bool Vec2::operator!=(const Vec2 &a) const
{
	return (x != a.x || y != a.y);
}

float Vec2::minComponent() const
{
	return x;
}

float Vec2::maxComponent() const
{
	return x;
}

float Vec2::minAbsComponent() const
{
	return fabs(x);
}

float Vec2::maxAbsComponent() const
{
	return fabs(x);
}

int	Vec2::indexMinComponent() const
{
	return 0;
}

int	Vec2::indexMaxComponent() const
{
	return 0;
}

int	Vec2::indexMinAbsComponent() const
{
	return 0;
}

int	Vec2::indexMaxAbsComponent() const
{
	return 0;
}

//  Vec3

Vec3::Vec3(void)
:	x(0.0f),
	y(0.0f),
	z(0.0f)
{ }

Vec3::Vec3(const float &x, const float &y, const float &z)
:	x(x),
	y(y),
	z(z)
{ }

void Vec3::set(const float &x, const float &y, const float &z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vec3::zero(void)
{
	x = y = z = 0.0f;
}

Vec3 Vec3::abs(void) const
{
	return max(*this, -*this);
}

float Vec3::sqr(void) const
{
	return dot(*this, *this);
}

float Vec3::norm(void) const
{
	return sqrtf(dot(*this, *this));
}

Vec3 Vec3::normal(void) const
{
	float magnitude = norm();
	return (magnitude > 1.0f) ? (*this / magnitude) : (*this);
}

void Vec3::normalize(void)
{
	float magnitude = norm();
	if (magnitude > 1.0f)
	{
		*this /= norm();
	}
}

float Vec3::operator[](const int index) const
{
	return (&x)[index];
}

float& Vec3::operator[](const int index)
{
	return (&x)[index];
}

Vec3 Vec3::operator-() const
{
	return Vec3(-x, -y, -z);
}

float Vec3::operator*(const Vec3 &a) const
{
	return x * a.x + y * a.y + z * a.z;
}

Vec3 Vec3::operator*(const float &a) const
{
	return Vec3(x * a, y * a, z * a);
}

Vec3 Vec3::operator/(const float &a) const
{
	return Vec3(x / a, y / a, z / a);
}

Vec3 Vec3::operator+(const Vec3 &a) const
{
	return Vec3(x + a.x, y + a.y, z + a.z);
}

Vec3 Vec3::operator-(const Vec3 &a) const
{
	return Vec3(x - a.x, y - a.y, z - a.z);
}

void Vec3::operator+=(const Vec3 &a)
{
	x += a.x;
	y += a.y;
	z += a.z;
}

void Vec3::operator-=(const Vec3 &a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;
}

void Vec3::operator/=(const Vec3 &a)
{
	x /= a.x;
	y /= a.y;
	z /= a.z;
}

void Vec3::operator/=(const float &a)
{
	x /= a;
	y /= a;
	z /= a;
}

void Vec3::operator*=(const float &a)
{
	x *= a;
	y *= a;
	z *= a;
}

bool Vec3::operator==(const Vec3 &a) const
{
	return (x == a.x && y == a.y && z == a.z);
}

bool Vec3::operator!=(const Vec3 &a) const
{
	return (x != a.x || y != a.y || z != a.z);
}

Vec3 Vec3::operator*(const Mat3 &m) const
{
	return Vec3(x * m.d00 + y * m.d10 + z * m.d20,
				x * m.d01 + y * m.d11 + z * m.d21,
				x * m.d02 + y * m.d12 + z * m.d22);
}

float Vec3::minComponent() const
{
	return data[indexMinComponent()];
}

float Vec3::maxComponent() const
{
	return data[indexMaxComponent()];
}

float Vec3::minAbsComponent() const
{
	return data[indexMinAbsComponent()];
}

float Vec3::maxAbsComponent() const
{
	return data[indexMaxAbsComponent()];
}

int	Vec3::indexMinComponent() const
{
	return (data[0] < data[1] && data[0] < data[2]) ?
			0 : (data[1] < data[2] ?
			1 : 2);
}

int	Vec3::indexMaxComponent() const
{
	return (data[0] > data[1] && data[0] > data[2]) ?
			0 : (data[1] > data[2] ?
			1 : 2);
}

int	Vec3::indexMinAbsComponent() const
{
	if (fabs(data[0]) < fabs(data[1]) && fabs(data[0]) < fabs(data[2]))
		return 0;
	else if (fabs(data[1]) < fabs(data[2]))
		return 1;
	else
		return 2;
}

int	Vec3::indexMaxAbsComponent() const
{
	if (fabs(data[0]) > fabs(data[1]) && fabs(data[0]) > fabs(data[2]))
		return 0;
	else if (fabs(data[1]) > fabs(data[2]))
		return 1;
	else
		return 2;
}

//  Vec4

Vec4::Vec4(void)
:	x(0.0f),
	y(0.0f),
	z(0.0f),
	w(0.0f)
{ }

Vec4::Vec4(const float &x, const float &y, const float &z, const float &w)
:	x(x),
	y(y),
	z(z),
	w(w)
{ }

void Vec4::set(const float &x, const float &y, const float &z, const float &w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

void Vec4::zero(void)
{
	x = y = z = w = 0.0f;
}

Vec4 Vec4::abs(void) const
{
	return max(*this, -*this);
}

float Vec4::sqr(void) const
{
	return dot(*this, *this);
}

float Vec4::norm(void) const
{
	return sqrtf(dot(*this, *this));
}

Vec4 Vec4::normal(void) const
{
	float magnitude = norm();
	return (magnitude > 1.0f) ? (*this / magnitude) : (*this);
}

void Vec4::normalize(void)
{
	float magnitude = norm();
	if (magnitude > 1.0f)
	{
		*this /= norm();
	}
}

Vec3 Vec4::project(void)
{
	return Vec3(x, y, z);
}

float Vec4::operator[](const int index) const
{
	return (&x)[index];
}

float& Vec4::operator[](const int index)
{
	return (&x)[index];
}

Vec4 Vec4::operator-() const
{
	return Vec4(-x, -y, -z, -w);
}

float Vec4::operator*(const Vec4 &a) const
{
	return x * a.x + y * a.y + z * a.z + w * a.w;
}

Vec4 Vec4::operator*(const float &a) const
{
	return Vec4(x * a, y * a, z * a, w * a);
}

Vec4 Vec4::operator/(const float &a) const
{
	return Vec4(x / a, y / a, z / a, w / a);
}

Vec4 Vec4::operator+(const Vec4 &a) const
{
	return Vec4(x + a.x, y + a.y, z + a.z, w + a.w);
}

Vec4 Vec4::operator-(const Vec4 &a) const
{
	return Vec4(x - a.x, y - a.y, z - a.z, w - a.w);
}

void Vec4::operator+=(const Vec4 &a)
{
	x += a.x;
	y += a.y;
	z += a.z;
	w += a.w;
}

void Vec4::operator-=(const Vec4 &a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;
	w -= a.w;
}

void Vec4::operator/=(const Vec4 &a)
{
	x /= a.x;
	y /= a.y;
	z /= a.z;
	w /= a.w;
}

void Vec4::operator/=(const float &a)
{
	x /= a;
	y /= a;
	z /= a;
	w /= a;
}

void Vec4::operator*=(const float &a)
{
	x *= a;
	y *= a;
	z *= a;
	w *= a;
}

bool Vec4::operator==(const Vec4 &a) const
{
	return (x == a.x && y == a.y && z == a.z && w == a.w);
}

bool Vec4::operator!=(const Vec4 &a) const
{
	return (x != a.x || y != a.y || z != a.z || w != a.w);
}

Vec4 Vec4::operator*(const Mat4 &m) const
{
	return Vec4(x * m.d00 + y * m.d10 + z * m.d20 + w * m.d30,
				x * m.d01 + y * m.d11 + z * m.d21 + w * m.d31,
				x * m.d02 + y * m.d12 + z * m.d22 + w * m.d32,
				x * m.d03 + y * m.d13 + z * m.d23 + w * m.d33);
}

float Vec4::minComponent() const
{
	return x;
}

float Vec4::maxComponent() const
{
	return x;
}

float Vec4::minAbsComponent() const
{
	return fabs(x);
}

float Vec4::maxAbsComponent() const
{
	return fabs(x);
}

int	Vec4::indexMinComponent() const
{
	return 0;
}

int	Vec4::indexMaxComponent() const
{
	return 0;
}

int	Vec4::indexMinAbsComponent() const
{
	return 0;
}

int	Vec4::indexMaxAbsComponent() const
{
	return 0;
}

//  Functions

Vec4 freeVector(const Vec3 &v)
{
	return Vec4(v.x, v.y, v.z, 1.0f);
}

Vec4 pointVector(const Vec3 &v)
{
	return Vec4(v.x, v.y, v.z, 0.0f);
}

Vec1 min(const Vec1 &u, const Vec1 &v)
{
	return Vec1(min(u.x, v.x));
}

Vec2 min(const Vec2 &u, const Vec2 &v)
{
	return Vec2(min(u.x, v.x), min(u.y, v.y));
}

Vec3 min(const Vec3 &u, const Vec3 &v)
{
	return Vec3(min(u.x, v.x), min(u.y, v.y), min(u.z, v.z));
}

Vec4 min(const Vec4 &u, const Vec4 &v)
{
	return Vec4(min(u.x, v.x), min(u.y, v.y), min(u.z, v.z), min(u.w, v.w));
}

Vec1 max(const Vec1 &u, const Vec1 &v)
{
	return Vec1(max(u.x, v.x));
}

Vec2 max(const Vec2 &u, const Vec2 &v)
{
	return Vec2(max(u.x, v.x), max(u.y, v.y));
}

Vec3 max(const Vec3 &u, const Vec3 &v)
{
	return Vec3(max(u.x, v.x), max(u.y, v.y), max(u.z, v.z));
}

Vec4 max(const Vec4 &u, const Vec4 &v)
{
	return Vec4(max(u.x, v.x), max(u.y, v.y), max(u.z, v.z), max(u.w, v.w));
}

float dot(const Vec1 &u, const Vec1 &v)
{
	return u.x * v.x;
}

float dot(const Vec2 &u, const Vec2 &v)
{
	return u.x * v.x + u.y * v.y;
}

float dot(const Vec3 &u, const Vec3 &v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z;
}

float dot(const Vec4 &u, const Vec4 &v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w;
}

Vec3 cross(const Vec3 &l, const Vec3 &r)
{
	return Vec3(l.y * r.z - r.y * l.z,
				r.x * l.z - l.x * r.z,
				l.x * r.y - r.x * l.y);
}

float dist(const Vec1 &u, const Vec1 &v)
{
	return fabsf(u.x - v.x);
}

float dist(const Vec2 &u, const Vec2 &v)
{
	return sqrtf((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}

float dist(const Vec3 &u, const Vec3 &v)
{
	return sqrtf((u.x - v.x) * (u.x - v.x) +
				 (u.y - v.y) * (u.y - v.y) +
				 (u.z - v.z) * (u.z - v.z));
}
 
float dist(const Vec4 &u, const Vec4 &v)
{
	return sqrtf((u.x - v.x) * (u.x - v.x) +
				 (u.y - v.y) * (u.y - v.y) +
				 (u.z - v.z) * (u.z - v.z) +
				 (u.w - v.w) * (u.w - v.w));
}
 
float distsqr(const Vec1 &u, const Vec1 &v)
{
	return (u.x - v.x) * (u.x - v.x);
}
 
float distsqr(const Vec2 u, const Vec2 &v)
{
	return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}
 
float distsqr(const Vec3 &u, const Vec3 &v)
{
	return ((u.x - v.x) * (u.x - v.x) +
			(u.y - v.y) * (u.y - v.y) +
			(u.z - v.z) * (u.z - v.z));
}
 
float distsqr(const Vec4 &u, const Vec4 &v)
{
	return ((u.x - v.x) * (u.x - v.x) +
			(u.y - v.y) * (u.y - v.y) +
			(u.z - v.z) * (u.z - v.z) +
			(u.w - v.w) * (u.w - v.w));
}

Vec1 lerp(const Vec1 &a, const Vec1 &b, const float &t)
{
	return (a - b) * t + b;
}

Vec2 lerp(const Vec2 &a, const Vec2 &b, const float &t)
{
	return (a - b) * t + b;
}

Vec3 lerp(const Vec3 &a, const Vec3 &b, const float &t)
{
	return (a - b) * t + b;
}

Vec4 lerp(const Vec4 &a, const Vec4 &b, const float &t)
{
	return (a - b) * t + b;
}

Vec1 reflect(const Vec1 &incident, const Vec1 &normal)
{
	return incident - normal * 2.0f * dot(incident, normal);
}

Vec2 reflect(const Vec2 &incident, const Vec2 &normal)
{
	return incident - normal * 2.0f * dot(incident, normal);
}

Vec3 reflect(const Vec3 &incident, const Vec3 &normal)
{
	return incident - normal * 2.0f * dot(incident, normal);
}

Vec4 reflect(const Vec4 &incident, const Vec4 &normal)
{
	return incident - normal * 2.0f * dot(incident, normal);
}

Vec3  vectorTripleProduct(const Vec3 &u, const Vec3 &v, const Vec3 &w)
{
	//a x (b x c) = (a . c) b - (a . b) c
	return cross(u, cross(v, w));
}

float scalarTripleProduct(const Vec3 &u, const Vec3 &v, const Vec3 &w)
{
	//a . (b x c) = b . (c x a) = c . (a x b)
	return dot(u, cross(v, w));
}
