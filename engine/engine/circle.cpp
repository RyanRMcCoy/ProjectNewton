#include "circle.h"
#include "rectangle.h"
#include "pch.h"

circle::circle() : physicalObject()
{
	radius = 0;

	density = 0;
	updateMass();

	mu = 0;
}

circle::circle(float rad) : physicalObject()
{
	radius = rad;

	density = 1;
	updateMass();

	mu = 0;
}

circle::circle(float rad, vector2 pos) : physicalObject()
{
	setPosition(pos.getX(), pos.getY());
	radius = rad;

	density = 1;
	updateMass();

	mu = 0;
}

circle::circle(float rad, vector2 pos, float d) : physicalObject()
{
	setPosition(pos.getX(), pos.getY());
	radius = rad;

	density = d;
	updateMass();

	mu = 0;
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

float circle::getFriction()
{
	return mu;
}

void circle::setFriction(float m)
{
	mu = m;
}
