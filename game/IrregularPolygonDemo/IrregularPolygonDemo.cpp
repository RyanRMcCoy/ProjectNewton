#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"
#include "../../../../engine/engine/polygon.h"

#include <iostream>
#include <vector>

int main()
{
	bool hasStarted = false;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Irregular Polygon Demo");

	engine physics = engine();
	int refreshRate = 120;

	bool reverse = false;

	vector2 pointsArray[] = {
		vector2(0, 0),
		vector2(200, 0),
		vector2(185, 75),
		vector2(150, 150),
		vector2(0, 200),
		vector2(-50, 100)
	};

	vector2 pointsArray2[] = {
		vector2(700, 0),
		vector2(800, 0),
		vector2(800, 100)
	};

	vector2 pointsArray3[] = {
		vector2(0, 500),
		vector2(0, 600),
		vector2(100, 600)
	};

	vector2 pointsArray4[] = {
		vector2(700, 600),
		vector2(800, 500),
		vector2(800, 600)
	};

	sf::CircleShape object1(50);
	object1.setFillColor(sf::Color::Red);
	object1.setPosition(0, 0);

	sf::ConvexShape object2;
	object2.setFillColor(sf::Color::Blue);
	object2.setPointCount(6);
	object2.setPoint(0, sf::Vector2f(0, 0));
	object2.setPoint(1, sf::Vector2f(200, 0));
	object2.setPoint(2, sf::Vector2f(185, 75));
	object2.setPoint(3, sf::Vector2f(150, 150));
	object2.setPoint(4, sf::Vector2f(0, 200));
	object2.setPoint(5, sf::Vector2f(-50, 100));
	object2.setPosition(325, 200);

	sf::ConvexShape object3;
	object3.setFillColor(sf::Color::Green);
	object3.setPointCount(3);
	object3.setPoint(0, sf::Vector2f(700, 0));
	object3.setPoint(1, sf::Vector2f(805, -5));
	object3.setPoint(2, sf::Vector2f(800, 100));
	object3.setPosition(0, 0);

	sf::ConvexShape object4;
	object4.setFillColor(sf::Color::Green);
	object4.setPointCount(3);
	object4.setPoint(0, sf::Vector2f(0, 500));
	object4.setPoint(1, sf::Vector2f(0, 600));
	object4.setPoint(2, sf::Vector2f(100, 600));
	object4.setPosition(0, 0);

	sf::ConvexShape object5;
	object5.setFillColor(sf::Color::Green);
	object5.setPointCount(3);
	object5.setPoint(0, sf::Vector2f(700, 600));
	object5.setPoint(1, sf::Vector2f(800, 500));
	object5.setPoint(2, sf::Vector2f(800, 600));
	object5.setPosition(0, 0);

	circle o1 = circle(50, vector2(50, 50));
	//o1.setVelocity(vector2(250, 0));
	o1.setElasticity(2);

	polygon o2 = polygon(6, pointsArray, vector2(325, 200));
	o2.setMass(100.f);
	o2.setAnchored(true);
	o2.setElasticity(1);

	polygon o3 = polygon(3, pointsArray2, vector2(0, 0));
	o3.setMass(100.f);
	o3.setAnchored(true);
	o3.setElasticity(2);

	polygon o4 = polygon(3, pointsArray3, vector2(0, 0));
	o4.setMass(100.f);
	o4.setAnchored(true);
	o4.setElasticity(2);

	polygon o5 = polygon(3, pointsArray4, vector2(0, 0));
	o5.setMass(100.f);
	o5.setAnchored(true);
	o5.setElasticity(2);

	physics.addCircle(o1);
	physics.addPolygon(o2);
	physics.addPolygon(o3);
	physics.addPolygon(o4);
	physics.addPolygon(o5);

	rectangle left = rectangle(100, 600);
	left.setPosition(vector2(-50, 300));
	left.setAnchored(true);
	left.setElasticity(.8);

	rectangle right = rectangle(100, 600);
	right.setPosition(vector2(850, 300));
	right.setAnchored(true);
	right.setElasticity(.8);

	rectangle top = rectangle(800, 100);
	top.setPosition(vector2(400, -50));
	top.setAnchored(true);
	top.setElasticity(.8);

	rectangle bottom = rectangle(800, 100);
	bottom.setPosition(vector2(400, 650));
	bottom.setAnchored(true);
	bottom.setElasticity(.8);

	physics.addPolygon(right);
	physics.addPolygon(left);
	physics.addPolygon(top);
	physics.addPolygon(bottom);

	force f1 = force(&o1, vector2(0, 1920) * o1.getMass());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(object1);
		window.draw(object2);
		window.draw(object3);
		window.draw(object4);
		window.draw(object5);
		window.display();

		if (hasStarted)
		{
			if (physics.update(refreshRate))
			{
				if (o2.getPosition().getY() > 250)
					reverse = true;
				else if (o2.getPosition().getY() < 150)
					reverse = false;

				if (!reverse)
					o2.setPosition(o2.getPosition() + vector2(0, .5));
				else
					o2.setPosition(o2.getPosition() - vector2(0, .5));

				object1.setPosition(o1.getXpos() - o1.getRadius(), o1.getYpos() - o1.getRadius());
				object2.setPosition(o2.getXpos(), o2.getYpos());
				object3.setPosition(o3.getXpos(), o3.getYpos());
				object4.setPosition(o4.getXpos(), o4.getYpos());
				object5.setPosition(o5.getXpos(), o5.getYpos());
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			hasStarted = true;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			o1.setPosition(vector2(50, 50));
			o1.setVelocity(vector2());
			hasStarted = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
	}
	
	return 0;
}