#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h";
#include "Block.h"
#include <vector>
class Ball
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    
    
    float speed;
    float radius;

    sf::RenderWindow* window;
    Platform* platform;
    std::vector<Block>* blocks;
public:
    Ball(float radius, float speed, sf::RenderWindow* window, Platform* platform, std::vector<Block>* blocks);
    void update();
    void draw();
    void setPosition(float x, float y);
    void checkCollisionWithWindow();
    void checkCollisionWithPlatform();
    void checkCollisionWithBlocks();

    float getRadius() const;
    std::vector<Block>* getBlocks();
};