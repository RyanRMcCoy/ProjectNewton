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
	circle(float rad, vector2 pos, float d);

	float getRadius();
	void  setRadius(float rad);

	float getArea();

	float getMass();
	float setMass(float m);

	float getDensity();
	float setDensity(float d);

	void updateMass();
	void updateDensity();

	float getFriction();
	void  setFriction(float m);
};

#endif // !CIRCLE_H