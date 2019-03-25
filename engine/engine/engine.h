#pragma once

#include <vector>
#include "satHandler.h"
#include "physicalObject.h"
#include "circle.h"
#include "polygon.h"

class engine
{
private:
	float lastUpdate;

	vector<circle> circles;
	vector<polygon> polygons;
	satHandler collisionHandler;
public:
	engine();

	void addCircle(circle o);
	void addPolygon(polygon o);
	vector<circle> getCircles();
	vector<polygon> getPolygons();
	void update();
};