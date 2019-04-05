#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"

using namespace std;

int main()
{
	engine physics = engine();
	int frameRate = 120;
	bool running = false;

	circle circ1(50, vector2(100, 100));
	circ1.setAcceleration(vector2(0, 1960));

	rectangle rect1(vector2(1920, 100), vector2(-960, 500));
	rect1.setAnchored(true);

	physics.addCircle(circ1);
	physics.addPolygon(rect1);

	sf::RenderWindow window(sf::VideoMode(200, 200), "Projectile Motion", sf::Style::Fullscreen);
	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Red);

	sf::RectangleShape ground(sf::Vector2f(1920, 100));
	ground.setFillColor(sf::Color::Green);
	ground.setPosition(0, 500);

	//sf::RectangleShape sky(sf::Vector2f(1920, 1080 - ground.getGlobalBounds().height));
	//sky.setFillColor(sf::Color::Cyan);

	/*
	sf::Text text;
	//text.setFont(font);
	text.setString("Press Space to Launch");
	text.setCharacterSize(20);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setPosition(400, 400);
	*/

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
		//window.draw(sky);
		//window.draw(text);
		window.draw(circle);
		window.display();

		//sfml graphics for ground
		sf::RectangleShape ground;
		ground.setFillColor(sf::Color::Green);

		//start the simulation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			running = true;
		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (running)
		{
			circle.setPosition(circ1.getXpos(), circ1.getYpos());
			physics.update(frameRate);
		}
	}

	return 0;
}