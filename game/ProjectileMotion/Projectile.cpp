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

	//initilize circles in the engine
	circle circ1(50, vector2(0, 400 - 100));
	circle circ2(100, vector2(0, 980 - 200));

	//set the mass of the larger circle to be twice as much as the smaller circle
	circ1.setMass(5);
	circ2.setMass(10);

	//Initilize rectangles in the engine and set them not to move
	rectangle rect1(vector2(1920, 100), vector2(0, 980));
	rect1.setAnchored(true);
	rectangle rect2(vector2(1920, 100), vector2(0, 400));
	rect2.setAnchored(true);

	//add the objects to the engine
	physics.addCircle(circ1);
	physics.addCircle(circ2);
	physics.addPolygon(rect1);
	physics.addPolygon(rect2);

	//SFML Graphics Setup
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mass Demo", sf::Style::Fullscreen);
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

	//Initilize forces
	force circ1Force = force();
	force circ2Force = force();

	//Window loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//draw the objects 
		window.clear();
		window.draw(sky);
		window.draw(ground1);
		window.draw(ground2);
		window.draw(circle2);
		window.draw(circle1);
		window.display();

		// If ball is out of screen, wrap it around and reset
		int circ1X = circ1.getXpos();
		int circ2X = circ2.getXpos();
		if (circ1X > 1920 + circ1.getRadius()) {
			circ1.setPosition(vector2(0, 400 - 100));
			circle1.setPosition(0, 400 - 100);
			circ1.setVelocity(0, 0);
		}
		if (circ2X > 1920 + circ2.getRadius()) {
			circ2.setPosition(vector2(0, 980 - 200));
			circ2.setVelocity(0, 0);
			circle2.setPosition(0, 980 - 200);
		}
			

		//start the simulation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			running = true;
		}

		//reset the simulation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			circ1.setPosition(vector2(0, 400-100));
			circ2.setPosition(vector2(0, 980-200));

			circ1.setVelocity(0, 0);
			circ2.setVelocity(0, 0);
						
			circle1.setPosition(0, 400-100);
			circle2.setPosition(0, 980-200);
			
			running = false;
		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		/*If the simulation is started apply the same force to both 
		circles and update their graphics on screen*/
		if (running)
		{
			physics.update(120);
			circ1Force = force(&circ1, vector2(1, 0));
			circ2Force = force(&circ2, vector2(1, 0));
			circle1.setPosition(circ1.getXpos(), circ1.getYpos());
			circle2.setPosition(circ2.getXpos(), circ2.getYpos());
			physics.update(frameRate);
		}
	}

	return 0;
}