#include "physicalObject.h"
#include <array>

physicalObject::physicalObject(float x, float y)
{
	position[0] = x;
	position[1] = y;

	velocity[0] = 0;
	velocity[1] = 0;

	acceleration[0] = 0;
	acceleration[1] = 1;
}

float physicalObject::getXpos()
{
	return position[0];
}

float physicalObject::getYpos()
{
	return position[1];
}

float physicalObject::getXvel()
{
	return velocity[0];
}

float physicalObject::getYvel()
{
	return velocity[1];
}

float physicalObject::getXacc()
{
	return acceleration[0];
}

float physicalObject::getYacc()
{
	return acceleration[1];
}

float physicalObject::setXpos(float x)
{
	return position[0] = x;
}

float physicalObject::setYpos(float y)
{
	return position[1] = y;
}

float physicalObject::setXvel(float x)
{
	return velocity[0] = x;
}

float physicalObject::setYvel(float y)
{
	return velocity[1] = y;
}

float physicalObject::setXacc(float x)
{
	return acceleration[0] = x;
}

float physicalObject::setYacc(float y)
{
	return acceleration[1] = y;
}
