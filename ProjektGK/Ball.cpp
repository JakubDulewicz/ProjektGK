#pragma once
#include "ball.h"

Ball::Ball(sf::RenderWindow* window, float radius, float speed)
{
    this->radius = radius;
    this->speed = speed;
    this->window = window;

    shape.setRadius(radius);
    shape.setFillColor(sf::Color::White);
    velocity = sf::Vector2f(0.0f, -speed);
}

void Ball::update()
{
    shape.move(velocity);
}

void Ball::draw()
{
    window->draw(shape);
}

void Ball::setPosition(float x, float y)
{
    shape.setPosition(x, y);
}

float Ball::getRadius() const
{
    return shape.getRadius();
}