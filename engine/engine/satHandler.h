///-------------------------------------------------/
///	Class: satHandler
///
///	Purpose: This class provides functionality for
///		detecting collisions between objects
///-------------------------------------------------/

#pragma once

#include "circle.h"
#include "polygon.h"
#include "vector2.h"

class satHandler
{
public:
	satHandler();

	/// Function: overlapping
	/// Purpose: Detects collision between two circles
	/// Note: Returns how much o1 overlaps (or has to move to get out of) o2.
	///		A return of (0, 0) means no overlap
	vector2 overlapping(circle o1, circle o2);

	/// Function: overlapping
	/// Purpose: Detects collision between a circle and polygon
	vector2 overlapping(circle o1, polygon o2);

	/// Function: overlapping
	/// Purpose: Detects collision between a polygon and a circle
	vector2 overlapping(polygon o1, circle o2);

	/// Function: overlapping
	/// Purpose: Detects collision between two polygons
	vector2 overlapping(polygon o1, polygon o2);
};

