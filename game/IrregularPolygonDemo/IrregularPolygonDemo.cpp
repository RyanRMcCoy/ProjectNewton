#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"
#include "../../../../engine/engine/polygon.h"

#include <vector>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Irregular Polygon Demo");
	int points = 10;
	sf::VertexArray triangleStrip(sf::TriangleStrip, points);

	triangleStrip[0].position = sf::Vector2f(10.f, 10.f);
	triangleStrip[1].position = sf::Vector2f(10.f, 100.f);
	triangleStrip[2].position = sf::Vector2f(100.f, 10.f);
	triangleStrip[3].position = sf::Vector2f(100.f, 100.f);
	triangleStrip[4].position = sf::Vector2f(160.f, 50.f);
	triangleStrip[5].position = sf::Vector2f(160.f, 140.f);
	triangleStrip[6].position = sf::Vector2f(225.f, 50.f);
	triangleStrip[7].position = sf::Vector2f(225.f, 140.f);
	triangleStrip[8].position = sf::Vector2f(300.f, 90.f);
	triangleStrip[9].position = sf::Vector2f(300.f, 180.f);

	triangleStrip[0].color = sf::Color::Red;
	triangleStrip[1].color = sf::Color::Cyan;
	triangleStrip[2].color = sf::Color::Blue;
	triangleStrip[3].color = sf::Color::Green;
	triangleStrip[4].color = sf::Color::Magenta;
	triangleStrip[5].color = sf::Color::Red;
	triangleStrip[6].color = sf::Color::Red;
	triangleStrip[7].color = sf::Color::Red;
	triangleStrip[8].color = sf::Color::Red;
	triangleStrip[9].color = sf::Color::Red;

	engine physics = engine();
	int refreshRate = 120;

	vector2 pointsArray[] = {
		vector2(10.f, 10.f),
		vector2(10.f, 100.f),
		vector2(100.f, 10.f),
		vector2(100.f, 100.f),
		vector2(160.f, 50.f),
		vector2(160.f, 140.f),
		vector2(225.f, 50.f),
		vector2(225.f, 140.f),
		vector2(300.f, 90.f),
		vector2(300.f, 180.f)
	};

	polygon physicsObject = polygon(points, pointsArray, vector2(0, 0));
	physicsObject.setMass(100.f);
	physics.addPolygon(physicsObject);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		physics.update(refreshRate);
		vector2 *vertices = physicsObject.getVertices();

		for (int i = 0; i < (int)triangleStrip.getVertexCount(); ++i) {
			triangleStrip[i].position = sf::Vector2f(vertices[i].getX(), vertices[i].getY());
		}

		window.clear();
		window.draw(triangleStrip);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			force upForce = force(&physicsObject, vector2(0.f, -100.f));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			force leftForce = force(&physicsObject, vector2(-100.f, 0.f));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			force downForce = force(&physicsObject, vector2(0.f, 100.f));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			force rightForce = force(&physicsObject, vector2(100.f, 0.f));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}