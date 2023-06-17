#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    
    float speed;
    float radius;

    sf::RenderWindow* window;

public:
    Ball(sf::RenderWindow* window, float radius, float speed);
    void update();
    void draw();
    void setPosition(float x, float y);
    float getRadius() const;
};