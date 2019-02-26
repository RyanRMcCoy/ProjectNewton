#include "pch.h"
#include "rectangle.h"

rectangle::rectangle()
{
	sideLenX = 0;
	sideLenY = 0;
}


rectangle::rectangle(float lenX, float lenY)
{
	sideLenX = lenX;
	sideLenY = lenY;
	
	setXpos(lenX / 2);
	setYpos(lenY / 2);
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
	setXpos(len / 2);
	return sideLenX = len;
}

float rectangle::setSideY(float len)
{
	setYpos(len / 2);
	return sideLenY = len;
}

//rectangle::~rectangle()
//{
//}
