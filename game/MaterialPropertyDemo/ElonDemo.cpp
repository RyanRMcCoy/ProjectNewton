#include <SFML/Graphics.hpp>

#include "../../../../engine/engine/engine.h"
#include "../../../../engine/engine/vector2.h"
#include "../../../../engine/engine/physicalObject.h"
#include "../../../../engine/engine/circle.h"
#include "../../../../engine/engine/force.h"

#include <iostream>
#include <deque>
#include <string>

void createPipe(engine *physicsEngine, deque<sf::RectangleShape*> *pipes, deque<rectangle*> *pipeConstraints,
	int pipeThickness, int lipThickness, int lipHeight, int gapSize, int groundHeight, int gapStart, 
	sf::Texture *pipeTexture, sf::Texture *pipeLipTexture, sf::Color overlayColor)
{
	rectangle *upper = new rectangle(vector2(pipeThickness, gapStart), 
		vector2(800 + pipeThickness / 2, gapStart / 2));
	rectangle *upperLip = new rectangle(vector2(pipeThickness + lipThickness, lipHeight), 
		vector2(upper->getXpos(), (upper->getYpos() + upper->getSideY() / 2) - lipHeight / 2));
	rectangle *lower = new rectangle(vector2(pipeThickness, 600 - groundHeight - gapStart - gapSize),
		vector2(800 + pipeThickness / 2, gapStart + gapSize + (600 - groundHeight - gapStart - gapSize) / 2));
	rectangle *lowerLip = new rectangle(vector2(pipeThickness + lipThickness, lipHeight),
		vector2(lower->getXpos(), (lower->getYpos() - lower->getSideY() / 2) + lipHeight / 2));

	upper->setAnchored(true);
	upper->setElasticity(.9);
	upperLip->setAnchored(true);
	upperLip->setElasticity(.9);
	lower->setAnchored(true);
	lower->setElasticity(.9);
	lowerLip->setAnchored(true);
	lowerLip->setElasticity(.9);

	sf::RectangleShape *sfUpper = new sf::RectangleShape(sf::Vector2f(upper->getSideX(), upper->getSideY()));
	sfUpper->setOrigin(upper->getSideX() / 2, upper->getSideY() / 2);
	sfUpper->setFillColor(overlayColor);
	sfUpper->setPosition(upper->getXpos(), upper->getYpos());
	sfUpper->setTexture(pipeTexture);
	sf::RectangleShape *sfUpperLip = new sf::RectangleShape(sf::Vector2f(upperLip->getSideX(), upperLip->getSideY()));
	sfUpperLip->setOrigin(upperLip->getSideX() / 2, upperLip->getSideY() / 2);
	sfUpperLip->setFillColor(overlayColor);
	sfUpperLip->setPosition(upperLip->getXpos(), upperLip->getYpos());
	sfUpperLip->setTexture(pipeLipTexture);
	sf::RectangleShape *sfLower = new sf::RectangleShape(sf::Vector2f(lower->getSideX(), lower->getSideY()));
	sfLower->setOrigin(lower->getSideX() / 2, lower->getSideY() / 2);
	sfLower->setFillColor(overlayColor);
	sfLower->setPosition(lower->getXpos(), lower->getYpos());
	sfLower->setTexture(pipeTexture);
	sf::RectangleShape *sfLowerLip = new sf::RectangleShape(sf::Vector2f(lowerLip->getSideX(), lowerLip->getSideY()));
	sfLowerLip->setOrigin(lowerLip->getSideX() / 2, lowerLip->getSideY() / 2);
	sfLowerLip->setFillColor(overlayColor);
	sfLowerLip->setPosition(lowerLip->getXpos(), lowerLip->getYpos());
	sfLowerLip->setTexture(pipeLipTexture);

	pipeConstraints->push_back(upper);
	pipeConstraints->push_back(upperLip);
	pipeConstraints->push_back(lower);
	pipeConstraints->push_back(lowerLip);
	pipes->push_back(sfUpper);
	pipes->push_back(sfUpperLip);
	pipes->push_back(sfLower);
	pipes->push_back(sfLowerLip);

	physicsEngine->addPolygon(*upper);
	physicsEngine->addPolygon(*upperLip);
	physicsEngine->addPolygon(*lower);
	physicsEngine->addPolygon(*lowerLip);
}

