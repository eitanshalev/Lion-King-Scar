#pragma once
//#include "Movable.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include "Enemy.h"
#include "Animation.h"

class Player;
class Enemy;

class Hedgehog : public Enemy {
	
//-----------------------------------------------------------------
//			_______________Hedgehog_________________________
//		This Cass is one of the player's enemies
//		he is spiky one, DO NOT TOUCH HIM! :)
//		NOT ATTAKING BUT CAN HURT YOU!
//-----------------------------------------------------------------
public:
	Hedgehog(sf::Vector2f location);
	~Hedgehog() = default;
	virtual void update(float deltaTime) override
	{
		if (jumpClock.getElapsedTime().asSeconds() > jumpTime)
		{
			velocity.y = -sqrtf(2.0f * 1200.0f * JUMP_DISTANCE); //AMAZING! ISN'T IT? (BY YONA)
			jumpClock.restart();
		}
		Enemy::update(deltaTime);
	}
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

	
	float jumpTime = 1;
	bool canJump = true;
	sf::Clock jumpClock;
};

