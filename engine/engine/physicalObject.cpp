#include "physicalObject.h"
#include "vector2.h"
#include "pch.h"


physicalObject::physicalObject()
{
	position = vector2();
	velocity = vector2();
	acceleration = vector2();

	colliding = false;

	mass = 1;
}

physicalObject::physicalObject(vector2 pos)
{
	position = pos;
	velocity = vector2();
	acceleration = vector2();

	colliding = false;
	
	mass = 1;
}

physicalObject::physicalObject(vector2 pos, vector2 vel)
{
	position = pos;
	velocity = vel;
	acceleration = vector2();

	colliding = false;

	mass = 1;
}

physicalObject::physicalObject(vector2 pos, vector2 vel, vector2 acc)
{
	position = pos;
	velocity = vel;
	acceleration = acc;

	colliding = false;

	mass = 1;
}

physicalObject::physicalObject(vector2 pos, vector2 vel, vector2 acc, float m)
{
	position = pos;
	velocity = vel;
	acceleration = acc;

	colliding = false;

	mass = m;
}

float physicalObject::getMass()
{
	return mass;
}

float physicalObject::setMass(float m)
{
	return mass = m;
}

bool physicalObject::getCollisionFlag()
{
	return colliding;
}

void physicalObject::setCollisionFlag(bool flag)
{
	colliding = flag;
}

float physicalObject::getXpos()
{
	return position.getX();
}

float physicalObject::getYpos()
{
	return position.getY();
}

vector2 physicalObject::getPosition()
{
	return position;
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

void physicalObject::setPosition(vector2 pos)
{
	position = pos;
}

void physicalObject::setPosition(float x, float y)
{
	position = vector2(x, y);
}

void physicalObject::setVelocity(vector2 vel)
{
	velocity = vel;
}

void physicalObject::setVelocity(float x, float y)
{
	velocity = vector2(x, y);
}

void physicalObject::setAcceleration(vector2 acc)
{
	acceleration = acc;
}

void physicalObject::setAcceleration(float x, float y)
{
	acceleration = vector2(x, y);
}

bool physicalObject::operator == (physicalObject o)
{
	return  position == o.getPosition() && 
			velocity == o.getVelocity() &&
			acceleration == o.getAcceleration() &&
			mass == o.getMass();
}
