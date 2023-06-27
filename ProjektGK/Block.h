#pragma once

#include <SFML/Graphics.hpp>
#include<vector>
#include "Collectable.h"


class Block
{
private:
    sf::RectangleShape shape;
    bool destroyed;

public:
    Block(float x, float y, float width, float height);
    ~Block();
    void draw(sf::RenderWindow& window);
    Collectable* spawnCollectable();
    void setDestroyed(bool value);
    bool getDestoryed() const;
    sf::FloatRect getBounds() const;
};