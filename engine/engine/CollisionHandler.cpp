#include "pch.h"
#include "CollisionHandler.h"


CollisionHandler::CollisionHandler() {}

void resolveCollision(physicalObject *o1, physicalObject *o2, vector2 *penetration)
{
	float avgFriction = (o1->getFriction() + o2->getFriction()) / 2;
	float totalMass = (o1->getMass() + o2->getMass());
	float o1Ratio = o1->getMass() / (o1->getMass() + o2->getMass());
	float o2Ratio = o2->getMass() / (o2->getMass() + o2->getMass());

	vector2 p1 = o1->getVelocity() * o1->getMass();
	vector2 p2 = o2->getVelocity() * o2->getMass();
	vector2 pTotal = p1 + p2;

	// Move objects out of each other

	// Determine velocities
}

/* 
	These exist because it might be possible to take shortcuts in calculations of
	basic objects like circles and non-rotated rectangles

	|||
	vvv
*/
void CollisionHandler::resolveCollision(circle *o1, circle *o2, vector2 *penetration)
{
	resolveCollision(o1, o2, penetration);
}

void CollisionHandler::resolveCollision(circle *o1, polygon *o2, vector2 *penetration)
{
	resolveCollision(o1, o2, penetration);
}

void CollisionHandler::resolveCollision(polygon *o1, circle *o2, vector2 *penetration)
{
	resolveCollision(o1, o2, penetration);
}

void CollisionHandler::resolveCollision(polygon *o1, polygon *o2, vector2 *penetration)
{
	resolveCollision(o1, o2, penetration);
}