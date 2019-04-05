#include <SFML/Graphics.hpp>
#include "Planet.h"

Planet::Planet(double radius, sf::Vector2f position, int32_t randomColorSeed)
{
	planet.setPosition(position);
	planet.setOrigin(sf::Vector2f(radius, radius));
	planet.setRadius(radius);
	mass = radius;

	srand(randomColorSeed);
	//random color planet
	int r = std::rand() % 200;
	int g = std::rand() % 200;
	int b = std::rand() % 200;
	sf::Color planetColor(r,g,b);
	planet.setFillColor(planetColor);
}

sf::CircleShape Planet::getShape()
{
	return planet;
}