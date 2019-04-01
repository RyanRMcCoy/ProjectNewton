#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hill Demo", sf::Style::Fullscreen);
	
	sf::ConvexShape ground;
	ground.setFillColor(sf::Color::Green);
	ground.setPointCount(3);
	ground.setPoint(0, sf::Vector2f(0, 400));
	ground.setPoint(1, sf::Vector2f(0, 1080));
	ground.setPoint(2, sf::Vector2f(1920, 1080));

	sf::ConvexShape sky;
	sky.setFillColor(sf::Color::Cyan);
	sky.setPointCount(4);
	sky.setPoint(0, sf::Vector2f(0, 0));
	sky.setPoint(1, sf::Vector2f(1920, 0));
	sky.setPoint(2, sf::Vector2f(1920, 1080));
	sky.setPoint(3, sf::Vector2f(0, 400));

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
		window.display();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}