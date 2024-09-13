#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG GAME");

	//--------------------------------------------------- Skeleton/Enemy -----------------------------------------------------------

	sf::Texture enemyTexture;
	sf::Sprite enemySprite;

	if (enemyTexture.loadFromFile("assets/skeleton/textures/BODY_animation.png"))
	{
		std::cout << "Player image loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load" << std::endl;
	}

	enemySprite.setTexture(enemyTexture);
	enemySprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
	enemySprite.scale(3, 3);

	//--------------------------------------------------- Player -----------------------------------------------------------


	sf::Texture playerTexture;
	sf::Sprite playerSprtie;


	if (playerTexture.loadFromFile("assets/player/textures/BODY_animation.png"))
	{
		std::cout << "Player image loaded" << std::endl;
	}
	else
	{
		std::cout << "Failed to load" << std::endl;
	}
	playerSprtie.setTexture(playerTexture);
	playerSprtie.setTextureRect(sf::IntRect(0,128, 64, 64));
	playerSprtie.scale(3, 3);


	//--------------------------------------------------- Main game loop -----------------------------------------------------------


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			sf::Vector2f position = playerSprtie.getPosition();
			playerSprtie.setPosition(position + sf::Vector2f(1, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			sf::Vector2f position = playerSprtie.getPosition();
			playerSprtie.setPosition(position + sf::Vector2f(-1, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			sf::Vector2f position = playerSprtie.getPosition();
			playerSprtie.setPosition(position + sf::Vector2f(0, -1));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sf::Vector2f position = playerSprtie.getPosition();
			playerSprtie.setPosition(position + sf::Vector2f(0, 1));
		}




		window.clear(sf::Color::Blue); 
		window.draw(playerSprtie);
		window.draw(enemySprite);

		window.display();
	}

	return 0;
	
}