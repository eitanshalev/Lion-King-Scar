#pragma once
#include "World_Block.h"
#include "Globals.h"

class StaticBlock : public WorldBlock
{
public:
	StaticBlock(sf::Vector2f& location, block_type_t bt, int worldNum)
		: WorldBlock(location, bt, worldNum) {}
	~StaticBlock() = default;
};