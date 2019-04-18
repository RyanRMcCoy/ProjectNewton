#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"

using namespace std;

int main()
{
	int refreshRate = 120;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Collision", sf::Style::Default);

	// Create instance of engine
	engine physics = engine();

	// Adding circles to the engine
	circle o1 = circle(100.f);
	o1.setVelocity(vector2(500, -400));
	o1.setAnchored(false);
	o1.setElasticity(.75);
	
	force f = force(&o1, vector2(0, 980) * o1.getMass());
	//o1.setAcceleration(vector2(0, 980));

	circle o2 = circle(100.f);
	o2.setVelocity(vector2(-400, -300));
	o2.setAcceleration(vector2(0, 980));
	o2.setAnchored(true);

	rectangle ground = rectangle(vector2(400, 100), vector2(400, 640));
	ground.setAnchored(true);

	//vector2 vertices[4] = {vector2(-400, -50), vector2(400, -50), vector2(400, 50), vector2(-400, 50)};
	//vector2 vertices[4] = { vector2(0, 550), vector2(800, 550), vector2(800, 650), vector2(0, 650) };
	//ground.setVertices(vertices);

	vector2 vectorHolder = vector2();

	physics.addCircle(o1);
	physics.addCircle(o2);
	physics.addPolygon(ground);

	// Drawing initial circles on window

	// Circle 1
	sf::CircleShape object1(o1.getRadius());
	object1.setFillColor(sf::Color::Red);
	vectorHolder = vector2(150, 300);
	o1.setPosition(vectorHolder);
	object1.setPosition(o1.getXpos() - o1.getRadius(), o1.getYpos() - o1.getRadius());

	// Circle2
	sf::CircleShape object2(o2.getRadius());
	object2.setFillColor(sf::Color::Blue);
	vectorHolder = vector2(650, 300);
	o2.setPosition(vectorHolder);
	object2.setPosition(o2.getXpos() - o1.getRadius(), o2.getYpos() - o1.getRadius());

	// Ground
	sf::RectangleShape object3(sf::Vector2f(400, 100));
	object3.setFillColor(sf::Color::Cyan);
	object3.setPosition(200, 590);

	// Drawing background
	sf::RectangleShape background(sf::Vector2f(800, 600));
	background.setFillColor(sf::Color::Green);

	bool hasStarted = false;

	//force o1Force = force(o1, vectorHolder);
	//force o2Force = force(o2, vectorHolder);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Using engine to update position
		if (hasStarted)
		{
			physics.update(refreshRate);
			object1.setPosition(o1.getXpos() - o1.getRadius(), o1.getYpos() - o1.getRadius());
			object2.setPosition(o2.getXpos() - o2.getRadius(), o2.getYpos() - o2.getRadius());
			object3.setPosition(ground.getXpos() - ground.getSideX() / 2, ground.getYpos() - ground.getSideY() / 2);
		}

		window.clear();
		window.draw(background);
		window.draw(object1);
		window.draw(object2);
		window.draw(object3);
		window.display();

		// If o1 is out of screen, wrap it around
		/*
		vector2 o1Pos = o1.getPosition();
		if (o1Pos.getX() > 800 + o1.getRadius())
			o1.setPosition(vector2(-o1.getRadius(), o1Pos.getY()));
		else if (o1Pos.getX() < -o1.getRadius())
			o1.setPosition(vector2(800 + o1.getRadius(), o1Pos.getY()));

		if (o1Pos.getY() > 600 + o1.getRadius())
			o1.setPosition(vector2(o1Pos.getX(), -o1.getRadius()));
		else if (o1Pos.getY() < -o1.getRadius())
			o1.setPosition(vector2(o1Pos.getX(), 600 + o1.getRadius()));
		*/

		vector2 o1Pos = o1.getPosition();
		if (o1Pos.getX() > 800 - o1.getRadius())
		{
			o1.setPosition(vector2(800 - o1.getRadius(), o1Pos.getY()));
			o1.setVelocity(o1.getVelocity() * vector2(-1, 1));
		}
		else if (o1Pos.getX() < o1.getRadius())
		{
			o1.setPosition(vector2(o1.getRadius(), o1Pos.getY()));
			o1.setVelocity(o1.getVelocity() * vector2(-1, 1));
		}

		if (o1Pos.getY() > 600 - o1.getRadius())
		{
			o1.setPosition(vector2(o1Pos.getX(), 600 - o1.getRadius()));
			o1.setVelocity(o1.getVelocity() * vector2(1, -1));
		}
		else if (o1Pos.getY() < o1.getRadius())
		{
			o1.setPosition(vector2(o1Pos.getX(), o1.getRadius()));
			o1.setVelocity(o1.getVelocity() * vector2(1, -1));
		}

		vector2 o2Pos = o2.getPosition();
		if (o2Pos.getX() > 800 + o2.getRadius())
			o2.setPosition(vector2(-o2.getRadius() * 2, o2Pos.getY()));
		else if (o2Pos.getX() < -o2.getRadius() * 2)
			o2.setPosition(vector2(800 + o2.getRadius(), o2Pos.getY()));

		if (o2Pos.getY() > 600 + o2.getRadius())
			o2.setPosition(vector2(o2Pos.getX(), -o2.getRadius() * 2));
		else if (o2Pos.getY() < -o2.getRadius() * 2)
			o2.setPosition(vector2(o2Pos.getX(), 600 + o2.getRadius()));

		// Waiting for 'S' to be pressed before starting demo
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			hasStarted = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			o1.setPosition(vector2(50, 200));
			o1.setVelocity(vector2(rand() % 1000 + 500, rand() % 800 - 800));
			o2.setPosition(vector2(650, 300));
			o2.setVelocity(vector2(-400, -300));
			hasStarted = false;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}