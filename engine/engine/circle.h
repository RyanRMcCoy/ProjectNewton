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

	bool intersect(circle o);
	bool intersect(rectangle o);
};

#endif // !CIRCLE_H