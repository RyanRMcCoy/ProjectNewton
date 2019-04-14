#include "pch.h"
#include "force.h"

force::force()
{
	obj = &circle();
	accelerationVector = vector2();
}

force::force(physicalObject *o)
{
	obj = o;
	accelerationVector = vector2();
}

force::force(vector2 v)
{
	obj = &circle(1);
	accelerationVector = v;

	updateMagnitude();
	updateObjAcc();
}

force::force(physicalObject *o, vector2 v)
{
	obj = o; 
	accelerationVector = v;

	updateMagnitude();
	updateObjAcc();
}

void force::updateMagnitude() 
{
	magnitude = accelerationVector.magnitude();
}

void force::updateObjAcc()
{
	obj -> setAcceleration(accelerationVector/obj->getMass());
}

physicalObject* force::getObj()
{
	return obj;
}

void force::setObj(physicalObject *o)
{
	obj = o;
}

vector2 force::getVector()
{
	return accelerationVector;
}

void force::setVector(vector2 v)
{
	accelerationVector = vector2(v.getX(), v.getY());
	updateObjAcc();
	updateMagnitude();
}

float force::getMagnitude()
{
	return accelerationVector.magnitude();
}

void force::setMagnitude(float mag)
{
	vector2 newVector = accelerationVector.unit() * mag;
	
	setVector(newVector);
}
