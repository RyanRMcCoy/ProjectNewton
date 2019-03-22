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

	for (int i = 0; i < objects.size; i++)
	{
		for (int j = objects.size - 1; j > i; j--)
		{
			vector2 overlap = collisionHandler.overlapping(objects.at(i), objects.at(j));
			if (!(overlap == vector2()))
			{
				objects.at(i).setCollisionFlag(true); // This is a really bad way of doing this
				objects.at(i).setCollisionFlag(true); // just for testing tho
			}
		}
	}
}