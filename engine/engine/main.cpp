///-------------------------------------------------/
///	File: main.cpp
///
///	Purpose: This file is for internal testing of
///				engine classes and methods
///-------------------------------------------------/

#include "pch.h"
#include "engine.h"
#include "physicalObject.h"
#include "vector2.h"
#include "circle.h"
#include "rectangle.h"
#include "polygon.h"
#include <iostream>

using namespace std;

int main()
{
	// Initialization
	engine physicsEngine;

	bool running = true;
	bool collision = false;

	circle circ1(10, vector2());
	circ1.setVelocity(vector2(5, 0));

	rectangle rect1(vector2(10, 10), vector2());

	physicsEngine.addCircle(circ1);
	physicsEngine.addPolygon(rect1);

	// while loop for execution bounded by time delta
	while (running)
	{
		bool updated = physicsEngine.update(10);
		if (updated)
		{
			if (circ1.getPosition().getX() >= 100 || circ1.getPosition().getX() <= -100)
				running = false;
			vector2 pos = circ1.getPosition();
			cout << "Circle at: (" << pos.getX() << ", " << pos.getY() << ")\n";
		}
	}

	vector2 v(10, 10);
	v = v * 10;
	cout << "(" << v.getX() << ", " << v.getY() << ")" << endl;

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
}