#pragma once
#include "SFML/Graphics.hpp"
class Platform
{
public:
	//Platform();
	Platform(sf::RenderWindow* window, float width, float height, float speed);
	~Platform();

	void moveLeft(sf::Time& deltaTime);
	void moveRight(sf::Time& deltaTime);
	void setPosition(float x, float y);
	void checkCollisionWithCollectable();
	void IncreasePlatformLenghtForPeriodOfTime(sf::Time durationTime);
	void SpawnShootingGuns(); // TO DO
	void draw();

	float getHeight();
	float getWidth();
	float getSpeed();
	sf::RectangleShape getShape();
	sf::Clock& getClock();


private:
	sf::RectangleShape shape;
	sf::RenderWindow* window;
	sf::Clock powerUpTimer;
	float speed;
	float width;
	float height;
	
};
