#include "block.h"

Block::Block(float x, float y, float width, float height)
{
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Green);
    destroyed = false;
}

void Block::draw(sf::RenderWindow& window)
{
    if (!destroyed)
        window.draw(shape);
}

void Block::setDestroyed(bool value)
{
    this->destroyed = value;
}

bool Block::getDestoryed() const
{
    return destroyed;
}

sf::FloatRect Block::getBounds() const
{
    return shape.getGlobalBounds();
}