#pragma once
#include<vector>
#include"Block.h"
#include"Platform.h"
#include"Block.h"
#include"Collectable.h"
#include"Ball.h"

class Game
{
public:
	Game();
	void spawnCollectableFromBlockVectorAddTItToCollectableVectorAndEraseBlock(std::vector<Block>& blocks, std::vector<Collectable>& collectables);
	void processEvent(Platform& platform);
	void updateAll(Ball& ball, Platform& platform, std::vector<Block>& blocks,std::vector<Collectable>& collectables);
	void drawALL(Ball& ball, Platform& platform, std::vector<Block>& blocks, std::vector<Collectable>& collectables);
	void drawBlocks(std::vector<Block>& blocks);
	void updateCollectables(std::vector<Collectable>& collectables);
	void drawCollectable(std::vector<Collectable>& collectables);

	sf::RenderWindow& getWindow();
	sf::Clock& getClock();
	sf::Time& getDeltaTime();
	~Game();

private:
	sf::VideoMode desktop;
	sf::RenderWindow window;
	sf::Time deltaTime;
	sf::Clock clock;
};

