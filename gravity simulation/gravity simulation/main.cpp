#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Planet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Gravity", sf::Style::Close);

	//clock for seeding random planet color
	sf::Clock clock;
	clock.getElapsedTime().asMilliseconds();

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
				Planet newPlanet(10,
					sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y),
					clock.getElapsedTime().asMilliseconds());

				planets.push_back(newPlanet);
			}
		}
		system("cls");
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