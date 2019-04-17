#include <limits>
#include "pch.h"
#include "satHandler.h"
#include "vector2.h"
#include <iostream>

using namespace std;

satHandler::satHandler() {}
const float maxFloat = numeric_limits<float>::max();

vector2 getMinProjection(int n, vector2 *vertices, vector2 projectionAxis)
{
	vector2 minProjection = vertices[0].project(projectionAxis);
	if (projectionAxis.getX() != 0)
	{
		for (int i = 1; i < n; i++)
		{
			vector2 projection = vertices[i].project(projectionAxis);
			if (projection.getX() < minProjection.getX())
			{
				minProjection = projection;
			}
		}
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			vector2 projection = vertices[i].project(projectionAxis);
			if (projection.getY() < minProjection.getY())
			{
				minProjection = projection;
			}
		}
	}
	return minProjection;
}

vector2 getMaxProjection(int n, vector2 *vertices, vector2 projectionAxis)
{
	vector2 maxProjection = vertices[0].project(projectionAxis);
	if (projectionAxis.getX() != 0)
	{
		for (int i = 1; i < n; i++)
		{
			vector2 projection = vertices[i].project(projectionAxis);
			if (projection.getX() > maxProjection.getX())
			{
				maxProjection = projection;
			}
		}
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			vector2 projection = vertices[i].project(projectionAxis);
			if (projection.getY() > maxProjection.getY())
			{
				maxProjection = projection;
			}
		}
	}
	return maxProjection;
}

/*
	Not sure if the overlap calculations for the cases where one objects projection
	is within the others are correct.
*/
vector2 determineOverlap(vector2 o1MinProj, vector2 o1MaxProj, vector2 o2MinProj, vector2 o2MaxProj, bool *overhang)
{
	// Primitive representations of vector projections (for simpler math)
	float v11(0), v12(0), v21(0), v22(0);

	// This checks to make sure that the x dimension is not 0
	if ((o1MinProj.getX() != 0 && o1MinProj.getX() != o1MaxProj.getX()) ||
		(o2MinProj.getX() != 0 && o2MinProj.getX() != o2MaxProj.getX()))
	{
		v11 = o1MinProj.getX();
		v12 = o1MaxProj.getX();
		v21 = o2MinProj.getX();
		v22 = o2MaxProj.getX();
	}
	else // If it was 0, use y values instead
	{
		v11 = o1MinProj.getY();
		v12 = o1MaxProj.getY();
		v21 = o2MinProj.getY();
		v22 = o2MaxProj.getY();
	}

	if (v11 >= v21 && v11 <= v22)
	{
		if (v12 >= v22) // o1 projection partially inside o2 projection (coming from right side)
		{ 
			*overhang = true;
			return o2MaxProj - o1MinProj;
		}
		else // o1 projection completely inside o2 projection
			if (abs(v22 - v11) < abs(v21 - v12))
				return o2MaxProj - o1MinProj; // I'm a little confused about what to return here maybe cuz I'm tired
			else
				return o2MinProj - o1MaxProj;
	}
	if (v21 >= v11 && v21 <= v12)
	{
		if (v22 >= v12) // o2 projection partially inside o1 projection (coming from right side also)
		{ 
			*overhang = true;
			return o2MinProj - o1MaxProj;
		}
		else // o2 projection completely inside o1 projection
			if (abs(v12 - v21) < abs(v11 - v22))
				return o1MaxProj - o2MinProj;
			else
				return o1MinProj - o2MaxProj;
	}
	return vector2(maxFloat, 0);
}

vector2 satHandler::overlapping(circle o1, circle o2)
{
	vector2 overlap = o2.getPosition() - o1.getPosition();
	float distance = overlap.magnitude() - (o1.getRadius() + o2.getRadius());
	if (distance < 0)
		return overlap.unit() * distance;
	return vector2();
}

