#pragma once
#ifndef PLANET_H
#define PLANET_H

class Planet
{
public:
	Planet(double radius, sf::Vector2f position, int32_t randomColorSeed);
	bool checkCollision(Planet otherPlanet);
	sf::CircleShape getShape();
private:
	double mass;
	sf::CircleShape planet;
};

#endif