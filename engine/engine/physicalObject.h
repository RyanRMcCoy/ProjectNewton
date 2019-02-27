#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <array>
#include "vector2.h"
class physicalObject 
{
private:
	//std::array <float, 2> position;
	vector2 position, velocity, acceleration;
public:
	physicalObject();
	physicalObject(vector2 position);

	float getXpos();
	float getYpos();
	vector2 getPos();
	float getXvel ();
	float getYvel ();
	vector2 getVelVector();
	float getXacc ();
	float getYacc ();
	vector2 getAccVector();

	void setVelocity(float x, float y);
	void setAcceleration(float x, float y);
};

#endif // !PHYSICALOBJECT_H;
