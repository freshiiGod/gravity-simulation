#include <SFML/Graphics.hpp>
#include "Planet.h"

Planet::Planet(double size, sf::Vector2f position)
{
	planet.setPosition(position);
	planet.setRadius(size);
	mass = size * 2;

	//random color planet
	srand(std::time(nullptr));
	int r = std::rand() % 50 + 200;
	int g = std::rand() % 50 + 200;
	int b = std::rand() % 50 + 200;
	sf::Color planetColor(r,g,b);
	planet.setFillColor(planetColor);
}