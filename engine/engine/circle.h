#ifndef CIRCLE_H
#define CIRCLE_H

#include "physicalObject.h"
class circle : public physicalObject
{
private: 
	float radius;
public:
	circle (float rad);
	float getRadius ();
	float setRadius (float rad);
};

#endif // !CIRCLE_H