#pragma once

#include "vector2.h"

class vertex
{
private:
	vector2 position;
	vertex *previous;
	vertex *next;
public:
	vertex();
	vertex(vector2 p);
	
	vector2 getPosition();
	vertex getPrevious();
	vertex getNext();
};

