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

	sf::RenderWindow window(sf::VideoMode(800, 600), "Force", sf::Style::Default);

	// Create instance of engine
	engine physics = engine();

	// Adding circles to the engine
	circle o1 = circle(100.f);
	o1.setVelocity(vector2(0, 0));
	o1.setAcceleration(vector2(0, 0));
	o1.setMass(1000.f);

	physics.addCircle(o1);

	// Drawing initial circles on window

	// Circle 1
	sf::CircleShape object1(o1.getRadius());
	object1.setFillColor(sf::Color::Red);
	o1.setPosition(vector2(400, 300));
	object1.setPosition(o1.getXpos(), o1.getYpos());

	// Drawing background
	sf::RectangleShape background(sf::Vector2f(800, 600));
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

		window.clear();
		window.draw(background);
		window.draw(object1);
		window.display();

		// If o1 is out of screen, wrap it around
		vector2 o1Pos = o1.getPosition();
		if (o1Pos.getX() > 800 + o1.getRadius())
			o1.setPosition(vector2(-o1.getRadius() * 2, o1Pos.getY()));
		else if (o1Pos.getX() < -o1.getRadius() * 2)
			o1.setPosition(vector2(800 + o1.getRadius(), o1Pos.getY()));

		if (o1Pos.getY() > 600 + o1.getRadius())
			o1.setPosition(vector2(o1Pos.getX(), -o1.getRadius() * 2));
		else if (o1Pos.getY() < -o1.getRadius() * 2)
			o1.setPosition(vector2(o1Pos.getX(), 600 + o1.getRadius()));

		// Applying force to the circle when wasd is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			force downForce = force(&o1, vector2(0, 960));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			force upForce = force(&o1, vector2(0, -960));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			force downForce = force(&o1, vector2(-960, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			force downForce = force(&o1, vector2(960, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}