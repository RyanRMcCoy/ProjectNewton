#include "pch.h"
#include "rectangle.h"

rectangle::rectangle()
{
	sideLenX = 0;
	sideLenY = 0;

	setPosition(0, 0);
}


rectangle::rectangle(float lenX, float lenY)
{
	sideLenX = lenX;
	sideLenY = lenY;
	
	setPosition(lenX / 2, lenY / 2);
}

rectangle::rectangle(float lenX, float lenY, vector2 pos)
{
	sideLenX = lenX;
	sideLenY = lenY;

	setPosition(pos.getX(), pos.getY());
}

float rectangle::getSideX()
{
	return sideLenX;
}

float rectangle::getSideY()
{
	return sideLenY;
}

float rectangle::setSideX(float len)
{
	setPosition(len / 2, sideLenY);
	return sideLenX = len;
}

float rectangle::setSideY(float len)
{
	setPosition(sideLenX, len / 2);
	return sideLenY = len;
}

//rectangle::~rectangle()
//{
//}
