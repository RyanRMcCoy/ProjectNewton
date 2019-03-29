#include "circle.h"
#include "rectangle.h"
#include "pch.h"

circle::circle()
{
	radius = 0;

	density = 0;
	updateMass();
}

circle::circle(float rad)
{
	radius = rad;

	density = 1;
	updateMass();
}

circle::circle(float rad, vector2 pos)
{
	setPosition(pos.getX(), pos.getY());
	radius = rad;

	density = 1;
	updateMass();
}

circle::circle(float rad, vector2 pos, float d)
{
	setPosition(pos.getX(), pos.getY());
	radius = rad;

	density = d;
	updateMass();
}

float circle::getRadius()
{
	return radius;
}

void circle::setRadius(float rad)
{
	radius = rad;
}

float circle::getArea()
{
	return (float) 3.14 * pow(radius, 2);
}

float circle::getMass()
{
	return mass;
}

float circle::setMass(float m)
{
	mass = m;
	updateDensity();
	return mass;
}

float circle::getDensity()
{
	return density;
}

float circle::setDensity(float d)
{
	density = d;
	updateMass();
	return density;
}

void circle::updateMass()
{
	mass = density * getArea();
}

void circle::updateDensity()
{
	density = mass / getArea();
}
