#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "physicalObject.h"
#include "polygon.h"

class rectangle : public polygon
{
private:
	float sideLenX;
	float sideLenY;
public:
	rectangle();
	rectangle(float lenX, float lenY);
	rectangle(vector2 size);
	rectangle(float lenX, float lenY, vector2 pos);
	rectangle(vector2 size, vector2 pos);
	rectangle(float lenX, float lenY, vector2 pos, float d);

	float getSideX();
	float getSideY();
	void  setSideX(float len);
	void  setSideY(float len);

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

#endif // !RECTANGLE_H

