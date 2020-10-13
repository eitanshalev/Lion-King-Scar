#pragma once
#include "Globals.h"
#include "Resources.h"
#include "NonMovable.h"
#include "Player.h"

class Player; // for handel collision


//-----------------------------------------------------------------
//			_______________Gift_________________________
//		This Cass control all about the Gift's proccess, 
//		here we define which each one will be walking,
//		attaking, and exactly 'live' at our game!
//		thier appreance , place at game , and etc.
//		
//		this class is a template like decoration
//-----------------------------------------------------------------
class Gift : public NonMovable <giftType> {
public:

	Gift(sf::Vector2f& location, giftType gt);
	~Gift() = default;
	sf::Sound& getGiftSound() { return m_sound; }
	virtual void handleCollision(Player& p); 
	virtual void move(float deltaTime) override {}
	virtual void animation(float deltaTime) override;

protected:
	sf::Sound m_sound;

private:
	int bugType = 0;
	int lifeindex = 0,
	 endPointIndex = 0,
	checkPointIndex = 0;
	giftType m_animation;
	float switchTime = 32.5;
	std::vector<sf::IntRect> m_recthealing_Vector  = Resources::loadResources().getgiftshealing(),
		m_endPointVector = Resources::loadResources().getEndPoint(),
		m_rectlife_Vector = Resources::loadResources().getgiftsLife(),
		m_checkPointVector = Resources::loadResources().getCheckPoint();
};