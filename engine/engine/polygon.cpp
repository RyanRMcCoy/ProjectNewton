#include <iterator>
#include "pch.h"
#include "polygon.h"
#include "vector2.h"

/* So the idea that I have right now is to come up with some intermediate class/object whose purpose is to
	translate a set of vertices passed into the physics engine into a set of vertices centered around the center
	of mass of the polygon which is passed into here. Centroid becomes the position so we will always have
	a simple reference of that. The way that we calculate the center of mass is by decomposing the polygon into a
	set of triangles and determining the individual centroids and taking the weighted mean of them all.
*/

using namespace std;

// Helper function to adjust relativeVertices
void offsetVertices(int s, vector2 v[], vector2 relativeV[], vector2 pos)
{
	for (int i = 0; i < s; i++)
	{
		v[i] = pos + relativeV[i];
	}
}

polygon::polygon() : sides(3), vertices(new vector2[3]), relativeVertices(new vector2[3]), physicalObject() {}

polygon::polygon(int s) : sides(s), vertices(new vector2[s]), relativeVertices(new vector2[s]), physicalObject() {}

polygon::polygon(int s, vector2 v[]) : sides(s), vertices(new vector2[s]), relativeVertices(new vector2[s]), physicalObject()
{
	copy(v, v + s, relativeVertices);
	offsetVertices(sides, vertices, relativeVertices, getPosition());
}

polygon::polygon(int s, vector2 v[], vector2 pos) : sides(s), vertices(new vector2[s]), 
relativeVertices(new vector2[s]), physicalObject(pos)
{
	copy(v, v + s, relativeVertices);
	setPosition(pos);
}

void polygon::setPosition(vector2 pos)
{
	__super::setPosition(pos);
	offsetVertices(sides, vertices, relativeVertices, pos);
}

int polygon::numSides()
{
	return sides;
}

vector2 *polygon::getVertices()
{
	return vertices;
}

void polygon::setVertices(vector2 v[])
{
	copy(v, v + sides, relativeVertices);
	offsetVertices(sides, vertices, relativeVertices, getPosition());
}
