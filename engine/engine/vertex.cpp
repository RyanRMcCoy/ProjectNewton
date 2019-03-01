#include "pch.h"
#include "vertex.h"

vertex::vertex() : position(vector2()) {}
vertex::vertex(vector2 p) : position(p) {}

vector2 vertex::getPosition()
{
	return position;
}

vertex vertex::getPrevious()
{
	return *previous;
}

vertex vertex::getNext()
{
	return *next;
}