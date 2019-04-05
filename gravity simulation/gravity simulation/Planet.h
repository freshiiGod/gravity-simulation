#pragma once
#ifndef PLANET_H
#define PLANET_H

class Planet
{
public:
	Planet(double size, sf::Vector2f position);
	sf::CircleShape getShape();
private:
	double mass;
	sf::CircleShape planet;
};

#endif