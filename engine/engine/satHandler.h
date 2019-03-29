#pragma once

#include "circle.h"
#include "polygon.h"
#include "vector2.h"

class satHandler
{
public:
	satHandler();

	// Overlapping returns how much o1 overlaps (or has to move to get out of) o2
	// A return of (0, 0) means no overlap
	vector2 overlapping(circle o1, circle o2);
	vector2 overlapping(circle o1, polygon o2);
	vector2 overlapping(polygon o1, circle o2);
	vector2 overlapping(polygon o1, polygon o2);
};

