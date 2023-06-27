#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Ball.h"
#include "Game.h"


int main()
{
    Game game;
    Platform platform(&game.getWindow(), 150.0f, 20.0f, 0.1f);
    Ball ball(10.0f, 0.16f);
    std::vector<Collectable> collectables;

    platform.setPosition(game.getWindow().getSize().x / 2.0f, game.getWindow().getSize().y);
    ball.setPosition(game.getWindow().getSize().x / 2.0f, game.getWindow().getSize().y - platform.getHeight() * 1.5f - ball.getRadius());

    // Utwórz bloki
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

    while (game.getWindow().isOpen())
    {
        game.processEvent(platform);
        game.updateAll(ball, platform, blocks, collectables);
        game.spawnCollectableFromBlockVectorAddTItToCollectableVectorAndEraseBlock(blocks, collectables);
        game.getWindow().clear(sf::Color::Black);
        game.drawALL(ball, platform, blocks, collectables);
        game.getWindow().display();
    }

    return 0;
}
