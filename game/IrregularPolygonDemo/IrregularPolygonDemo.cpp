#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"
#include "../../../../engine/engine/polygon.h"

#include <vector>

int main()
{
	bool hasStarted = false;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Irregular Polygon Demo");

	engine physics = engine();
	int refreshRate = 120;

	vector2 pointsArray[] = {
		vector2(0, 0),
		vector2(200, 0),
		vector2(185, 75),
		vector2(150, 150),
		vector2(0, 200),
		vector2(-50, 100)
	};

	sf::CircleShape object1(50);
	object1.setFillColor(sf::Color::Red);
	object1.setPosition(0, 0);

	sf::CircleShape object2(50);
	object2.setFillColor(sf::Color::Blue);
	object2.setPosition(700, 0);

	sf::ConvexShape ground;
	ground.setFillColor(sf::Color::Green);
	ground.setPointCount(6);
	ground.setPoint(0, sf::Vector2f(0, 0));
	ground.setPoint(1, sf::Vector2f(200, 0));
	ground.setPoint(2, sf::Vector2f(185, 75));
	ground.setPoint(3, sf::Vector2f(150, 150));
	ground.setPoint(4, sf::Vector2f(0, 200));
	ground.setPoint(5, sf::Vector2f(-50, 100));
	ground.setPosition(300, 200);

	circle o1 = circle(50, vector2(50, 50));
	o1.setVelocity(vector2(250, 0));
	o1.setElasticity(1);

	circle o2 = circle(50, vector2(750, 50));
	o2.setVelocity(vector2(-250, 0));
	o2.setElasticity(1);

	polygon o3 = polygon(6, pointsArray, vector2(300, 200));
	o3.setMass(100.f);
	o3.setAnchored(true);
	o3.setElasticity(1);

	physics.addCircle(o1);
	//physics.addCircle(o2);
	physics.addPolygon(o3);

	rectangle left = rectangle(100, 600);
	left.setPosition(vector2(-50, 300));
	left.setAnchored(true);
	left.setElasticity(1);

	rectangle right = rectangle(100, 600);
	right.setPosition(vector2(850, 300));
	right.setAnchored(true);
	right.setElasticity(1);

	rectangle top = rectangle(800, 100);
	top.setPosition(vector2(400, -50));
	top.setAnchored(true);
	top.setElasticity(1);

	rectangle bottom = rectangle(800, 100);
	bottom.setPosition(vector2(400, 650));
	bottom.setAnchored(true);
	bottom.setElasticity(1);

	physics.addPolygon(right);
	physics.addPolygon(left);
	physics.addPolygon(top);
	physics.addPolygon(bottom);

	force f1 = force(&o1, vector2(0, 1920) * o1.getMass());
	force f2 = force(&o2, vector2(0, 1920) * o1.getMass());
	force controlForce;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(ground);
		window.draw(object1);
		//window.draw(object2);
		window.display();

		if (hasStarted)
		{
			physics.update(refreshRate);
			object1.setPosition(o1.getXpos() - o1.getRadius(), o1.getYpos() - o1.getRadius());
			object2.setPosition(o2.getXpos() - o2.getRadius(), o2.getYpos() - o2.getRadius());
			ground.setPosition(o3.getXpos(), o3.getYpos());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			controlForce.remove();
			controlForce = force(&o1, vector2(0.f, -10.f) * o1.getMass());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			controlForce.remove();
			controlForce = force(&o1, vector2(-10.f, 0.f) * o1.getMass());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			controlForce.remove();
			controlForce = force(&o1, vector2(0.f, 10.f) * o1.getMass());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			controlForce.remove();
			controlForce = force(&o1, vector2(10.f, 0.f) * o1.getMass());
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