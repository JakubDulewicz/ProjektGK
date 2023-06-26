#pragma once
#include "SFML/Graphics.hpp"
class Collectable
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

public:
    Collectable(float radius, float x, float y, float velocityY);
    void update();
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

};