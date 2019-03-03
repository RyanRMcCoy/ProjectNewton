// engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "physicalObject.h"
#include "vector2.h"
#include "circle.h"
#include "rectangle.h"
#include "polygon.h"
using namespace std;

int main()
{
	// Initialization
	bool running = true;
	float dt;

	// while loop for execution bounded by time delta
	while (running)
	{
		
		running = false; // temporary obviously
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

	std::cin >> dt;
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
