#pragma once
#include <vector>
#include "Resources.h"
#include "Player.h"
#include "Enemy.h"
#include "Globals.h"

class Player;


class Hyena : public Enemy
{
public:
	Hyena(sf::Vector2f location, bool& soundOn, int& difficulty);
	~Hyena() = default;
	void handleCollision(Player& player);
	virtual void handleCollision(StaticBlock& block) override
	{
		Movable::handleCollision(block);
	}
	virtual void handleCollision(SpecialBlock& block) override
	{
		Movable::handleCollision(block);
	}

	

};