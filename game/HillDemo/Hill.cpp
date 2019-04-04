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
	sf::RenderWindow window(sf::VideoMode(400, 400), "Hill Demo");
	
	engine physics = engine();

	//initilizing objects in the engine
	vector2 groundPoints[3] = { vector2(0, 400) ,  vector2(0, 1080), vector2(1920, 1080) };
	polygon groundPH = polygon(3, groundPoints);
	circle ballPH = circle(100.f, vector2(150, 150));
	ballPH.setVelocity(vector2(10, 0));
	ballPH.setAcceleration(vector2(0, 9.8));

	physics.addPolygon(groundPH);
	physics.addCircle(ballPH);

	//sfml graphics for ground
	sf::ConvexShape ground;
	ground.setFillColor(sf::Color::Green);
	ground.setPointCount(3);
	ground.setPoint(0, sf::Vector2f(0, 400));
	ground.setPoint(1, sf::Vector2f(0, 1080));
	ground.setPoint(2, sf::Vector2f(1920, 1080));

	//sfml graphics for sky
	sf::ConvexShape sky;
	sky.setFillColor(sf::Color::Cyan);
	sky.setPointCount(4);
	sky.setPoint(0, sf::Vector2f(0, 0));
	sky.setPoint(1, sf::Vector2f(1920, 0));
	sky.setPoint(2, sf::Vector2f(1920, 1080));
	sky.setPoint(3, sf::Vector2f(0, 400));

	//sfml graphics for ball
	sf::CircleShape ball(ballPH.getRadius());
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(ballPH.getXpos(), ballPH.getYpos());

	bool hasStarted = false;
	force ballForce = force(ballPH, vector2(0, 0));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		physics.update(60); // Refresh the engine

		window.clear();
		window.draw(ground);
		window.draw(sky);
		window.draw(ball);
		window.display();

		//start the simulation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			hasStarted = true;
			ballForce = vector2(0, 50);
		}

		if (hasStarted) {
			cout << ballPH.getVelocity().getX() << ", " << ballPH.getVelocity().getY() << endl;
			ball.setPosition(ballPH.getXpos(), ballPH.getYpos());
		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}