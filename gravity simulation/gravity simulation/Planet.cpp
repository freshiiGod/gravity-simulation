#include <SFML/Graphics.hpp>
#include <cmath>
#include "Planet.h"

Planet::Planet(double radius, sf::Vector2f position, int32_t randomColorSeed)
{
	planet.setPosition(position);
	planet.setOrigin(sf::Vector2f(radius, radius));
	planet.setRadius(radius);
	mass = 50;

	srand(randomColorSeed);
	//random color planet
	int r = std::rand() % 80 + 200;
	int g = std::rand() % 80 + 200;
	int b = std::rand() % 80 + 200;
	sf::Color planetColor(r,g,b);
	planet.setFillColor(planetColor);
}
Planet::~Planet(){}

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

void Planet::updateVelocity(Planet otherPlanet)
{
	const double gravityConst = 6.673;
	//get distance with a^2 + b^2 = c^2
	double aSquared = pow(otherPlanet.getShape().getPosition().y - planet.getPosition().y, 2);
	double bSquared = pow(otherPlanet.getShape().getPosition().x - planet.getPosition().x, 2);
	double distance = std::sqrt(aSquared + bSquared);

	velocity = (gravityConst * mass * otherPlanet.getMass()) / (distance * distance);
}

//movement
void Planet::moveYUp()
{
	planet.move(0, -velocity);
}

void Planet::moveYDown()
{
	planet.move(0, velocity);
}

void Planet::moveXLeft()
{
	planet.move(-velocity, 0);
}

void Planet::moveXRight()
{
	planet.move(velocity, 0);
}

void Planet::setCollidedTrue()
{
	collided = true;
}

bool Planet::hasCollided()
{
	return collided;
}

double Planet::getMass()
{
	return mass;
}

sf::CircleShape Planet::getShape()
{
	return planet;
}