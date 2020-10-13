#pragma once
#include "Movable.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"
//#include "World_Block.h"
#include "Player.h"
#include "Enemy.h"

class WorldBlock;
class Player;

//-----------------------------------------------------------------
//			_______________Vulture_________________________
//		This Cass is one of the player's enemies				
//		he is lizard - walking and spliting! 
//		can ATTAKING and fly!!! is defently CAN HURT YOU!
//-----------------------------------------------------------------
class Vulture : public Enemy
{
public:
	~Vulture() = default;
	void handleCollision(Player& player);
	virtual void update(float deltaTime) override;
	Vulture(sf::Vector2f location, bool& soundOn, int& difficulty);
	virtual void handleCollision(StaticBlock& block) override
	{
		Movable::handleCollision(block);
	}
	virtual void handleCollision(SpecialBlock& block) override
	{
		Movable::handleCollision(block);
	}

};