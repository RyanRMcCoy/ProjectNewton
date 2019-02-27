#include "physicalObject.h"
#include "vector2.h"
#include "pch.h"


physicalObject::physicalObject()
{
	vector2 position();
	vector2 velocity();
	vector2 acceleration();
}

physicalObject::physicalObject(vector2 pos)
{
	vector2 position = pos;
	vector2 velocity();
	vector2 acceleration();
}

vector2 physicalObject::getPos()
{
	return position;
}

float physicalObject::getXpos()
{
	return position.getX();
}

float physicalObject::getYpos()
{
	return position.getY();
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

void setPosition(vector2 position)
{
	*this.position = position;
}

void physicalObject::setVelocity(float x, float y)
{
	velocity = vector2(x, y);
}

void physicalObject::setAcceleration(float x, float y)
{
	acceleration = vector2(x, y);
}

