#include "pch.h"
#include "CollisionHandler.h"
#include <iostream>


collisionHandler::collisionHandler() {}

#define FRICTION_SPEED_THRESHHOLD 25

float min(float n1, float n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

// o2 is anchored, o1 is not
void anchoredResolve(physicalObject *o1, physicalObject *o2, vector2 *penetration, float dt)
{
	float friction = min(o1->getFriction(), o2->getFriction());
	float elasticity = min(o1->getElasticity(), o2->getElasticity());
	//force frictionalForce = force(o1, vector2(o1->getAcceleration().getX() * friction, o1->getAcceleration().getY() * friction));

	vector2 v1 = o1->getVelocity();

	//if (v1.magnitude() < 0)
		//frictionalForce.remove();

	// Determine velocities
	o1->setVelocity(o1->getVelocity() - penetration->unit() *
		(o1->getVelocity().dot(penetration->unit())) * 2);
	o1->setVelocity(o1->getVelocity() - o1->getVelocity().project(*penetration) * (1 - elasticity));

	// Determine velocities along collision axis to determine whether to apply friction
	float normalSpeed = o1->getVelocity().project(*penetration).magnitude(); // Speed along normal (penetration axis)
	vector2 norm = vector2(0, o1->getMass() * -1920).project(penetration->unit());
	if (normalSpeed < FRICTION_SPEED_THRESHHOLD)
	{
		o1->setVelocity(o1->getVelocity() - (o1->getVelocity() * (friction / 2)) * .1);
	}

	// Move objects out of each other
	o1->setPosition(o1->getPosition() + (*penetration));

	//frictionalForce.remove();
}

void resolve(physicalObject *o1, physicalObject *o2, vector2 *penetration, float dt)
{
	o1->setColliding(true);
	o2->setColliding(true);

	if (o2->getAnchored())
	{
		anchoredResolve(o1, o2, penetration, dt);
		return;
	}
	else if (o1->getAnchored())
	{
		anchoredResolve(o2, o1, penetration, dt);
		return;
	}

	float friction = min(o1->getFriction(), o2->getFriction());

	//force frictionalForceO1 = force(o1, vector2(o1->getAcceleration().getX() * friction, o1->getAcceleration().getY() *avgFriction));
	//force frictionalForceO2 = force(o2, vector2(o2->getAcceleration().getX() * friction, o2->getAcceleration().getY() *avgFriction));

	float totalMass = (o1->getMass() + o2->getMass());
	float o1Ratio = (o1->getVelocity() * o1->getMass()).magnitude() / 
		((o1->getVelocity() * o1->getMass()).magnitude() + (o2->getVelocity() * o2->getMass()).magnitude());
	float o2Ratio = 1 - o1Ratio;

	float totalMomentum = (o1->getMass() * o1->getVelocity().magnitude() +
		o1->getMass() * o1->getVelocity().magnitude());

	vector2 v1 = o1->getVelocity();
	vector2 v2 = o2->getVelocity();

	/*
	if (v1.magnitude() <= 0)
		frictionalForceO1.remove();
	if (v2.magnitude() <= 0)
		frictionalForceO2.remove();
	*/

	float p1 = (v1 * ((o1->getMass() - o2->getMass()) / (totalMass)) + v2 * ((2 * o2->getMass()) / totalMass)).magnitude() * o1->getMass();
	float p2 = totalMomentum - p1;

	p1 *= o1->getElasticity();
	p2 *= o2->getElasticity();

	// Determine velocities
	o1->setVelocity(
		v1 * ((o1->getMass() - o2->getMass()) / (totalMass)) +
		v2 * ((2 * o2->getMass()) / totalMass));
	o2->setVelocity(
		v2 * ((o2->getMass() - o1->getMass()) / (totalMass)) +
		v1 * ((2 * o1->getMass()) / totalMass));

	float normalSpeedO1 = o1->getVelocity().project(*penetration).magnitude(); // Speed along normal (penetration axis)
	vector2 normO1 = vector2(0, o1->getMass() * -1920).project(penetration->unit());
	float normalSpeedO2 = o2->getVelocity().project(*penetration).magnitude(); // Speed along normal (penetration axis)
	vector2 normO2 = vector2(0, o2->getMass() * -1920).project(penetration->unit());
	
	if (normalSpeedO1 > FRICTION_SPEED_THRESHHOLD || normalSpeedO2 > FRICTION_SPEED_THRESHHOLD)
	{
		o1->setVelocity(o1->getVelocity() - ((normO1 / o1->getMass()) * friction * dt));
		o2->setVelocity(o2->getVelocity() - ((normO2 / o2->getMass()) * friction * dt));
	}

	// Move objects out of each other
	cout << "Penetration: " << penetration->toString() << std::endl;
	cout << "o1Ratio: " << o1Ratio << endl;
	cout << "Current Position: " << o1->getPosition().toString() << endl;
	cout << "Resolution Position: " << (o1->getPosition() + (*penetration) * o1Ratio).toString() << endl;
	o1->setPosition(o1->getPosition() + (*penetration) * o1Ratio);
	o2->setPosition(o2->getPosition() + (*penetration) * o2Ratio);
	
	//frictionalForceO1.remove();
	//frictionalForceO2.remove();
}

/* 
	These exist because it might be possible to take shortcuts in calculations of
	basic objects like circles and non-rotated rectangles

	|||
	vvv
*/
void collisionHandler::resolveCollision(circle *o1, circle *o2, vector2 *penetration, float dt)
{
	resolve(o1, o2, penetration, dt);
}

void collisionHandler::resolveCollision(circle *o1, polygon *o2, vector2 *penetration, float dt)
{
	resolve(o1, o2, penetration, dt);
}

void collisionHandler::resolveCollision(polygon *o1, circle *o2, vector2 *penetration, float dt)
{
	resolve(o1, o2, penetration, dt);
}

void collisionHandler::resolveCollision(polygon *o1, polygon *o2, vector2 *penetration, float dt)
{
	resolve(o1, o2, penetration, dt);
}