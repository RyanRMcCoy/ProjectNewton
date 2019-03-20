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

		window.clear();
		window.draw(sky);
		window.draw(ground);
		window.draw(sun);
		window.draw(avatar);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			avatar.move(-1.f, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			avatar.move(1.f, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			avatar.move(0.f, -1.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			avatar.move(0.f, 1.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}