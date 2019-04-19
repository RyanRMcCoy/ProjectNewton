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
		vector2(120, 40),
		vector2(200, 120),
		vector2(260, 200),
		vector2(240, 240),
		vector2(-20, 260),
	};

	sf::CircleShape object1(50);
	object1.setFillColor(sf::Color::Red);
	object1.setPosition(0, 0);

	sf::ConvexShape ground;
	ground.setFillColor(sf::Color::Green);
	ground.setPointCount(6);
	ground.setPoint(0, sf::Vector2f(0, 0));
	ground.setPoint(1, sf::Vector2f(120, 40));
	ground.setPoint(2, sf::Vector2f(200, 120));
	ground.setPoint(3, sf::Vector2f(260, 200));
	ground.setPoint(4, sf::Vector2f(240, 240));
	ground.setPoint(5, sf::Vector2f(-20, 260));
	ground.setPosition(50, 250);

	circle o1 = circle(50, vector2(50, 50));

	polygon o2 = polygon(6, pointsArray, vector2(50, 200));
	o2.setMass(100.f);
	o2.setAnchored(true);

	physics.addCircle(o1);
	physics.addPolygon(o2);

	force f = force(&o1, vector2(0, 1920) * o1.getMass());
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
		window.display();

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

		if (hasStarted)
		{
			physics.update(refreshRate);
			object1.setPosition(o1.getXpos() - o1.getRadius(), o1.getYpos() - o1.getRadius());
			ground.setPosition(o2.getXpos(), o2.getYpos());
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
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