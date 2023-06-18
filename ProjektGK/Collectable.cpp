#include "collectable.h"

Collectable::Collectable(float radius, float x, float y, float velocityY)
{
    shape.setRadius(radius);
    shape.setPosition(x, y);
    velocity.x = 0.0f;
    velocity.y = velocityY;
    shape.setFillColor(sf::Color::Blue);
}

void Collectable::update()
{
    shape.move(velocity);
}

void Collectable::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::FloatRect Collectable::getBounds() const
{
    return shape.getGlobalBounds();
}