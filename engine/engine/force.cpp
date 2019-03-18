#include "pch.h"
#include "force.h"


force::force()
{
	obj = physicalObject();
	accelerationVector = vector2();
}

force::force(physicalObject o)
{
	obj = o;
	accelerationVector = vector2();
}

force::force(vector2 v)
{
	obj = physicalObject();
	accelerationVector = v;

	updateMagnitude();
	updateObjAcc();
}

force::force(physicalObject o, vector2 v)
{
	obj = o; 
	accelerationVector = v;

	updateMagnitude();
	updateObjAcc();
}

void force::updateMagnitude() 
{
	magnitude = sqrt(pow(accelerationVector.getX(), 2) + pow(accelerationVector.getY(), 2));
}

void force::updateObjAcc()
{
	obj.setAcceleration(accelerationVector / obj.getMass());
}

physicalObject force::getObj()
{
	return obj;
}

void force::setObj(physicalObject o)
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
}

float force::getMagnitude()
{
	return accelerationVector.magnitude();
}

void force::setMagnitude(float mag)
{
	accelerationVector = vector2(cos(mag), sin(mag));
	accelerationVector.magnitude();
}
