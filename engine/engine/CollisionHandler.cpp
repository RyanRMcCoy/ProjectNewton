#include "pch.h"
#include "CollisionHandler.h"


collisionHandler::collisionHandler() {}

void resolveCollision(physicalObject *o1, physicalObject *o2, vector2 *penetration)
{
	float avgFriction = (o1->getFriction() + o2->getFriction()) / 2;
	float totalMass = (o1->getMass() + o2->getMass());
	float o1Ratio = (o1->getVelocity() * o1->getMass()).magnitude() / 
		(o2->getVelocity() * o2->getMass()).magnitude();
	float o2Ratio = 1 - o1Ratio;

	vector2 v1 = o1->getVelocity();
	vector2 v2 = o2->getVelocity();

	// Determine velocities
	o1->setVelocity(
		v1 * ((o1->getMass() - o2->getMass()) / (totalMass)) +
		v2 * ((2 * o2->getMass()) / totalMass));
	o2->setVelocity(
		v2 * ((o2->getMass() - o1->getMass()) / (totalMass)) +
		v1 * ((2 * o1->getMass()) / totalMass));

	// Move objects out of each other
	o1->setPosition(o1->getPosition() + (*penetration) * o1Ratio);
	o2->setPosition(o2->getPosition() + (*penetration) * o2Ratio);
}

/* 
	These exist because it might be possible to take shortcuts in calculations of
	basic objects like circles and non-rotated rectangles

	|||
	vvv
*/
void collisionHandler::resolveCollision(circle *o1, circle *o2, vector2 *penetration)
{
	resolveCollision(o1, o2, penetration);
}

void collisionHandler::resolveCollision(circle *o1, polygon *o2, vector2 *penetration)
{
	resolveCollision(o1, o2, penetration);
}

void collisionHandler::resolveCollision(polygon *o1, circle *o2, vector2 *penetration)
{
	resolveCollision(o1, o2, penetration);
}

void collisionHandler::resolveCollision(polygon *o1, polygon *o2, vector2 *penetration)
{
	resolveCollision(o1, o2, penetration);
}