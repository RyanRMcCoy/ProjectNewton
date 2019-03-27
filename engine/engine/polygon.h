#pragma once

class polygon : public physicalObject
{
private:
	int sides;
	vector2 *vertices;
	vector2 *relativeVertices;
public:
	polygon();
	polygon(int s);
	polygon(int s, vector2 v[]);
	polygon(int s, vector2 v[], vector2 pos);

	void setPosition(vector2 pos);

	int numSides();
	vector2* getVertices();
};