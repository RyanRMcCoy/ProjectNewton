#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <array>
#include "vector2.h"
class physicalObject 
{
private:
	std::array <float, 2> position;
	vector2 velocity, acceleration;
public:
	physicalObject();
	physicalObject(float x, float y);

	float getXpos ();
	float getYpos ();
	float getXvel ();
	float getYvel ();
	vector2 getVelVector();
	float getXacc ();
	float getYacc ();
	vector2 getAccVector();


	float setXpos (float x);
	float setYpos (float y);
	void setVelocity(float x, float y);
	void setAcceleration(float x, float y);
};

#endif // !PHYSICALOBJECT_H;
