#include <SFML/Graphics.hpp>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Collision", sf::Style::Default);

	// Create instance of engine
	engine physics = engine();
	// Adding circles to the engine
	circle o1 = circle(100.f);
	circle o2 = circle(100.f);
	vector2 vectorHolder = vector2();
	physics.addCircle(o1);
	physics.addCircle(o2);

	// Drawing initial circles on window
		//Circle 1
	sf::CircleShape object1(o1.getRadius());
	object1.setFillColor(sf::Color::Red);
	vectorHolder = vector2(50., 200.);
	o1.setPosition(vectorHolder);
	object1.setPosition(o1.getXpos(), o1.getYpos());

		//Circle2
	sf::CircleShape object2(o2.getRadius());
	object2.setFillColor(sf::Color::Blue);
	vectorHolder = vector2(550., 200.);
	o2.setPosition(vectorHolder);
	object2.setPosition(o2.getXpos(), o2.getYpos());

	// Drawing background
	sf::RectangleShape background(sf::Vector2f(800, 600));
	background.setFillColor(sf::Color::Green);

	bool hasStarted = false;

	force o1Force = force(o1, vectorHolder);
	force o2Force = force(o2, vectorHolder);

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
			
		}

		window.clear();
		window.draw(background);
		window.draw(object1);
		window.draw(object2);
		window.display();

		// Waiting for 'S' to be pressed before starting demo
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			hasStarted = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}