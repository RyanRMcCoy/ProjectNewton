#include "physicalObject.h"
#include "vector2.h"
#include "pch.h"


physicalObject::physicalObject()
{
	position[0] = 0;
	position[1] = 0;
	vector2 velocity(0, 0);
	vector2 acceleration(0, 0);
}

physicalObject::physicalObject(float x, float y)
{
	position[0] = x;
	position[1] = y;
	vector2 velocity(0, 0);
	vector2 acceleration(0, 0);
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
	return velocity.getX();
}

float physicalObject::getYvel()
{
	return velocity.getY();
}

vector2 physicalObject::getVelVector()
{
	return velocity;
}

float physicalObject::getXacc()
{
	return acceleration.getX();
}

float physicalObject::getYacc()
{
	return acceleration.getY();
}

vector2 physicalObject::getAccVector()
{
	return acceleration;
}

float physicalObject::setXpos(float x)
{
	return position[0] = x;
}

float physicalObject::setYpos(float y)
{
	return position[1] = y;
}
void physicalObject::setVelocity(float x, float y)
{
	velocity = vector2(x, y);
}

void physicalObject::setAcceleration(float x, float y)
{
	acceleration = vector2(x, y);
}

