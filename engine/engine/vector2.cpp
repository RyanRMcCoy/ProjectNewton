#include "pch.h"
#include "vector2.h"
#include <cmath>

using namespace std;

vector2::vector2() : x(0), y(0) {}
vector2::vector2(float xs, float ys) : x(xs), y(ys) {}

float vector2::getX()
{
	return x;
}

float vector2::getY()
{
	return y;
}

float vector2::magnitude()
{
	return sqrt((x * x) + (y * y));
}

float vector2::dot(vector2 v)
{
	return (x * v.getX() + y * v.getY());
}

vector2 vector2::unit()
{
	return vector2(x, y) / magnitude();
}

vector2 vector2::perpendicular()
{
	return vector2(abs(y), abs(x));
}

vector2 vector2::project(vector2 v)
{
	return v * (dot(v) / v.dot(v));
}

vector2 vector2::operator + (vector2 v)
{
	vector2 vNew(x + v.getX(), y + v.getY());
	return vNew;
}

vector2 vector2::operator - (vector2 v)
{
	vector2 vNew(x - v.getX(), y - v.getY());
	return vNew;
}

vector2 vector2::operator * (vector2 v)
{
	vector2 vNew(x * v.getX(), y * v.getY());
	return vNew;
}

vector2 vector2::operator * (float f)
{
	vector2 vNew(x * f, y * f);
	return vNew;
}

vector2 vector2::operator / (vector2 v)
{
	vector2 vNew(x / v.getX(), y / v.getY());
	return vNew;
}

vector2 vector2::operator / (float f)
{
	vector2 vNew(x / f, y / f);
	return vNew;
}

bool vector2::operator < (vector2 v)
{
	return magnitude() < v.magnitude();
}

bool vector2::operator <= (vector2 v)
{
	return *this < v || *this == v;
}

bool vector2::operator == (vector2 v)
{
	return x == v.x && y == v.y;
}

bool vector2::operator != (vector2 v)
{
	return x != v.x || y != v.y;
}

bool vector2::operator >= (vector2 v)
{
	return *this > v || *this == v;
}

bool vector2::operator > (vector2 v)
{
	return magnitude() > v.magnitude();
}