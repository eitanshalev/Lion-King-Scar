#pragma once
#include "Gift.h"
#include "Globals.h"


class LifeGift : public Gift
{

public:
	LifeGift(sf::Vector2f location, giftType gt, bool soundOn)
		:Gift(location, gt) 
	{
		if (soundOn)
			m_sound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_gift));
	}

	~LifeGift() = default;
};