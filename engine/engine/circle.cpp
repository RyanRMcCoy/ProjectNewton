#include "circle.h"
#include "rectangle.h"
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

bool circle::intersect(circle o)
{
	if ((getPos() - o.getPos()).magnitude() <= getRadius() + o.getRadius())
		return true;
	return false;
}

bool circle::intersect(rectangle o)
{
	
}