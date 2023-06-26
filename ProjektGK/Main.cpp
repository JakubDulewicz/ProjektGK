#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Ball.h"
int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(desktop.width - 800, desktop.height - 200), "Arkanoid");

    // Utw�rz platform�
    Platform platform(&window,150.0f, 20.0f, 0.1f);
    platform.setPosition(window.getSize().x / 2.0f, window.getSize().y);


    // Utw�rz bloki
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
    //Utw�rz kontener na usuni�te bloki;
    std::vector<Block> deletedBlocks;

    //Utw�rz pi�k� 
    Ball ball(10.0f, 0.16f,&window,&platform,&blocks);
    ball.setPosition(window.getSize().x / 2.0f, window.getSize().y - platform.getHeight() * 1.5f - ball.getRadius());

    // G��wna p�tla gry
    while (window.isOpen())
    {
        // Sprawd� zdarzenia
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Poruszanie platform�
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            platform.moveLeft();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            platform.moveRight();
        }
        window.clear(sf::Color::Black);


        for (auto it = blocks.begin(); it != blocks.end();)
        {
            it->draw(window);
            if (it->getDestoryed())
            {
                deletedBlocks.push_back(*it);
                it = blocks.erase(it);
            }
            else
            {
                ++it;
            }
        }

        ball.update();
        if (deletedBlocks.size() > 0)
        {
            for (int i = 0; i < deletedBlocks.size(); i++)
            {
                if (deletedBlocks.at(i).getCollectable() != nullptr)
                {
                    deletedBlocks.at(i).getCollectable()->update();
                }
            }
        }
        platform.draw();
        ball.draw();
        if (deletedBlocks.size() > 0)
        {

            for (int i = 0; i < deletedBlocks.size(); i++)
            {
                if (deletedBlocks.at(i).getCollectable() != nullptr)
                {
                    deletedBlocks.at(i).getCollectable()->draw(window);
                }
              
            }
        }
        
        window.display();  
    }

    return 0;
}

   