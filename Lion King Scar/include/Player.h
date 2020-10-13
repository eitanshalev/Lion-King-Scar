#pragma once
 
#include "Globals.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Gift.h"
#include "Hyena.h"
#include "Hedgehog.h"
#include "Decoration.h"
#include "Movable.h"
#include "Vulture.h"


class Lizard;		//forward declatetion
class Hedgehog;		//forward declatetion
class Hyena;		//forward declatetion
class Gift;
class Decoration;
class Movable;
class WorldBlock;
class Vulture;

//-----------------------------------------------------------------
//			_______________Player________________________
//		This Cass is of our main caracter
//-----------------------------------------------------------------
class Player : public Movable {
public:

	
	Player(sf::Vector2f location, bool &soundOn);
	~Player() = default;
	virtual void update(float deltaTime) override;
	bool scarjumping() { return m_animation.isJumping(); }
	void handleCollision(Gift& gift);
	void handleCollision(Hedgehog&);
	void handleCollision(Decoration& decoration);
	void  handleCollision(Lizard& liz);
	virtual void handleCollision(Hyena& hyena);
	 void handleCollision(Vulture& vulture);
	void handlewithEnemy(float enemyX);
	void setHealth() { 	m_sprite.setPosition(getStartingLocation()); m_health = 5;}
	bool isAttacking() { return m_animation.isAttacking(); }

	bool isOut() { return (m_health == 0); }
	void showStats(sf::RenderWindow& window, sf::Vector2f viewCenter);
	bool finished() {  return m_finished;  }
	void checkLimits(const sf::Vector2f& viewSize);
	virtual void handleCollision(StaticBlock& block) override
	{
		Movable::handleCollision(block);
	}
	virtual void handleCollision(SpecialBlock& block) override
	{
		Movable::handleCollision(block);
	}
	void resetSpeed() {m_speed = PLAYER_SPEED;}
	void speedUp() { m_speed *= speedBonus; }
private:
	sf::Sound ouch;
	sf::Sound jump;
	sf::Sound failure;
	sf::Sprite m_data;
	sf::Text life_show ;
	sf::Sound attacking;
	sf::Sound giftSound;
	sf::Sprite m_healthBar;
	sf::Sound fallingSound;
	sf::Sound checkPointSound;
	sf::Vector2f m_newLocation;

	std::vector<sf::IntRect> m_dataFacerectVector = Resources::loadResources().getscarDataFace();
	std::vector<sf::IntRect> m_dataHealthBarrectVector = Resources::loadResources().getscarhealthBar();
	std::vector<sf::IntRect> m_scaragorheartedVector = Resources::loadResources().getScargotheartRect();

	int m_health = 5;
	float switchTime = 32;
	bool m_finished = false;
	float speedBonus = 1.07f;
	sf::Clock m_jumpingClock;
	bool switchDirection = false;	
};

