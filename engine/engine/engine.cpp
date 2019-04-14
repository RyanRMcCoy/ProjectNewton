#include "pch.h"
#include "vector2.h"
#include "physicalObject.h"
#include "satHandler.h"
#include "collisionHandler.h"
#include "engine.h"
#include <ctime>

#include <iostream>

using namespace std;

engine::engine() {
	collisionDetector = satHandler();
	collisionResolver = collisionHandler();
	lastUpdate = clock() / 1000.F;
}

void engine::addCircle(circle &o)
{
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
		if (dt < .25)
			enabled = true;
	}
	
	if (enabled)
	{
		for (circle *o : circles)
		{
			if (!o->getAnchored())
			{
				o->setPosition(o->getPosition() + o->getVelocity() * dt);
				o->setVelocity(o->getVelocity() + o->getAcceleration() * dt);
			}
		}

		for (polygon *o : polygons)
		{
			if (!o->getAnchored())
			{
				o->setPosition(o->getPosition() + o->getVelocity() * dt);
				o->setVelocity(o->getVelocity() + o->getAcceleration() * dt);
			}
		}

		for (unsigned int i = 0; i < circles.size() + polygons.size(); i++)
		{
			for (unsigned int j = circles.size() + polygons.size() - 1; j > i; j--)
			{
				vector2 overlap;
				if (i < circles.size() && j < circles.size())
				{
					if (circles.at(i)->getAnchored() && circles.at(i)->getAnchored());
					{
						overlap = collisionDetector.overlapping(*circles.at(i), *circles.at(j));
						if (overlap != vector2())
							collisionResolver.resolveCollision(circles.at(i), circles.at(j), &overlap);
					}
				}
				else if (i < circles.size() && j >= circles.size())
				{
					if (circles.at(i)->getAnchored() && polygons.at(j - circles.size())->getAnchored());
					{
						overlap = collisionDetector.overlapping(*circles.at(i), *polygons.at(j - circles.size()));
						if (overlap != vector2())
							collisionResolver.resolveCollision(circles.at(i), polygons.at(j - circles.size()), &overlap);
					}
				}
				else
				{
					if (polygons.at(i - circles.size())->getAnchored() && polygons.at(j - circles.size())->getAnchored());
					{
						overlap = collisionDetector.overlapping(*polygons.at(i - circles.size()), *polygons.at(j - circles.size()));
						if (overlap != vector2())
							collisionResolver.resolveCollision(polygons.at(i - circles.size()), polygons.at(j - circles.size()), &overlap);
					}
				}
			}
		}
		return true;
	}
	return false;
}