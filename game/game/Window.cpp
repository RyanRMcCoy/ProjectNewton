#include <SFML/Graphics.hpp>
#include <iostream>

#include <vector>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"

//engine physicsEngine = engine();

int main()
{
	//Set bounds for the window , sf::Style::Fullscreen
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sir Issac");

	//Set bounds and color for sky
	sf::RectangleShape sky(sf::Vector2f(1920.f, 880.f));
	sky.setFillColor(sf::Color::Cyan);

	//Set bounds and color for ground
	sf::RectangleShape ground(sf::Vector2f(1920.f, 300.f));
	ground.setFillColor(sf::Color::Green);
	ground.setPosition(0.f, 780.f);

	//Set position and color for sun
	sf::CircleShape sun(200.f);
	sun.setFillColor(sf::Color::Yellow);
	sun.setPosition(1700.f, -200.f);

	//Set the texture to the apple image
	sf::Texture textureApple;
	if (!textureApple.loadFromFile("img/apple.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}

	//Set the texture to the sprite
	sf::Sprite avatar;
	avatar.setTexture(textureApple);

	//Make the avatar smaller and start them on the far left
	avatar.setScale(.20f, .20f);
	avatar.setPosition(20.f, 700.f);



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
		window.draw(sun);
		window.draw(avatar);

		// Temp
			/*
			vector<circle> objects = physicsEngine.getCircles();
			for (circle o : objects)
			{
				vector2 pos = o.getPosition();
				sf::CircleShape object(10.f);
				object.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
				if (o.getCollisionFlag())
					object.setFillColor(sf::Color::Green);
				else
					object.setFillColor(sf::Color::Red);
				window.draw(object);
			}
			*/
			// Temp

		window.display();


		//move the avatar left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (avatar.getPosition().x <= 0)
			{
				avatar.move(0.f, 0.f);
			}
			else
			{
				avatar.move(-5.f, 0.f);
			}
		}


		//move the avatar right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (avatar.getPosition().x >= 1740)
			{
				avatar.move(0.f, 0.f);
			}
			else
			{
				avatar.move(5.f, 0.f);
			}
		}

		//move the avatar up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (avatar.getPosition().y <= 650.f)
			{
				avatar.move(0.f, 0.f);
			}
			else
			{
				avatar.move(0.f, -5.f);
			}
		}

		//move the avatar down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (avatar.getPosition().y >= 880)
			{
				avatar.move(0.f, 0.f);
			}
			else
			{
				avatar.move(0.f, 5.f);
			}
		}

		/*
		TO-DO
		Error Checking on diagonal movement
		Currently can go beyond the bounds
		*/

		//move diagonally up/right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (avatar.getPosition().y <= 650.f && avatar.getPosition().x >= 1740.f)
			{
				avatar.move(0.f, 0.f);
			}
			else if (avatar.getPosition().y <= 650.f)
			{
				avatar.move(5.f, 0.f);
			}
			else if (avatar.getPosition().x >= 1740.f)
			{
				avatar.move(0.f, -5.f);
			}
			else
			{
				avatar.move(2.f, -2.f);
			}
		}

		//move diagonally up/left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (avatar.getPosition().y <= 650.f && avatar.getPosition().x <= 0.f)
			{
				avatar.move(0.f, 0.f);
			}
			else if (avatar.getPosition().y <= 650.f)
			{
				avatar.move(-5.f, 0.f);
			}
			else if (avatar.getPosition().x <= 0.f)
			{
				avatar.move(0.f, -5.f);
			}
			else
			{
				avatar.move(-2.f, -2.f);
			}
		}

		//move diagonally down/right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (avatar.getPosition().y >= 800.f && avatar.getPosition().x >= 1740.f)
			{
				avatar.move(0.f, 0.f);
			}
			else if (avatar.getPosition().y >= 800.f)
			{
				avatar.move(5.f, 0.f);
			}
			else if (avatar.getPosition().x >= 1740.f)
			{
				avatar.move(0.f, 5.f);
			}
			else
			{
				avatar.move(2.f, 2.f);
			}
		}

		//move diagonally down/left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (avatar.getPosition().y >= 800.f && avatar.getPosition().x <= 0.f)
			{
				avatar.move(0.f, 0.f);
			}
			else if (avatar.getPosition().y >= 800.f)
			{
				avatar.move(-5.f, 0.f);
			}
			else if (avatar.getPosition().x <= 0.f)
			{
				avatar.move(0.f, 5.f);
			}
			else
			{
				avatar.move(-2.f, 2.f);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (!textureApple.loadFromFile("img/elon.png"))
			{
				std::cout << "Elon Failed" << std::endl;
				system("pause");
			}
			avatar.setTexture(textureApple);
		}

		//quit the window
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}