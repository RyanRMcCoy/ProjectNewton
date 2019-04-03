#pragma once

#include "circle.h"
#include "polygon.h"
#include "vector2.h"

class CollisionHandler
{
private:

public:
	CollisionHandler();
	void resolveCollision(circle *o1, circle *o2, vector2 *penetration);
	void resolveCollision(circle *o1, polygon *o2, vector2 *penetration);
	void resolveCollision(polygon *o1, circle *o2, vector2 *penetration);
	void resolveCollision(polygon *o1, polygon *o2, vector2 *penetration);
};

