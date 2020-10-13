#pragma once
#include "Globals.h"
#include "Resources.h"
#include "NonMovable.h"
 
//-----------------------------------------------------------------
//			_______________Vulture_________________________
//		This Cass is one of the player's enemies				
//		he is lizard - walking and spliting! 
//		can ATTAKING and fly!!! is defently CAN HURT YOU!
//-----------------------------------------------------------------
class WorldBlock : public NonMovable <block_type_t> {
public :
	WorldBlock(sf::Vector2f& location, block_type_t bt, int worldNum)
		:	NonMovable(location, bt, worldNum) {}
	~WorldBlock() = default;
	virtual void move(float deltaTime) override {}
	virtual void animation(float deltaTime) override {}
	

private:

};