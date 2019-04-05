#include <SFML/Graphics.hpp>
#include <vector>
#include "Planet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Gravity", sf::Style::Close);
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
			if (event.type == event.MouseButtonPressed)
			{
				//adding new planet so increase array size
				numberOfPlanets++;
				planets.resize(numberOfPlanets);

				Planet newPlanet(10, sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));

				planets[numberOfPlanets - 1] = newPlanet;
			}
		}
		//clear window with black color
		window.clear(sf::Color::Black);

		//select what to draw: window.draw(...)
		for (int i = 0; i < numberOfPlanets; i++)
		{
			window.display(planets[i].getShape());
		}

		//actually draw objects
		window.display();
	}

	return 0;
}