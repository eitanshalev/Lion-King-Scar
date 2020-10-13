#pragma once
#include "Gift.h"
#include "Globals.h"

class SunGift  : public Gift
{

public:
	SunGift(sf::Vector2f location , giftType gt, bool soundOn)
		:Gift(location,gt)
	{
		if (soundOn)
			m_sound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_gift));
		
	
	}
	
	~SunGift() = default;

	void handleCollision(Player& p) {}//this will help us define another mening to a gift - that should not be deleted
};