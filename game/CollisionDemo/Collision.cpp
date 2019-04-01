#include <SFML/Graphics.hpp>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Collision", sf::Style::Fullscreen);

	engine physics = engine();
	physics.addCircle(100.f);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

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

		window.clear();
		window.draw(background);
		window.draw(shape);
		window.display();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}