#include <SFML/Graphics.hpp>
#include <iostream>

#include <vector>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"



int main()
{
	engine physicsEngine = engine();

	//Set bounds for the window , sf::Style::Fullscreen
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hill");

	//Set bounds and color for sky
	sf::RectangleShape sky(sf::Vector2f(1920.f, 880.f));
	sky.setFillColor(sf::Color::White);

	//Set bounds and color for ground
	rectangle groundEngine = rectangle(1920.f, 300.f);
	vector2 groundVector = vector2(0.f, 780.f);
	physicsEngine.addPolygon(groundEngine);
	sf::RectangleShape ground(sf::Vector2f(groundEngine.getSideX(), groundEngine.getSideY()));
	ground.setFillColor(sf::Color::Black);
	groundEngine.setPosition(groundVector);
	ground.setPosition(groundEngine.getXpos(), groundEngine.getYpos());





	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Enable VSync
		window.setVerticalSyncEnabled(true);

		//When a key is pressed, KeyPressed will only be true once
		window.setKeyRepeatEnabled(false);

		//draw the objects
		window.clear();
		window.draw(sky);
		window.draw(ground);

	}

	return 0;
}