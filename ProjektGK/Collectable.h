#pragma once
#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "PowerUp.h"
class Collectable
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    PowerUp powerUp;
    bool isCollected;

    

    // Increase platform lenghth - on time period
    // Spawn new ball from current one
    // Shoot bullets from platform
    // Increase powerUp duration

public:
    Collectable(float radius, float x, float y, float velocityY);
    void checkCollisionWithPlatform(Platform& platform);
    void update();
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    bool getIsCollected();

};
