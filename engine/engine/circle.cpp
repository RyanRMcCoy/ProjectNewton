#include "circle.h"
#include "pch.h"

circle::circle(float rad)
{
	physicalObject(0, 0);
	radius = rad;
}

float circle::getRadius()
{
	return radius;
}

float circle::setRadius(float rad)
{
	return radius = rad;
}
