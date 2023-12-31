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

void Platform::moveLeft(sf::Time& deltaTime)
{
	shape.move(-speed * deltaTime.asSeconds(), 0.0f);
	if (shape.getPosition().x < 0)
		shape.setPosition(0, shape.getPosition().y);
}
void Platform::moveRight(sf::Time& deltaTime)
{
	shape.move(speed * deltaTime.asSeconds(), 0.0f);
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
void Platform::IncreasePlatformLenghtForPeriodOfTime(sf::Time durationTime)
{

	if (powerUpTimer.getElapsedTime() < durationTime)
	{
		shape.setSize(sf::Vector2f((width + width), shape.getSize().y));
	}
	else
	{
		shape.setSize(sf::Vector2f((width), shape.getSize().y));
	}

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

sf::Clock& Platform::getClock()
{
	return powerUpTimer;
}
