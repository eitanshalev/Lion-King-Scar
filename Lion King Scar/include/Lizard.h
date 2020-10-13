#pragma once
#include "Movable.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include "Enemy.h"

class Player; // FOR HANDLE COLLISION
//-----------------------------------------------------------------
//			_______________Lizard_________________________
//		This Cass is one of the player's enemies
//		he is lizard - walking and spliting! 
//		NOT ATTAKING BUT CAN HURT YOU!
//-----------------------------------------------------------------

class Lizard : public Enemy {

public:
	Lizard(sf::Vector2f location);

	~Lizard() = default;

	void handleCollision(Player& player);
	virtual void handleCollision(StaticBlock& block) override
	{
		Movable::handleCollision(block);
	}
	virtual void handleCollision(SpecialBlock& block) override
	{
		Movable::handleCollision(block);
	}

private:
	float switchTime = 12;
};





