#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <array>
#include "vector2.h"
class physicalObject 
{
private:
	vector2 position, velocity, acceleration;
public:
	physicalObject();
	physicalObject(vector2 position);
	physicalObject(vector2 position, vector2 velocity);
	physicalObject(vector2 position, vector2 velocity, vector2 acceleration);

	float getXpos();
	float getYpos();
	vector2 getPosition();
	float getXvel();
	float getYvel();
	vector2 getVelocity();
	float getXacc();
	float getYacc();
	vector2 getAcceleration();

	void setPosition(float x, float y);
	void setVelocity(float x, float y);
	void setAcceleration(float x, float y);
};

#endif // !PHYSICALOBJECT_H;
