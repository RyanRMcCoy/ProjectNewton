#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <array>
class physicalObject 
{
private:
	std::array <float, 2> position, velocity, acceleration;
	//vector2 velocity, acceleration;
public:
	physicalObject();
	physicalObject(float x, float y);

	float getXpos ();
	float getYpos ();
	float getXvel ();
	float getYvel ();
	float getXacc ();
	float getYacc ();

	float setXpos (float x);
	float setYpos (float y);
	float setXvel (float x);
	float setYvel (float y);
	float setXacc (float x);
	float setYacc (float y);
};

#endif // !PHYSICALOBJECT_H;
