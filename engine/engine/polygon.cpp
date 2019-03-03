#include "pch.h"
#include "polygon.h"
#include "vector2.h"

/* So the idea that I have right now is to come up with some intermediate class/object whose purpose is to
	translate a set of vertices passed into the physics engine into a set of vertices centered around the center
	of mass of the polygon which is passed into here. Centroid becomes the position so we will always have
	a simple reference of that. The way that we calculate the center of mass is by decomposing the polygon into a
	set of triangles and determining the individual centroids and taking the weighted mean of them all.
*/

polygon::polygon() {}

polygon::polygon(int s) : sides(s), vertices(new vector2[s]) {}

polygon::polygon(int s, vector2 v[]) : sides(s), vertices(v) {}

vector2* polygon::getVertices()
{
	return vertices;
}

