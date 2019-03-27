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

	float getSideX();
	float getSideY();
	void  setSideX(float len);
	void  setSideY(float len);

	float getArea();
};

#endif // !RECTANGLE_H

