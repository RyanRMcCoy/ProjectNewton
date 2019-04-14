#pragma once
#include "vector2.h"

class force
{
private:
	physicalObject *obj;			// Object being acted upon
	vector2 accelerationVector;	// Vector of the Force
	float magnitude;
public:
	force();
	force(physicalObject *o);
	force(vector2 v);
	force(physicalObject *o, vector2 v);

	void updateMagnitude();
	void updateObjAcc();

	physicalObject *getObj();
	void setObj(physicalObject *o);
	
	vector2 getVector();
	void setVector(vector2 v);

	float getMagnitude();
	void  setMagnitude(float mag);
};

