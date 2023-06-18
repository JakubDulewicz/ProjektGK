#pragma once
#include "ball.h"
#include "Platform.h"
#include <random>


Ball::Ball(float radius, float speed, sf::RenderWindow* window, Platform* platform, std::vector<Block>* blocks)
{
    this->radius = radius;
    this->speed = speed;
    this->window = window;
    this->platform = platform;
    this->blocks = blocks;

    shape.setRadius(radius);
    shape.setFillColor(sf::Color::White);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-speed, speed);
    velocity = sf::Vector2f(dis(gen), -speed);
}

void Ball::update()
{
    shape.move(velocity);
    checkCollisionWithWindow();
    checkCollisionWithPlatform();
    checkCollisionWithBlocks();
}

void Ball::draw()
{
    window->draw(shape);
}

void Ball::setPosition(float x, float y)
{
    shape.setPosition(x, y);
}

void Ball::checkCollisionWithWindow()
{
    sf::FloatRect ballBounds = shape.getGlobalBounds();
    sf::Vector2u windowSize = window->getSize();

    if (ballBounds.left <= 0 || ballBounds.left + ballBounds.width >= windowSize.x)
    {
        velocity.x = -velocity.x;
    }

    if (ballBounds.top <= 0)
    {
        velocity.y = -velocity.y;
    }
}

void Ball::checkCollisionWithPlatform()
{
    sf::FloatRect ballBounds = shape.getGlobalBounds();
    sf::FloatRect platformBounds = platform->getShape().getGlobalBounds();
 
    if (ballBounds.intersects(platformBounds))
    {
        velocity.y = -velocity.y;
    }
}

void Ball::checkCollisionWithBlocks()
{
    for (auto& block : *blocks)
    {
        if (!block.getDestoryed() && shape.getGlobalBounds().intersects(block.getBounds()))
        {
            velocity.y = -velocity.y;
            block.setDestroyed(true);
            block.spawnCollectable();
        }
    }
}

float Ball::getRadius() const
{
    return shape.getRadius();
}

std::vector<Block>* Ball::getBlocks()
{
    return this->blocks;
}
