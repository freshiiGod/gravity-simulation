#pragma once
#ifndef PLANET_H
#define PLANET_H

class Planet
{
public:
	Planet(double radius, sf::Vector2f position, int32_t randomColorSeed);
	sf::CircleShape getShape();
private:
	double mass;
	sf::CircleShape planet;
};

#endif