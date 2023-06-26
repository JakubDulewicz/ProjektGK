#include "SFML/Graphics.hpp"
#include "Platform.h"
//Platform::Platform(){}
Platform::Platform(sf::RenderWindow* window, float width, float height, float speed)
{
	this->speed = speed;
	this->height = height;
	this->width = width;
	this->window = window;
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color::White);
	shape.setPosition(350.0f, 580.0f);
	
}
Platform::~Platform(){}

void Platform::moveLeft()
{
	shape.move(-speed, 0.0f);
	if (shape.getPosition().x < 0)
		shape.setPosition(0, shape.getPosition().y);
}
void Platform::moveRight()
{
	shape.move(speed, 0.0f);
	if (shape.getPosition().x + shape.getSize().x > window->getSize().x)
		shape.setPosition(window->getSize().x - shape.getSize().x, shape.getPosition().y);
	
}
void Platform::setPosition(float x, float y)
{
	shape.setPosition(x, y - shape.getSize().y);
}
void Platform::checkCollisionWithCollectable()
{
	sf::FloatRect rectangleBound = shape.getGlobalBounds();
	
}
void Platform::draw()
{
	window->draw(shape);
}

float Platform::getHeight()
{
	return height;
}

float Platform::getWidth()
{
	return width;
}

float Platform::getSpeed()
{
	return speed;
}

sf::RectangleShape Platform::getShape()
{
	return shape;
}
