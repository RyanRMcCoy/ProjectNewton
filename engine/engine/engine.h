///-------------------------------------------------/
///	Class: engine
///
///	Purpose: This class provides instantiation of an
///		engine object whose purpose is to provide an
///		interface to access the physics engine by
///-------------------------------------------------/

#pragma once

#include <vector>
#include "satHandler.h"
#include "collisionHandler.h"
#include "physicalObject.h"
#include "circle.h"
#include "polygon.h"

class engine
{
private:
	/// Variable: lastUpdate
	/// Purpose: Used to calculate time deltas between each
	///		step in the simulation
	float lastUpdate;

	/// Variable: circles
	/// Purpose: Stores a collection of circle objects to be
	///		simulated via the engine.
	vector<circle*> circles;
	
	/// Variable: polygons
	/// Purpose: Stores a collection of polygon objects to be
	///		simulated via the engine.
	vector<polygon*> polygons;

	/// Variable: collisionDetector
	/// Purpose: Implements an satHandler object for collision
	///		detection.
	satHandler collisionDetector;

	/// Variable: collisionResolver
	/// Purpose: Implements a collisionHandler object for 
	///		collision resolution.
	collisionHandler collisionResolver;

public:
	engine();

	/// Function: addCircle
	/// Purpose: Adds a circle object to the circles vector
	void addCircle(circle &o);

	/// Function: addPolygon
	/// Purpose: Adds a polygon object to the polygon vector
	void addPolygon(polygon &o);

	/// Function: getCircles
	/// Purpose: Returns a pointer to the vector of circles
	vector<circle*> getCircles();

	/// Function: getPolygons
	/// Purpose: Returns a pointer to the vector of polygons
	vector<polygon*> getPolygons();

	/// Function: removeCircle
	/// Purpose: Searches for and removes the circle from the circles vector
	void removeCircle(circle &o);

	/// Function: removePolygon
	/// Purpose: Searches for and removes the polygon from the polygons vector
	void removePolygon(polygon &o);

	/// Function: update
	/// Purpose: Refreshes or 'steps' the simulation by calculating
	///		a time delta using the lastUpdate variable
	bool update(int);
};