#include "pch.h"
#include "vector2.h"
#include "physicalObject.h"
#include "satHandler.h"
#include "engine.h"
#include <ctime>

#include <iostream>

using namespace std;

engine::engine() {
	collisionHandler = satHandler();
	lastUpdate = clock() / 1000.F;
}

void engine::addCircle(circle &o)
{
	cout << "Circle received with memory address " << &o << endl;
	circles.push_back(&o);
}

vector<circle*> engine::getCircles()
{
	return circles;
}

void engine::addPolygon(polygon &o)
{
	polygons.push_back(&o);
}

vector<polygon*> engine::getPolygons()
{
	return polygons;
}

bool engine::update(int refreshRate)
{
	float dt = (clock() / 1000.F) - lastUpdate;

	bool enabled = false;
	if (dt > (1.F / refreshRate)) {
		lastUpdate += dt;
		enabled = true;
	}

	if (enabled)
	{
		for (circle *o : circles)
		{
			o->setCollisionFlag(false);
			o->setPosition(o->getPosition() + o->getVelocity() * dt);
			o->setAcceleration(o->getVelocity() + o->getAcceleration() * dt);
		}

		for (polygon *o : polygons)
		{
			o->setCollisionFlag(false);
			o->setPosition(o->getPosition() + o->getVelocity() * dt);
			o->setVelocity(o->getVelocity() + o->getAcceleration() * dt);
		}

		for (unsigned int i = 0; i < circles.size() + polygons.size() && enabled; i++)
		{
			for (unsigned int j = circles.size() + polygons.size() - 1; j > i; j--)
			{
				vector2 overlap;
				if (i < circles.size() && j < circles.size())
				{
					overlap = collisionHandler.overlapping(*circles.at(i), *circles.at(j));
				}
				else if (i < circles.size() && j >= circles.size())
				{
					overlap = collisionHandler.overlapping(*circles.at(i), *polygons.at(j - circles.size()));
				}
				else
				{
					overlap = collisionHandler.overlapping(*polygons.at(i - circles.size()), *polygons.at(j - circles.size()));
				}
				
				if (!(overlap == vector2()))
				{
					circles.at(i)->setCollisionFlag(true); // This is a really bad way of doing this
					circles.at(i)->setCollisionFlag(true); // just for testing tho
				}
				if (!(overlap == vector2()))
					cout << "Overlap: (" << overlap.getX() << ", " << overlap.getY() << ")\n";
			}
		}
		return true;
	}
	return false;
}