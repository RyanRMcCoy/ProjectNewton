#include "vector2.h"
#include "physicalObject.h"
#include "aabbHandler.h"
#include "engine.h"
#include <ctime>

using namespace std;

engine::engine() {
	collisionHandler = aabbHandler();
}

void engine::addObject(physicalObject o)
{
	objects.push_back(o);
}

vector<physicalObject> engine::getObjects()
{
	return objects;
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
