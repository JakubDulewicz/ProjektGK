#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Ball.h"

void spawnCollectableFromBlockVectorAddTItToCollectableVectorAndEraseBlock(std::vector<Block>& blocks, std::vector<Collectable>& collectables)
{
    for (int i = 0; i < blocks.size(); i++)
    {
        if (blocks.at(i).getDestoryed() == true)
        {
           Collectable* collectable = blocks.at(i).spawnCollectable();
           if (collectable != nullptr)
           {
               collectables.push_back(*collectable);
               delete collectable;
           }
           blocks.erase(blocks.begin()+i);
        }
        else
        {
            i++;
        }
    }
}


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
    //Utw�rz kontener na obiekty collectable;
    std::vector<Collectable> collectables;

    //Utw�rz pi�k� 
    Ball ball(10.0f, 0.16f);
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
        spawnCollectableFromBlockVectorAddTItToCollectableVectorAndEraseBlock(blocks, collectables);
        //update blocks
        for (int i = 0; i < blocks.size(); i++)
        {
            blocks.at(i).draw(window);
        }
        //update collectable
        for (int i = 0; i < collectables.size(); i++)
        {
            collectables.at(i).update();
        }
        ball.update(window, platform, blocks);        
      
        platform.draw();
        ball.draw(window);
      
        for (int i = 0; i < collectables.size(); i++)
        {
            collectables.at(i).draw(window);
        }
       
        window.display();  
    }

    return 0;
}
