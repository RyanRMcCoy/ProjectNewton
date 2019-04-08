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
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hill Demo");
	
	engine physics = engine();

	//initilizing objects in the engine
	vector2 groundPoints[3] = {vector2(0, 400) , vector2(0, 1080), vector2(1920, 1080)};
	polygon groundPH = polygon(3, groundPoints, vector2(0, -275));
	groundPH.setAnchored(true);

	rectangle boxPH = rectangle(vector2(50, 1600), vector2(1000, 590));
	boxPH.setAnchored(false);

	circle ballPH = circle(100.F, vector2(150, 150));
	ballPH.setVelocity(vector2(0, 100));
	ballPH.setAcceleration(vector2(0, 1920));
	// ballPH.setAnchored(true);

	physics.addPolygon(groundPH);
	//physics.addPolygon(boxPH);
	physics.addCircle(ballPH);

	// sfml graphics for ground
	sf::ConvexShape ground;
	ground.setFillColor(sf::Color::Green);
	ground.setPointCount(3);
	ground.setPoint(0, sf::Vector2f(0, 400));
	ground.setPoint(1, sf::Vector2f(0, 1080));
	ground.setPoint(2, sf::Vector2f(1920, 1080));

	//sfml graphics for box
	sf::RectangleShape box(sf::Vector2f(50, 800));
	box.setPosition(sf::Vector2f(1000-25, 500-400));
	box.setFillColor(sf::Color::Green);

	//sfml graphics for sky
	sf::RectangleShape sky(sf::Vector2f(1920, 1080));
	sky.setFillColor(sf::Color::Cyan);

	//sfml graphics for ball
	sf::CircleShape ball(ballPH.getRadius());
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(ballPH.getXpos(), ballPH.getYpos());

	bool hasStarted = false;
	//force ballForce = force(ballPH, vector2(0, 0));

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
		window.draw(ground);
		//window.draw(box);
		window.draw(ball);
		window.display();

		// If ball is out of screen, wrap it around
		vector2 ballPos = ballPH.getPosition();
		if (ballPos.getX() > 1920 + ballPH.getRadius())
			ballPH.setPosition(vector2(-ballPH.getRadius() * 2, ballPos.getY()));
		else if (ballPos.getX() < -ballPH.getRadius() * 2)
			ballPH.setPosition(vector2(1920 + ballPH.getRadius(), ballPos.getY()));

		if (ballPos.getY() > 1080 + ballPH.getRadius())
			ballPH.setPosition(vector2(ballPos.getX(), -ballPH.getRadius() * 2));
		else if (ballPos.getY() < -ballPH.getRadius() * 2)
			ballPH.setPosition(vector2(ballPos.getX(), 1080 + ballPH.getRadius()));

		//start the simulation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			hasStarted = true;
			//ballForce = vector2(0, 50);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			ballPH.setPosition(vector2(150, 150));
			ballPH.setVelocity(vector2(0, 100));
			hasStarted = false;
		}

		if (hasStarted) {
			physics.update(120); // Refresh the engine
			ball.setPosition(ballPH.getXpos(), ballPH.getYpos());
			box.setPosition(boxPH.getXpos(), boxPH.getYpos());
			ground.setPosition(groundPH.getXpos(), groundPH.getYpos() + 275);
		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}