#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "physicalObject.h"

class rectangle : public physicalObject
{
private:
	float sideLenX;
	float sideLenY;
public:
	rectangle();
	rectangle(float lenX, float lenY);
	rectangle(float lenX, float lenY, vector2 pos);

	float getSideX();
	float getSideY();
	void  setSideX(float len);
	void  setSideY(float len);

	float getArea();
};

#endif // !RECTANGLE_H

