#pragma once

#include "vector2.h"

class aabbHandler
{
public:
	aabbHandler();

	vector2 overlapping(circle o1, circle o2);
	vector2 overlapping(circle o1, polygon o2);
	vector2 overlapping(polygon o1, circle o2);
	vector2 overlapping(polygon o1, polygon o2);
};

