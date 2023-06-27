#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Block.h"
#include <vector>
class Ball
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    
    
    float speed;
    float radius;

public:
    Ball(float radius, float speed);
    void update(sf::RenderWindow& window, Platform& platform, std::vector<Block>& blocks);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    void checkCollisionWithWindow(sf::RenderWindow& window);
    void checkCollisionWithPlatform(Platform& platform);
    void checkCollisionWithBlocks(std::vector<Block>& blocks);

    float getRadius() const;
};