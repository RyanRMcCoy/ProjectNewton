#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//Set bounds for the window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sir Issac");

	//Set bounds and color for sky
	sf::RectangleShape sky(sf::Vector2f(1920.f, 540.f));
	sky.setFillColor(sf::Color::Cyan);

	//Set bounds and color for ground
	sf::RectangleShape ground(sf::Vector2f(1920.f, 540.f));
	ground.setFillColor(sf::Color::Green);
	ground.setPosition(0.f, 540.f);

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
	avatar.setPosition(20.f, 400.f);


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
		window.draw(ground);
		window.draw(sun);
		window.draw(avatar);
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
			if(avatar.getPosition().x >= 1740)
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
			if (avatar.getPosition().y <= 400.f)
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
			if (avatar.getPosition().y >= 800)
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
			avatar.move(3.f, -3.f);
		}

		//move diagonally up/left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			avatar.move(-3.f, -3.f);
		}

		//move diagonally down/right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			avatar.move(3.f, 3.f);
		}

		//move diagonally down/left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			avatar.move(-3.f, 3.f);
		}

		sf::Texture elon;
		if (!elon.loadFromFile("img/elon.png"))
		{
			std::cout << "Elon Failed" << std::endl;
			system("pause");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
									if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
										if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
											if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
												std::cout << "ELON" << std::endl;
												avatar.setTexture(elon);
											}

										}
									}
								}
							}
						}
					}
				}
			}
		}

		//quit the window
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}