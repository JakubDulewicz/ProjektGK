#include "block.h"
#include <random>
Block::Block(float x, float y, float width, float height)
{
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Green);
    destroyed = false;
}

Block::~Block()
{
}

void Block::draw(sf::RenderWindow& window)
{
    if (!destroyed)
    {
        window.draw(shape);
    }
}

Collectable* Block::spawnCollectable()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 99);

    int random = dist(gen);

    if (random < 50)
    {
        float x = shape.getPosition().x + shape.getSize().x / 2.0f;
        float y = shape.getPosition().y + shape.getSize().y / 2.0f;

        float collectableRadius = 10.0f;
        float collectableVelocityY = 0.1f;
        return new Collectable(collectableRadius, x, y, collectableVelocityY);

    }
    else
    {
        return nullptr;
    }
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