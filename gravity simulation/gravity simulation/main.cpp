#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Planet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Gravity", sf::Style::Close);

	//clock for seeding random planet color
	sf::Clock clock;

	//holds number of planets to decide planet array length
	int numberOfPlanets{ 0 };
	std::vector<Planet> planets;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
				break;
			}
			//creating new planets
			if (event.type == event.MouseButtonPressed)
			{
				numberOfPlanets++;

				//create new planet object and copy into planets vector
				Planet newPlanet(40,
					sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y),
					clock.getElapsedTime().asMilliseconds());

				planets.push_back(newPlanet);
			}
		}

		//loop through each existing planet
		for (int i{ 0 }; i < numberOfPlanets; i++)
		{
			//loop through each planet except current planet
			//checking things in respect to current planet
			for (int j{ 0 }; j < numberOfPlanets; j++)
			{
				if (j != i)
				{
					//update planets position based on it's velocity
					planets[i].updateVelocity(planets[j]);
					if (planets[i].getShape().getPosition().y > planets[j].getShape().getPosition().y)
						planets[i].moveYUp();
					if (planets[i].getShape().getPosition().y < planets[j].getShape().getPosition().y)
						planets[i].moveYDown();
					if (planets[i].getShape().getPosition().x > planets[j].getShape().getPosition().x)
						planets[i].moveXLeft();
					if (planets[i].getShape().getPosition().x < planets[j].getShape().getPosition().x)
						planets[i].moveXRight();

					//if planets are colliding, mark them to be destroyed
					if (planets[i].checkCollision(planets[j]))
					{
						planets[i].setCollidedTrue();
						planets[j].setCollidedTrue();
					}
				}
			}
		}

		//destroy marked planets
		for (int i = 0; i < numberOfPlanets; i++)
		{
			if (planets[i].hasCollided())
			{
				planets.erase(planets.begin() + i);
				numberOfPlanets--;
			}
		}

		system("cls");

		std::cout << numberOfPlanets << std::endl;

		//clear window with black color
		window.clear(sf::Color::Black);

		//select what to draw: window.draw(...)
		//loop through planet vector drawing all existing planets
		for (int i{ 0 }; i < numberOfPlanets; i++)
			window.draw(planets[i].getShape());

		//actually draw objects
		window.display();
	}

	return 0;
}