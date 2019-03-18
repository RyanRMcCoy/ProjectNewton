#include "circle.h"
#include "rectangle.h"
#include "pch.h"

circle::circle()
{
	radius = 0;
}

circle::circle(float rad)
{
	radius = rad;
}

circle::circle(float rad, vector2 pos)
{
	setPosition(pos.getX(), pos.getY());
	radius = rad;
}

float circle::getRadius()
{
	return radius;
}

void circle::setRadius(float rad)
{
	radius = rad;
}