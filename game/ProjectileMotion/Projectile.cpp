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

	circle circ1(50, vector2(0, 400-100));
	circle circ2(100, vector2(0, 980-200));

	//force f1 = force(circ1, vector2(20, 10));
	//force f2 = force(circ2, vector2(20, 10));
	circ1.setMass(5);
	circ2.setMass(10);
	

	rectangle rect1(vector2(1920, 100), vector2(0, 980));
	rect1.setAnchored(true);

	rectangle rect2(vector2(1920, 100), vector2(0, 400));
	rect2.setAnchored(true);

	physics.addCircle(circ1);
	physics.addCircle(circ2);
	physics.addPolygon(rect1);
	physics.addPolygon(rect2);

	sf::RenderWindow window(sf::VideoMode(600, 400), "Projectile Motion", sf::Style::Fullscreen);
	sf::CircleShape circle1(circ1.getRadius());
	sf::CircleShape circle2(circ2.getRadius());
	circle1.setFillColor(sf::Color::Red);
	circle2.setFillColor(sf::Color::Blue);
	circle1.setPosition(circ1.getXpos(), circ1.getYpos());
	circle2.setPosition(circ2.getXpos(), circ2.getYpos());

	sf::RectangleShape ground1(sf::Vector2f(1920, 100));
	ground1.setFillColor(sf::Color::Green);
	ground1.setPosition(0, 980);

	sf::RectangleShape ground2(sf::Vector2f(1920, 100));
	ground2.setFillColor(sf::Color::Green);
	ground2.setPosition(0, 400);
	
	sf::RectangleShape sky(sf::Vector2f(1920, 1080));
	sky.setFillColor(sf::Color::Cyan);

	force circ1Force = force(&circ1, vector2(300, 0));
	force circ2Force = force(&circ2, vector2(300, 0));

	//circ1.setAcceleration(0, 0);
	//circ2.setAcceleration(0, 0);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sky);
		window.draw(ground1);
		window.draw(ground2);
		window.draw(circle2);
		window.draw(circle1);
		window.display();

		//start the simulation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			running = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			circ1.setPosition(vector2(0, 400-100));
			circ2.setPosition(vector2(0, 980-200));
			
			circle1.setPosition(0, 400-100);
			circle2.setPosition(0, 980-200);
			
			running = false;
		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (running)
		{
			physics.update(120);
			circle1.setPosition(circ1.getXpos(), circ1.getYpos());
			circle2.setPosition(circ2.getXpos(), circ2.getYpos());
			physics.update(frameRate);
		}
	}

	return 0;
}