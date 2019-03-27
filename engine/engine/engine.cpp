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

	vector2 vertices[3] = { vector2(5, 10), vector2(2, 2), vector2(12, 2) };
	polygon p(3, vertices);
	cout << "Vertex 1: (" << p.getVertices()[0].getX() << ", " << p.getVertices()[0].getY() << ")" << endl;
	
	rectangle firstRect(10, 10);
	std::cout << firstRect.getXpos() << endl;
	std::cout << firstRect.getSideX() << endl;

	circle circ(5);
	std::cout << "rad: " << circ.getRadius() << ", pos: (" << circ.getXpos() << ", " << circ.getYpos() << ")" << endl;
	std::cout << "vel: (" << circ.getVelocity().magnitude() << ")" << endl;
	circ.setVelocity(9, 3);
	std::cout << "vel: (" << circ.getVelocity().magnitude() << ")" << endl;

	std::cin >> dt;
}

bool overlapping(circle o1, circle o2)
{
	return (o1.getPosition() - o2.getPosition()).magnitude() < 
		o1.getRadius() + o2.getRadius();
}

bool overlapping(circle o1, polygon o2)
{
	return false;
}

bool overlapping(polygon o1, circle o2)
{
	return overlapping(o2, o1);
}

bool overlapping(polygon o1, polygon o2)
{
	return false;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
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
}
*/