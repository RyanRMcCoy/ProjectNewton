#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include <array>
#include "vector2.h"

using namespace std;

class physicalObject 
{
private:
	vector2 position, velocity, acceleration;
	bool colliding;
protected:
	float mass;
	float density;
	float mu;
	bool anchored;
public:
	physicalObject();
	physicalObject(vector2 position);
	physicalObject(vector2 position, vector2 velocity);
	physicalObject(vector2 position, vector2 velocity, vector2 acceleration);

	float getXpos();
	float getYpos();
	vector2 getPosition();
	float getXvel();
	float getYvel();
	vector2 getVelocity();
	float getXacc();
	float getYacc();
	vector2 getAcceleration();

	void setPosition(vector2 pos);
	void setPosition(float x, float y);
	void setVelocity(vector2 vel);
	void setVelocity(float x, float y);
	void setAcceleration(vector2 acc);
	void setAcceleration(float x, float y);

	float getMass();
	float getDensity();
	float getFriction();

	bool getAnchored();
	void setAnchored(bool);

	bool operator == (physicalObject o);
};

#endif // !PHYSICALOBJECT_H;