#pragma once

#include "vertex.h"

class polygon : public physicalObject
{
private:
	int sides;
	vertex root;
public:
	polygon(int s);
	polygon(int s, vertex r);
};