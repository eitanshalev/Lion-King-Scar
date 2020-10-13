#pragma once
#include "Gift.h"
#include "Globals.h"


class HealthGift : public Gift
{

public:
	HealthGift(sf::Vector2f location, giftType gt, bool soundOn)
		:Gift(location, gt) 
	{
		if (soundOn)
		m_sound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_gift));
			
		
	}

	~HealthGift() = default;
	
};