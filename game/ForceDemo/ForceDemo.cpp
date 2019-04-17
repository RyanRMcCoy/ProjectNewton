#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"

using namespace std;

int main()
{
	int refreshRate = 120;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Force", sf::Style::Fullscreen);

	// Create instance of engine
	engine physics = engine();

	// Adding circles to the engine
	circle o1 = circle(100.f);
	o1.setVelocity(vector2(0, 0));
	o1.setAcceleration(vector2(0, 0));
	o1.setMass(5.f);

	circle o2 = circle(100.f);
	o2.setVelocity(vector2(0, 0));
	o2.setAcceleration(vector2(0, 0));
	o2.setMass(5.f);

	rectangle left = rectangle(1, 10000, vector2(0, 0));
	rectangle right = rectangle(1, 10000, vector2(1920, 0));
	rectangle top = rectangle(192000, 1, vector2(0, 0));
	rectangle bottom = rectangle(192000, 1, vector2(0, 1080));

	left.setAnchored(true);
	right.setAnchored(true);
	top.setAnchored(true);
	bottom.setAnchored(true);

	physics.addCircle(o1);
	physics.addCircle(o2);
	physics.addPolygon(right);
	physics.addPolygon(left);
	physics.addPolygon(top);
	physics.addPolygon(bottom);

	// Drawing initial circles on window

	// Circle 1
	sf::CircleShape object1(o1.getRadius());
	object1.setFillColor(sf::Color::Red);
	o1.setPosition(vector2(400, 540));
	object1.setPosition(o1.getXpos(), o1.getYpos());

	//Circle 2
	sf::CircleShape object2(o2.getRadius());
	object2.setFillColor(sf::Color::Blue);
	o2.setPosition(vector2(1000, 540));
	object2.setPosition(o2.getXpos(), o2.getYpos());

	sf::RectangleShape leftDis(sf::Vector2f(left.getSideX(), left.getSideY()));
	leftDis.setPosition(left.getXpos() - left.getSideX() / 2, left.getYpos() - left.getSideY() / 2);
	leftDis.setFillColor(sf::Color::Magenta);
	

	// Drawing background
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	background.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		physics.update(refreshRate);
		object1.setPosition(o1.getXpos() - o1.getRadius(), o1.getYpos() - o1.getRadius());
		object2.setPosition(o2.getXpos() - o2.getRadius(), o2.getYpos() - o2.getRadius());

		window.clear();
		window.draw(background);
		window.draw(object1);
		window.draw(object2);
		window.display();

		// If o1 is out of screen, wrap it around
		vector2 o1Pos = o1.getPosition();
		if (o1Pos.getX() > 1920 + o1.getRadius())
			o1.setPosition(vector2(-o1.getRadius() * 2, o1Pos.getY()));
		else if (o1Pos.getX() < -o1.getRadius() * 2)
			o1.setPosition(vector2(1920 + o1.getRadius(), o1Pos.getY()));

		if (o1Pos.getY() > 1080 + o1.getRadius())
			o1.setPosition(vector2(o1Pos.getX(), -o1.getRadius() * 2));
		else if (o1Pos.getY() < -o1.getRadius() * 2)
			o1.setPosition(vector2(o1Pos.getX(), 1080 + o1.getRadius()));

		// If o1 is out of screen, wrap it around
		vector2 o2Pos = o2.getPosition();
		if (o2Pos.getX() > 1920 + o2.getRadius())
			o2.setPosition(vector2(-o2.getRadius() * 2, o2Pos.getY()));
		else if (o2Pos.getX() < -o2.getRadius() * 2)
			o2.setPosition(vector2(1920 + o2.getRadius(), o2Pos.getY()));

		if (o2Pos.getY() > 1080 + o2.getRadius())
			o2.setPosition(vector2(o2Pos.getX(), -o2.getRadius() * 2));
		else if (o2Pos.getY() < -o2.getRadius() * 2)
			o2.setPosition(vector2(o2Pos.getX(), 1080 + o2.getRadius()));

		int speed = 1000;

		// Applying force to the circle when wasd is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			force downForce1 = force(&o1, vector2(0, speed));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			force downForce2 = force(&o2, vector2(0, speed));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			force upForce1 = force(&o1, vector2(0, -speed));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			force upForce2 = force(&o2, vector2(0, -speed));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			force downForce1 = force(&o1, vector2(-speed, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			force downForce2 = force(&o2, vector2(-speed, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			force downForce1 = force(&o1, vector2(speed, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			force downForce2 = force(&o2, vector2(speed, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}