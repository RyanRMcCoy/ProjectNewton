///-------------------------------------------------/
///	Class: collisionHandler
///
///	Purpose: This class provides functionality for
///		resolving detected collisions between objects
///-------------------------------------------------/

#pragma once

#include "circle.h"
#include "polygon.h"
#include "vector2.h"

class collisionHandler
{
private:

public:
	collisionHandler();

	/// Function: resolveCollision
	/// Purpose: Resolves collisions between two circles
	void resolveCollision(circle *o1, circle *o2, vector2 *penetration, float dt);

	/// Function: resolveCollision
	/// Purpose: Resolves collisions between circles and a polygons
	void resolveCollision(circle *o1, polygon *o2, vector2 *penetration, float dt);

	/// Function: resolveCollision
	/// Purpose: Resolves collisions polygons and a circles
	void resolveCollision(polygon *o1, circle *o2, vector2 *penetration, float dt);

	/// Function: resolveCollision
	/// Purpose: Resolves collisions between two polygons
	void resolveCollision(polygon *o1, polygon *o2, vector2 *penetration, float dt);
};

