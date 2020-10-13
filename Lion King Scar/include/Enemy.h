#pragma once
#include "Globals.h"
#include "Movable.h"

class Movable;


//-----------------------------------------------------------------
//			_______________Enemy_________________________
//		This Cass control all about the Enemy's proccess, 
//		here we define which movement each one will be walking,
//		attaking, and exactly 'live' at our game!
//		thier appreance , place at game , and etc.
//		
//-----------------------------------------------------------------
class Enemy : public Movable
{
public:

	Enemy(sf::Vector2f location, float speed, sf::Texture* texture) ;// {}
	~Enemy() = default;
	virtual void update(float deltaTime) override;
	void checkPlayerLocation(const sf::Vector2f& playerLocation);
	virtual void animation(float deltaTime) override;
	void moveToPlayer();
	sf::Vector2f &getPlayerLocation() { return m_playerLocation; }
	bool isNearPlayer() { return nearPlayer; }
	void setSound(const sf::Sound& sound) { scar_is_around = sound; } 
	void playScarIsAround() { scar_is_around.play(); }
	
	private:
		bool m_dead = false;
		bool m_attacking = false;
		bool nearPlayer = false;
		sf::Sound scar_is_around;
		sf::Vector2f m_playerLocation;
		sf::Clock movingClock;
		sf::Clock standClock;
		float m_standingTime = 5.0f;
		float m_movingTime = 3.0f;
		bool isStanding = false;
		sf::Clock soundTime;
};