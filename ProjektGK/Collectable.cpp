#include "collectable.h"
#include <random>

bool Collectable::getIsCollected()
{
    return isCollected;
}

Collectable::Collectable(float radius, float x, float y, float velocityY)
{
    shape.setRadius(radius);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Blue);
    velocity.x = 0.0f;
    velocity.y = velocityY;
    
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,3);
    
    powerUp = static_cast<PowerUp>(dis(gen));
    isCollected = false;
}

void Collectable::checkCollisionWithPlatform(Platform& platform)
{
    sf::FloatRect collectableBounds = shape.getGlobalBounds();
    sf::FloatRect platformBounds = platform.getShape().getGlobalBounds();
    if (collectableBounds.intersects(platformBounds))
    {
        isCollected = true;
    }
}

void Collectable::update()
{
    if (!isCollected)
    {
        shape.move(velocity);
    }
}


void Collectable::draw(sf::RenderWindow& window)
{
    if (!isCollected)
    {
        window.draw(shape);
    }
    
}

sf::FloatRect Collectable::getBounds() const
{
    return shape.getGlobalBounds();
}