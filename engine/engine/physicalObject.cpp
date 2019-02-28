#include "physicalObject.h"
#include "vector2.h"
#include "pch.h"


physicalObject::physicalObject()
{
	position = vector2();
	velocity = vector2();
	acceleration = vector2();
}

physicalObject::physicalObject(vector2 pos)
{
	position = pos;
	velocity = vector2();
	acceleration = vector2();
}

physicalObject::physicalObject(vector2 pos, vector2 vel)
{
	position = pos;
	velocity = vel;
	acceleration = vector2();
}

physicalObject::physicalObject(vector2 pos, vector2 vel, vector2 acc)
{
	position = pos;
	velocity = vel;
	acceleration = acc;
}

vector2 physicalObject::getPosition()
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

vector2 physicalObject::getVelocity()
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

vector2 physicalObject::getAcceleration()
{
	return acceleration;
}

//Tyler did you put this in? Do you need to be able to pass in a vector rather than 
//just values?
//void setPosition(vector2 pos)
//{
//	*this.position = position;
//}

void physicalObject::setPosition(float x, float y)
{
	position = vector2(x, y);
}

void physicalObject::setVelocity(float x, float y)
{
	velocity = vector2(x, y);
}

void physicalObject::setAcceleration(float x, float y)
{
	acceleration = vector2(x, y);
}

