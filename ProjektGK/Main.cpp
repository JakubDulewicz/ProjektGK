#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Ball.h"
int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(desktop.width - 800, desktop.height - 200), "Arkanoid");

    // Utwórz platformê
    Platform platform(&window,150.0f, 20.0f, 0.1f);
    platform.setPosition(window.getSize().x / 2.0f, window.getSize().y);

    std::vector<Block> blocks;
    float blockWidth = 60.0f;
    float blockHeight = 20.0f;
    int numBlocksX = 10;
    int numBlocksY = 4;

    for (int y = 0; y < numBlocksY; y++)
    {
        for (int x = 0; x < numBlocksX; x++)
        {
            float posX = x * (blockWidth + 10.0f) + 30.0f;
            float posY = y * (blockHeight + 10.0f) + 30.0f;
            blocks.emplace_back(posX, posY, blockWidth, blockHeight);
        }
    }


    //Utwórz pi³kê 
    Ball ball(10.0f, 0.16f,&window,&platform,&blocks);
    ball.setPosition(window.getSize().x / 2.0f, window.getSize().y - platform.getHeight() * 1.5f - ball.getRadius());

    // G³ówna pêtla gry
    while (window.isOpen())
    {
        // SprawdŸ zdarzenia
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Poruszanie platform¹
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            platform.moveLeft();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            platform.moveRight();
        }

        ball.update();
        // Wyczyœæ ekran
        window.clear(sf::Color::Black);

        // Wyœwietl planszê

        // Narysuj platformê
        platform.draw();
        ball.draw();
        for (auto& block : blocks)
        {
            block.draw(window);
        }

        // Zakoñcz rysowanie
        window.display();
    }

    return 0;
}

   