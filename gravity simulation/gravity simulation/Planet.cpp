#include <SFML/Graphics.hpp>
#include <cmath>
#include "Planet.h"

Planet::Planet(double radius, sf::Vector2f position, int32_t randomColorSeed)
{
	planet.setPosition(position);
	planet.setOrigin(sf::Vector2f(radius, radius));
	planet.setRadius(radius);
	mass = radius;

	srand(randomColorSeed);
	//random color planet
	int r = std::rand() % 80 + 200;
	int g = std::rand() % 80 + 200;
	int b = std::rand() % 80 + 200;
	sf::Color planetColor(r,g,b);
	planet.setFillColor(planetColor);
}

bool Planet::checkCollision(Planet otherPlanet)
{
	double aSquared = pow(otherPlanet.getShape().getPosition().y - planet.getPosition().y, 2);
	double bSquared = pow(otherPlanet.getShape().getPosition().x - planet.getPosition().x, 2);
	double distance = std::sqrt(aSquared + bSquared);

	if (distance < otherPlanet.getShape().getRadius() + planet.getRadius())
		return true;
	else
		return false;
}

sf::CircleShape Planet::getShape()
{
	return planet;
}