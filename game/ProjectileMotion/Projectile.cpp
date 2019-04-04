#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Projectile Motion", sf::Style::Fullscreen);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	sf::RectangleShape ground(sf::Vector2f(1920, 300));
	ground.setFillColor(sf::Color::Green);
	ground.setPosition(0.f, 1080 - ground.getGlobalBounds().height);

	sf::RectangleShape sky(sf::Vector2f(1920, 1080 - ground.getGlobalBounds().height));
	sky.setFillColor(sf::Color::Cyan);

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
		window.draw(sky);
		//window.draw(text);
		//window.draw(shape);
		window.display();

		//start the simulation
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}