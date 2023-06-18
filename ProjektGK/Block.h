#pragma once

#include <SFML/Graphics.hpp>
#include "Collectable.h"

class Block
{
private:
    sf::RectangleShape shape;
    Collectable* collectable;
    bool destroyed;

public:
    Block(float x, float y, float width, float height);
    ~Block();
    void draw(sf::RenderWindow& window);
    void spawnCollectable();
    Collectable* getCollectable();
    void setDestroyed(bool value);
    bool getDestoryed() const;
    sf::FloatRect getBounds() const;
};