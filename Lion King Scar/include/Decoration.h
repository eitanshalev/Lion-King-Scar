#pragma once

#include "Globals.h"
#include "Resources.h"
#include "NonMovable.h"

//-----------------------------------------------------------------
//			_______________Decoration_________________________
//		This Cass control all about the Decoration thing, 
//		as this name hint - here we control withc decoration will be shown, 
//		thier appreance , place at game , and etc.
//		
//		due to the fact this class can use a Tample,  we did it like this way! 	
//-----------------------------------------------------------------
class Decoration : public NonMovable <decoration_type_t> {
public:
	Decoration(sf::Vector2f& location, decoration_type_t dt, int worldNum) : NonMovable(location, dt, worldNum) {
	

		m_sprite.setTexture(Resources::loadResources().getWorldTexture(worldNum));
		m_sprite.setTextureRect(Resources::loadResources().getDecoration(worldNum)[(int)dt]);
		location.y += 7;
		m_sprite.setPosition(location);
		m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.0f, m_sprite.getTextureRect().height/ 2.0f);
		setLocation(m_sprite.getPosition());

		int randomSide = rand() % 2;
		if (randomSide == 0)
			m_sprite.setScale(-1, 1);
		else m_sprite.setScale(1, 1);
	}

	~Decoration() = default;
	virtual void animation(float deltaTime) override {}
	virtual void move(float deltaTime) override {}

	private:
	
};