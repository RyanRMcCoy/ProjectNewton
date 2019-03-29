#include "pch.h"
#include "vector2.h"
#include "physicalObject.h"
#include "satHandler.h"
#include "engine.h"
#include <ctime>

using namespace std;
/*
engine::engine() {
	collisionHandler = satHandler();
}

void engine::addCircle(circle o)
{
	circles.push_back(o);
}

vector<circle> engine::getCircles()
{
	return circles;
}

void engine::addPolygon(polygon o)
{
	polygons.push_back(o);
}

vector<polygon> engine::getPolygons()
{
	return polygons;
}

void engine::update()
{
	float dt = lastUpdate - clock();
	lastUpdate += dt;

	for (circle o : circles)
		o.setCollisionFlag(false);

	for (polygon o : polygons)
		o.setCollisionFlag(false);

	for (unsigned int i = 0; i < circles.size() + polygons.size(); i++)
	{
		if (i >= circles.size())
			for (unsigned int j = polygons.size() - 1; j > (i - circles.size()); j--)
			{
				vector2 overlap = collisionHandler.overlapping(polygons.at(i - circles.size()), polygons.at(j));
				if (!(overlap == vector2()))
				{
					polygons.at(i).setCollisionFlag(true); // This is a really bad way of doing this
					polygons.at(i).setCollisionFlag(true); // just for testing tho
				}
			}
		for (unsigned int j = circles.size() - 1; j > i; j--)
		{
			vector2 overlap;
			if (i < circles.size())
				overlap = collisionHandler.overlapping(circles.at(i), circles.at(j));
			else
				overlap = collisionHandler.overlapping(polygons.at(i - circles.size()), circles.at(j));
			if (!(overlap == vector2()))
			{
				circles.at(i).setCollisionFlag(true); // This is a really bad way of doing this
				circles.at(i).setCollisionFlag(true); // just for testing tho
			}
		}
	}
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file