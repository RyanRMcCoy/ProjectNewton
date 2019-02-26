#pragma once

class circle : public physicalObject
{
private: 
	float radius;
public:
	circle (float rad);
	float getRadius ();
	float setRadius (float rad);
};