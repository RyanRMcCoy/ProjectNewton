#ifndef CIRCLE_H
#define CIRCLE_H

#include "physicalObject.h"
#include "rectangle.h"

class circle : public physicalObject
{
private: 
	float radius;
public:
	circle();
	circle(float rad);
	circle(float rad, vector2 pos);

	float getRadius();
	void  setRadius(float rad);

	bool intersect(circle o);
	bool intersect(rectangle o);
};

#endif // !CIRCLE_H