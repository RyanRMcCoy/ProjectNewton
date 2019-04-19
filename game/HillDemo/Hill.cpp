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
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hill Demo");
	
	engine physics = engine();

	//initilizing objects in the engine
	vector2 groundPoints[3] = {vector2(0, 200) , vector2(0, 600), vector2(800, 600)};
	polygon groundPH = polygon(3, groundPoints);
	groundPH.setAnchored(true);

	rectangle boxPH = rectangle(vector2(200, 250), vector2(400, 0));
	boxPH.setAnchored(true);

	rectangle box2PH = rectangle(vector2(100, 100), vector2(250, 100));
	box2PH.setAcceleration(vector2(0, 1920));
	//boxPH.setAnchored(true);

	circle ballPH = circle(100.F, vector2(100, 100));
	ballPH.setVelocity(vector2(100, 200));
	ballPH.setAcceleration(vector2(0, 1920));
	ballPH.setElasticity(.5);
	//ballPH.setAnchored(true);

	physics.addPolygon(groundPH);
	physics.addPolygon(boxPH);
	//physics.addPolygon(box2PH);
	physics.addCircle(ballPH);

	// sfml graphics for ground
	sf::ConvexShape ground;
	ground.setFillColor(sf::Color::Green);
	ground.setPointCount(3);
	ground.setPoint(0, sf::Vector2f(0, 200));
	ground.setPoint(1, sf::Vector2f(0, 600));
	ground.setPoint(2, sf::Vector2f(800, 600));

	//sfml graphics for box
	sf::RectangleShape box(sf::Vector2f(boxPH.getSideX(), boxPH.getSideY()));
	box.setPosition(boxPH.getXpos() - boxPH.getSideX() / 2, boxPH.getYpos() - boxPH.getSideY() / 2);
	box.setFillColor(sf::Color::Green);

	//sfml graphics for sky
	sf::RectangleShape sky(sf::Vector2f(800, 600));
	sky.setFillColor(sf::Color::Cyan);

	//sfml graphics for box2
	sf::RectangleShape box2(sf::Vector2f(box2PH.getSideX(), box2PH.getSideY()));
	box2.setPosition(box2PH.getXpos() - box2PH.getSideX() / 2, box2PH.getYpos() - box2PH.getSideY() / 2);
	box2.setFillColor(sf::Color::Red);

	//sfml graphics for ball
	sf::CircleShape ball(ballPH.getRadius());
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(ballPH.getXpos() - ballPH.getRadius(), ballPH.getYpos() - ballPH.getRadius());

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
		window.draw(box);
		window.draw(ground);
		window.draw(ball);
		//window.draw(box2);
		window.display();

		// If ball is out of screen, wrap it around
		vector2 ballPos = ballPH.getPosition();
		if (ballPos.getX() > 800 + ballPH.getRadius())
			ballPH.setPosition(vector2(-ballPH.getRadius(), 50));
		else if (ballPos.getX() < -ballPH.getRadius())
			ballPH.setPosition(vector2(800 + ballPH.getRadius(), ballPos.getY()));

		if (ballPos.getY() > 600 + ballPH.getRadius())
			ballPH.setPosition(vector2(ballPos.getX(), -ballPH.getRadius()));
		else if (ballPos.getY() < -ballPH.getRadius())
			ballPH.setPosition(vector2(ballPos.getX(), 600 + ballPH.getRadius()));

		// If box2 is out of screen, wrap around
		vector2 boxPos = box2PH.getPosition();
		if (boxPos.getX() > 800 + box2PH.getSideX() / 2)
			box2PH.setPosition(vector2(-box2PH.getSideX() / 2, boxPos.getY()));
		else if (boxPos.getX() < -box2PH.getSideX() / 2)
			box2PH.setPosition(vector2(800 + box2PH.getSideX() / 2, boxPos.getY()));

		if (boxPos.getY() > 600 + box2PH.getSideY() / 2)
			box2PH.setPosition(vector2(boxPos.getX(), -box2PH.getSideY() / 2));
		else if (boxPos.getY() < -box2PH.getSideY() / 2)
			box2PH.setPosition(vector2(boxPos.getX(), 600 + box2PH.getSideY() / 2));

		//start the simulation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			hasStarted = true;
			//ballForce = vector2(0, 50);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			box2PH.setPosition(vector2(250, 100));
			ballPH.setPosition(vector2(100, 100));
			ballPH.setVelocity(vector2(0, 100));
			hasStarted = false;
		}

		if (hasStarted) {
			physics.update(120); // Refresh the engine
			ball.setPosition(ballPH.getXpos() - ballPH.getRadius(), ballPH.getYpos() - ballPH.getRadius());
			box.setPosition(boxPH.getXpos() - boxPH.getSideX() / 2, boxPH.getYpos() - boxPH.getSideY() / 2);
			box2.setPosition(box2PH.getXpos() - box2PH.getSideX() / 2, box2PH.getYpos() - box2PH.getSideY() / 2);
		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}