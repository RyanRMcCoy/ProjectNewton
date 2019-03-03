#pragma once

class polygon : public physicalObject
{
private:
	int sides;
	vector2 *vertices;
public:
	polygon();
	polygon(int s);
	polygon(int s, vector2 v[]);

	vector2* getVertices();
};