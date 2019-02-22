#pragma once
#include <array>
#include "pch.h"

class physicalObject {
private:
	std::array <float, 2> position, velocity, acceleration;
public:
	physicalObject(float x, float y);

	float getXpos ();
	float getYpos ();
	float getXvel ();
	float getYvel ();
	float getXacc ();
	float getYacc ();

	float setXpos (float x);
	float setYpos (float y);
	float setXvel (float x);
	float setYvel (float y);
	float setXacc (float x);
	float setYacc (float y);
};