int main()
{
	// Initialization
	const int FRAME_RATE = 60;
	const double PIPE_SPEED = 5;
	const double PIPE_FREQUENCY = 1;
	const int GROUND_HEIGHT = 100;
	const int PIPE_THICKNESS = 100;
	const int LIP_THICKNESS = 15;
	const int LIP_HEIGHT = 50;
	const int GAP_SIZE = 180;
	const int PIPE_MARGIN = 60;
	const int JUMP_VELOCITY = 500;

	sf::RenderWindow window(sf::VideoMode(800, 600), "ELON");

	int score = 0;
	bool running = false, titleUp = false, alive = true, jumpKey = false;
	double frameCount = 0, lastPipe = 0;
	engine physicsEngine = engine();

	sf::Color overlayColor(255, 255, 255);

	deque<sf::RectangleShape*> *pipes = new deque<sf::RectangleShape*>;
	deque<rectangle*> *pipeConstraints = new deque<rectangle*>;

	// Load textures
	sf::Texture titleText, elonTexture, backgroundTexture, groundTexture, pipeTexture, pipeLipTexture;
	if (!titleText.loadFromFile("images/TitleText.png"))
		std::cout << "Texture Load Failed" << std::endl;
	if (!elonTexture.loadFromFile("images/ELON.png"))
		std::cout << "Texture Load Failed" << std::endl;
	if (!backgroundTexture.loadFromFile("images/background.png"))
		std::cout << "Texture Load Failed" << std::endl;
	if (!groundTexture.loadFromFile("images/ground.png"))
		std::cout << "Texture Load Failed" << std::endl;
	if (!pipeTexture.loadFromFile("images/pipe.png"))
		std::cout << "Texture Load Failed" << std::endl;
	if (!pipeLipTexture.loadFromFile("images/pipeLip.png"))
		std::cout << "Texture Load Failed" << std::endl;

	// Load font
	sf::Font flappyFont;
	if (!flappyFont.loadFromFile("font/FlappyBirdy.ttf"))
		std::cout << "Font Load Failed" << std::endl;

	// Set random seed
	srand(time(0));

	// Initialize engine objects
	circle elon(35, vector2(200, 300));
	elon.setElasticity(1);
	elon.setFriction(1);

	rectangle ground(vector2(1600, GROUND_HEIGHT), vector2(800, 600 - GROUND_HEIGHT / 2));
	ground.setAnchored(true);
	ground.setElasticity(.5);
	ground.setFriction(1);

	rectangle backWall(vector2(200, 600), vector2(-100, 300));
	backWall.setAnchored(true);
	backWall.setElasticity(.9);

	rectangle frontWall(vector2(200, 600), vector2(900, 300));
	frontWall.setAnchored(true);
	frontWall.setElasticity(.9);

	force elonGravity(&elon, vector2(0, 1920) * elon.getMass());

	// Add objects to engine
	physicsEngine.addCircle(elon);
	physicsEngine.addPolygon(ground);
	physicsEngine.addPolygon(backWall);
	physicsEngine.addPolygon(frontWall);

	// Create SFML objects
	sf::RectangleShape title(sf::Vector2f(235, 109));
	title.setPosition(300, 175);
	title.setScale(1.5, 1.5);
	title.setTexture(&titleText);

	sf::CircleShape elonImage(elon.getRadius());
	elonImage.setOrigin(elon.getRadius(), elon.getRadius());
	elonImage.setPosition(elon.getXpos(), elon.getYpos());
	elonImage.setTexture(&elonTexture);
	//elonImage.setFillColor(overlayColor);

	sf::RectangleShape background(sf::Vector2f(800, 600));
	background.setTexture(&backgroundTexture);
	background.setFillColor(overlayColor);

	sf::RectangleShape sfGround(sf::Vector2f(ground.getSideX(), GROUND_HEIGHT));
	sfGround.setOrigin(ground.getSideX() / 2, ground.getSideY() / 2);
	sfGround.setPosition(ground.getXpos(), ground.getYpos());
	sfGround.setTexture(&groundTexture);
	sfGround.setFillColor(overlayColor);

	sf::Text scoreText;
	scoreText.setFont(flappyFont);
	scoreText.setString("0");
	scoreText.setCharacterSize(128);
	scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
	scoreText.setPosition(400, 0);
	scoreText.setFillColor(sf::Color(255, 255, 255));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		scoreText.setString(std::to_string(score));
		scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
		scoreText.setPosition(400, 0);

		window.clear();
		window.draw(background);
		window.draw(elonImage);
		window.draw(title);
		window.draw(sfGround);
		for (sf::RectangleShape *pipe : *pipes)
		{
			window.draw(*pipe);
			//cout << pipe->getLocalBounds().height << endl;
		}
		window.draw(scoreText);
		window.display();

		if (title.getPosition().x > -500 && alive)
		{
			if (title.getPosition().y <= 170)
				titleUp = false;
			else if (title.getPosition().y >= 180)
				titleUp = true;

			//cout << titleUp << endl;
			if (titleUp)
				title.setPosition(title.getPosition() - sf::Vector2f(0, PIPE_SPEED / 400));
			else
				title.setPosition(title.getPosition() + sf::Vector2f(0, PIPE_SPEED / 400));
		}

		// Check if engine is running and if a frame has passed yet
		if (running && physicsEngine.update(FRAME_RATE))
		{
			double rotation = 70 * (1 - abs((elon.getVelocity().getY() - (JUMP_VELOCITY * 2)) / (JUMP_VELOCITY * 2))) + 30;
			elonImage.setRotation(rotation);
			if (elon.getPosition().getY() < -elon.getRadius())
			{
				elon.setPosition(vector2(elon.getXpos(), -elon.getRadius()));
				elon.setVelocity(0, 100);
			}
			elonImage.setPosition(elon.getXpos(), elon.getYpos());
			sfGround.setPosition(ground.getXpos(), ground.getYpos());

			if (alive && title.getPosition().x > -500)
				title.setPosition(title.getPosition() - sf::Vector2f(PIPE_SPEED, 0));

			frameCount++;
			double time = frameCount / FRAME_RATE;

			if (alive && elon.getColliding())
			{
				alive = false;
				if (ground.getColliding())
				{
					elon.setAnchored(true);
				}
				else
					elon.setVelocity(-750, elon.getVelocity().getY());
			}

			if (alive)
			{
				// Update positions of pipes
				for (int i = 0; i < pipeConstraints->size(); i++)
				{
					rectangle *constraint = (*pipeConstraints)[i];
					//std::cout << constraint->getPosition().toString() << std::endl;
					if (constraint->getXpos() >= -constraint->getSideX() / 2)
					{
						constraint->setPosition(constraint->getPosition() - vector2(PIPE_SPEED, 0));
						(*pipes)[i]->setPosition(constraint->getXpos(), constraint->getYpos());
					}
					else
					{
						physicsEngine.removePolygon(*(*pipeConstraints)[0]);
						pipeConstraints->pop_front();
						pipes->pop_front();
					}
				}

				ground.setPosition(ground.getPosition() - vector2(PIPE_SPEED, 0));
				if (ground.getPosition().getX() <= 0)
					ground.setPosition(vector2(ground.getSideX() / 2, ground.getYpos()));

				if (time - lastPipe > PIPE_FREQUENCY)
				{
					if (lastPipe >= 2 * PIPE_FREQUENCY)
						score++;
					lastPipe = time;
					createPipe(&physicsEngine, pipes, pipeConstraints, PIPE_THICKNESS,
						LIP_THICKNESS, LIP_HEIGHT, GAP_SIZE, GROUND_HEIGHT,
						(rand() % (600 - GAP_SIZE - GROUND_HEIGHT - PIPE_MARGIN * 2)) + PIPE_MARGIN,
						&pipeTexture, &pipeLipTexture, overlayColor);
				}
			}
		}

		// Jump functionality
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!running)
				running = true;
			if (!jumpKey && alive)
			{
				jumpKey = true;
				elon.setVelocity(0, -JUMP_VELOCITY);
			}
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jumpKey)
			jumpKey = false;

		// Restart
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			running = false;
			alive = true;

			// Reset images
			elon.setPosition(vector2(200, 300));
			elon.setVelocity(vector2());
			elon.setAnchored(false);
			elonImage.setPosition(elon.getXpos(), elon.getYpos());
			elonImage.setRotation(0);
			title.setPosition(300, 175);

			// Reset data
			frameCount = 0;
			lastPipe = 0;
			score = 0;

			for (int i = 0; i < pipeConstraints->size(); i++)
			{
				physicsEngine.removePolygon(*(*pipeConstraints)[0]);
				pipeConstraints->pop_front();
				pipes->pop_front();
			}
			
		}

		//close the window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	return 0;
}