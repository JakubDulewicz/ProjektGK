#pragma once
#include "Collectable.h"
#include "Block.h"
void spawnCollectableFromBlockVectorAddTItToCollectableVectorAndEraseBlock(std::vector<Block>& blocks, std::vector<Collectable*>& collectables);