#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Friction Demo!");

	// Initialize the physics engine
	engine physics = engine();
	int refresh = 120;

	// Initialize the objects in the engine
	rectangle boxPhysics = rectangle(vector2(100, 100), vector2(150, 500));
	boxPhysics.setVelocity(100, 0);
	boxPhysics.setFriction(1);

	rectangle groundPhysics = rectangle(vector2(1000, 50), vector2(400, 600));
	groundPhysics.setAnchored(true);
	groundPhysics.setFriction(1);

	// Adding objects to the physics engine
	physics.addPolygon(boxPhysics);
	physics.addPolygon(groundPhysics);

	// sfml graphics for ground
	sf::RectangleShape ground(sf::Vector2f(groundPhysics.getSideX(), groundPhysics.getSideY()));
	ground.setPosition(groundPhysics.getXpos() - groundPhysics.getSideX() / 2, groundPhysics.getYpos() - groundPhysics.getSideY() / 2);
	ground.setFillColor(sf::Color::Green);

	//sfml graphics for box
	sf::RectangleShape box(sf::Vector2f(boxPhysics.getSideX(), boxPhysics.getSideY()));
	box.setPosition(boxPhysics.getXpos() - boxPhysics.getSideX() / 2, boxPhysics.getYpos() - boxPhysics.getSideY() / 2);
	box.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Updating engine and applying gravity to boxPhysics
		physics.update(refresh);
		force gravity = force(&boxPhysics, vector2(0, 5000));

		// Wrap around for boxPhysics
		if (boxPhysics.getXpos() - boxPhysics.getSideX() / 2 > 800) {
			boxPhysics.setPosition(vector2(150, 500));
		}

		// Updating SFML Objects
		box.setPosition(boxPhysics.getXpos() - boxPhysics.getSideX() / 2, boxPhysics.getYpos() - boxPhysics.getSideY() / 2);

		// Drawing objects
		window.clear();
		window.draw(box);
		window.draw(ground);
		window.display();

		// Push the box to the right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			//force push = force(&boxPhysics, vector2(100, 0));
		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}