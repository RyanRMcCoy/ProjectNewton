#include "pch.h"
#include "rectangle.h"

rectangle::rectangle()
{
	sideLenX = 0;
	sideLenY = 0;

	setPosition(0, 0);

	density = 0;
	updateMass();
}


rectangle::rectangle(float lenX, float lenY)
{
	sideLenX = lenX;
	sideLenY = lenY;
	
	setPosition(lenX / 2, lenY / 2);

	density = 1;
	updateMass();
}

rectangle::rectangle(float lenX, float lenY, vector2 pos)
{
	sideLenX = lenX;
	sideLenY = lenY;

	setPosition(pos.getX(), pos.getY());

	density = 1;
	updateMass();
}

rectangle::rectangle(float lenX, float lenY, vector2 pos, float d)
{
	sideLenX = lenX;
	sideLenY = lenY;

	setPosition(pos.getX(), pos.getY());

	density = d;
	updateMass();
}

float rectangle::getSideX()
{
	return sideLenX;
}

float rectangle::getSideY()
{
	return sideLenY;
}

void rectangle::setSideX(float len)
{
	setPosition(len / 2, sideLenY);
	sideLenX = len;
}

void rectangle::setSideY(float len)
{
	setPosition(sideLenX, len / 2);
	sideLenY = len;
}

float rectangle::getArea()
{
	return sideLenX * sideLenY;
}

float rectangle::getMass()
{
	return mass;
}

float rectangle::setMass(float m)
{
	mass = m;
	updateDensity();
	return mass;
}

float rectangle::getDensity()
{
	return density;
}

float rectangle::setDensity(float d)
{
	density = d; 
	updateMass();
	return density;
}

void rectangle::updateMass()
{
	mass = density * getArea();
}

void rectangle::updateDensity()
{
	density = mass / getArea();
}