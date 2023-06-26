#pragma once
#include "SFML/Graphics.hpp"
class Platform
{
public:
	//Platform();
	Platform(sf::RenderWindow* window, float width, float height, float speed);
	~Platform();

	void moveLeft();
	void moveRight();
	void setPosition(float x, float y);
	void checkCollisionWithCollectable();
	void draw();

	float getHeight();
	float getWidth();
	float getSpeed();
	sf::RectangleShape getShape();


private:
	sf::RectangleShape shape;
	float speed;
	float width;
	float height;
	sf::RenderWindow* window;
};
