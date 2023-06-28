#include"Game.h"
Game::Game()
{
    this->desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(desktop.width - 800, desktop.height - 200), "Arkanoid");
    this->deltaTime = clock.restart();
}

void Game::spawnCollectableFromBlockVectorAddTItToCollectableVectorAndEraseBlock(std::vector<Block>& blocks, std::vector<Collectable>& collectables)
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
                blocks.erase(blocks.begin() + i);
                i--;
            }
           
        }
}

void Game::processEvent(Platform& platform)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Poruszanie platform¹
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        platform.moveLeft(deltaTime);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        platform.moveRight(deltaTime);
    }
}

void Game::updateAll(Ball& ball, Platform& platform, std::vector<Block>& blocks,std::vector<Collectable>& collectables)
{
    ball.update(window, platform, blocks,deltaTime);
    updateCollectables(collectables);
}

void Game::drawALL(Ball& ball, Platform& platform, std::vector<Block>& blocks, std::vector<Collectable>& collectables)
{
    ball.draw(window);
    platform.draw();
    drawBlocks(blocks);
    drawCollectable(collectables);
}

void Game::updateCollectables(std::vector<Collectable>& collectables)
{
    for (int i = 0; i < collectables.size(); i++)
    {
        collectables.at(i).update();
    }
}

void Game::drawCollectable(std::vector<Collectable>& collectables)
{
    for (int i = 0; i < collectables.size(); i++)
    {
        collectables.at(i).draw(window);
    }
}

void Game::drawBlocks(std::vector<Block>& blocks)
{
    for (int i = 0; i < blocks.size(); i++)
    {
        blocks.at(i).draw(window);
    }
}

sf::RenderWindow& Game::getWindow()
{
    return window;
}

sf::Clock& Game::getClock()
{
    return clock;
}

sf::Time& Game::getDeltaTime()
{
    return deltaTime;
}

Game::~Game()
{
}