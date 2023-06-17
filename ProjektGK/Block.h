#pragma once

#include <SFML/Graphics.hpp>

class Block
{
private:
    sf::RectangleShape shape;
    bool destroyed;

public:
    Block(float x, float y, float width, float height);
    void draw(sf::RenderWindow& window);
    void setDestroyed(bool value);
    bool getDestoryed() const;
    sf::FloatRect getBounds() const;
};