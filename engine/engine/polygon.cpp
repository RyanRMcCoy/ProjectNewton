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

float polygon::dist(vector2 v1, vector2 v2)
{
	return sqrt(pow(v1.getX() - v2.getX(), 2) + pow(v1.getY() - v2.getY(), 2));
}

//for finding area.
/*float polygon :: heron(vector2 v[])
{
	float perimeter = 0;
	float sideLen[3];
	for (int i = 0; i < 2; i++)
	{

		perimeter = perimeter + dist(v[i], v[i + 1]);
	}
	perimeter = perimeter + dist(v[s], v[0]);
	
	float p = perimeter / 2;
	

	return 0.0f;
}*/

void polygon::setDefaultMat()
{
	density = 1;
	updateMass();

	mu = 0;
}

polygon::polygon() : sides(3), vertices(new vector2[3]), relativeVertices(new vector2[3]), physicalObject() { setDefaultMat(); }

polygon::polygon(int s) : sides(s), vertices(new vector2[s]), relativeVertices(new vector2[s]), physicalObject() { setDefaultMat(); }

polygon::polygon(int s, vector2 v[]) : sides(s), vertices(new vector2[s]), relativeVertices(new vector2[s]), physicalObject()
{
	copy(v, v + s, relativeVertices);
	offsetVertices(sides, vertices, relativeVertices, getPosition());
	setDefaultMat();
}

polygon::polygon(int s, vector2 v[], vector2 pos) : sides(s), vertices(new vector2[s]), 
	relativeVertices(new vector2[s]), physicalObject(pos)
{
	copy(v, v + s, relativeVertices);
	setPosition(pos);
	setDefaultMat();
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

float polygon::getArea()
{
	return 0.0f;
}

float polygon::getMass()
{
	return mass;
}

float polygon::setMass(float m)
{
	mass = m;
	updateDensity();
	return mass;
}

float polygon::getDensity()
{
	return density;
}

float polygon::setDensity(float d)
{
	density = d;
	updateMass();
	return density;
}

void polygon::updateMass()
{
	mass = density * getArea();
}

void polygon::updateDensity()
{
	density = mass / getArea();
}

void polygon::setVertices(vector2 v[])
{
	copy(v, v + sides, relativeVertices);
	offsetVertices(sides, vertices, relativeVertices, getPosition());
}
