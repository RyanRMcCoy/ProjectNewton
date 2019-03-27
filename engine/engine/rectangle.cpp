#include "pch.h"
#include "rectangle.h"
#include "polygon.h"

rectangle::rectangle() : polygon(4)
{
	sideLenX = 0;
	sideLenY = 0;
}

rectangle::rectangle(float lenX, float lenY) : polygon(4)
{
	sideLenX = lenX;
	sideLenY = lenY;

	float halfX = lenX / 2;
	float halfY = lenY / 2;
	vector2 vertices[4] = {vector2(-halfX, -halfY), vector2(halfX, -halfY), vector2(halfX, halfY), vector2(-halfX, halfY)};
	setVertices(vertices);
}

rectangle::rectangle(vector2 size) : polygon(4)
{
	sideLenX = size.getX();
	sideLenY = size.getY();

	float halfX = sideLenX / 2;
	float halfY = sideLenY / 2;
	vector2 vertices[4] = { vector2(-halfX, -halfY), vector2(halfX, -halfY), vector2(halfX, halfY), vector2(-halfX, halfY) };
	setVertices(vertices);
}

rectangle::rectangle(float lenX, float lenY, vector2 pos) : polygon(4)
{
	sideLenX = lenX;
	sideLenY = lenY;

	setPosition(pos);

	float halfX = lenX / 2;
	float halfY = lenY / 2;
	vector2 vertices[4] = {vector2(-halfX, -halfY), vector2(halfX, -halfY), vector2(halfX, halfY), vector2(-halfX, halfY)};
	setVertices(vertices);
}

rectangle::rectangle(vector2 size, vector2 pos)
{
	sideLenX = size.getX();
	sideLenY = size.getY();

	setPosition(pos);

	float halfX = sideLenX / 2;
	float halfY = sideLenY / 2;
	vector2 vertices[4] = { vector2(-halfX, -halfY), vector2(halfX, -halfY), vector2(halfX, halfY), vector2(-halfX, halfY) };
	setVertices(vertices);
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
	setPosition(vector2(len / 2, sideLenY / 2));
	sideLenX = len;
}

void rectangle::setSideY(float len)
{
	setPosition(vector2(sideLenX / 2, len / 2));
	sideLenY = len;
}

float rectangle::getArea()
{
	return sideLenX * sideLenY;
}
