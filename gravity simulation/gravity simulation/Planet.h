#pragma once
#ifndef PLANET_H
#define PLANET_H

class Planet
{
public:
	Planet(double radius, sf::Vector2f position, int32_t randomColorSeed);
	~Planet();
	bool checkCollision(Planet otherPlanet);
	void updateVelocity(Planet otherPlanet);

	void setCollidedTrue();
	bool hasCollided();

	//planet movement
	void moveYUp();
	void moveYDown();
	void moveXLeft();
	void moveXRight();

	sf::CircleShape getShape();
	double getMass();
private:
	bool collided{ false };
	double velocity;
	double mass;
	sf::CircleShape planet;
};

#endif