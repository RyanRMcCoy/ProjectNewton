#pragma once

class polygon : public physicalObject
{
private:
	int sides;
	vector2 *vertices;
	vector2 *relativeVertices;
	void setDefaultMat();
public:
	polygon();
	polygon(int s);
	polygon(int s, vector2 v[]);
	polygon(int s, vector2 v[], vector2 pos);

	void setPosition(vector2 pos);
	void setRotation(float rot);

	int numSides();
	vector2* getVertices();
	void setVertices(vector2 v[]);

	float getArea();

	float getMass();
	float setMass(float m);

	float getDensity();
	float setDensity(float d);

	void updateMass();
	void updateDensity();

	float getFriction();
	void  setFriction(float m);
};