/*
	Can I possibly stick to a single dimension for the whole method and therefore not
	need to store every vector?
	 - Similar to determineOverlap method

	Possibly check whether x is 0, and if so then substitute y in for x to avoid writing
	different chunks of code.
*/
vector2 satHandler::overlapping(circle o1, polygon o2)
{
	int n = o2.numSides();
	vector2 *vertices = o2.getVertices();

	float minOverlapMag = maxFloat;
	vector2 minOverlap; // Direction for o1 to move "out" of o2

	bool overhang = false;

	for (int i = 0; i < n; i++)
	{
		// Projection axes are normals(perps) of each side of polygon
		vector2 projectionAxis = (vertices[(i + 1) % n] - vertices[i]).perpendicular().unit();

		// Get the projections for each shape onto the projectionAxis
		vector2 o1Proj = o1.getPosition().project(projectionAxis);
		vector2 o1MinProj = o1Proj - projectionAxis * o1.getRadius();
		vector2 o1MaxProj = o1Proj + projectionAxis * o1.getRadius();
		vector2 o2MinProj = getMinProjection(n, vertices, projectionAxis);
		vector2 o2MaxProj = getMaxProjection(n, vertices, projectionAxis);

		bool newOverhang = false;

		if (projectionAxis.getX() != 0 && o1MinProj.getX() > o1MaxProj.getX())
		{
			vector2 temp = o1MinProj;
			o1MinProj = o1MaxProj;
			o1MaxProj = temp;
		}
		else if (projectionAxis.getY() != 0 && o1MinProj.getY() > o1MaxProj.getY())
		{
			vector2 temp = o1MinProj;
			o1MinProj = o1MaxProj;
			o1MaxProj = temp;
		}

		vector2 overlap = determineOverlap(o1MinProj, o1MaxProj, o2MinProj, o2MaxProj, &newOverhang);

		// If there was no overlap found, then return zero vector
		if (overlap.getX() == maxFloat)
			return vector2();

		// Check if the circle overlaps the vertex at all
		vector2 vertexOverlap = o1.getPosition() - vertices[i];
		if (vertexOverlap.magnitude() < o1.getRadius())
		{
			if (vertexOverlap.magnitude() < minOverlapMag)
			{
				overhang = newOverhang;
				minOverlap = vertexOverlap;
				minOverlapMag = vertexOverlap.magnitude();
			}
		}

		if (overlap.magnitude() < minOverlapMag)
		{
			minOverlap = overlap;
			minOverlapMag = minOverlap.magnitude();
		}
	}

	if (overhang)
	{
		for (int i = 0; i < n; i++)
		{
			vector2 vertex = vertices[i];
			if ((o1.getPosition() - vertex).magnitude() < o1.getRadius())
			{
				return (vertex - o2.getPosition());
			}
		}
	}

	return minOverlap;
}

vector2 satHandler::overlapping(polygon o1, circle o2)
{
	return this->overlapping(o2, o1);
}

vector2 satHandler::overlapping(polygon o1, polygon o2)
{
	int n1 = o1.numSides();
	vector2 *vertices1 = o1.getVertices();
	int n2 = o2.numSides();
	vector2 *vertices2 = o2.getVertices();

	float minOverlapMag = maxFloat;
	vector2 minOverlap; // Direction for o1 to move "out" of o2

	bool overhang = false;

	for (int i = 0; i < n1; i++)
	{
		// Projection axes are normals(perps) of each side of polygon
		vector2 projectionAxis = (vertices1[(i + 1) % n1] - vertices1[i]).perpendicular();

		// Get the projections for each shape onto the projectionAxis
		vector2 o1Proj = o1.getPosition().project(projectionAxis);
		vector2 o1MinProj = getMinProjection(n1, vertices1, projectionAxis);
		vector2 o1MaxProj = getMaxProjection(n1, vertices1, projectionAxis);
		vector2 o2MinProj = getMinProjection(n2, vertices2, projectionAxis);
		vector2 o2MaxProj = getMaxProjection(n2, vertices2, projectionAxis);

		vector2 overlap = determineOverlap(o1MinProj, o1MaxProj, o2MinProj, o2MaxProj, &overhang);

		if (overlap.getX() == maxFloat) { // No overlap so return
			return vector2();
		}

		if (overlap.magnitude() < minOverlapMag)
		{
			minOverlap = overlap;
			minOverlapMag = minOverlap.magnitude();
		}
	}
	for (int i = 0; i < n2; i++)
	{
		// Projection axes are normals(perps) of each side of polygon
		vector2 projectionAxis = (vertices2[(i + 1) % n2] - vertices2[i]).perpendicular().unit();

		// Get the projections for each shape onto the projectionAxis
		vector2 o1Proj = o1.getPosition().project(projectionAxis);
		vector2 o1MinProj = getMinProjection(n1, vertices1, projectionAxis);
		vector2 o1MaxProj = getMaxProjection(n1, vertices1, projectionAxis);
		vector2 o2MinProj = getMinProjection(n2, vertices2, projectionAxis);
		vector2 o2MaxProj = getMaxProjection(n2, vertices2, projectionAxis);

		vector2 overlap = determineOverlap(o1MinProj, o1MaxProj, o2MinProj, o2MaxProj, &overhang);

		if (overlap.getX() == maxFloat) { // No overlap so return
			return vector2();
		}

		if (overlap.magnitude() < minOverlapMag)
		{
			minOverlap = overlap;
			minOverlapMag = minOverlap.magnitude();
		}
	}

	return minOverlap;
}