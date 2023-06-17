#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h";
class Ball
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    
    float speed;
    float radius;

    sf::RenderWindow* window;
    Platform* platform;
public:
    Ball(float radius, float speed, sf::RenderWindow* window, Platform* platform);
    void update();
    void draw();
    void setPosition(float x, float y);
    void checkCollisionWithWindow();
    void checkCollisionWithPlatform();

    float getRadius() const;
};