#pragma once
#include "Gift.h"
#include "Globals.h"


//--------------------------------------------------
//   _______________CheckPointGift__________________
//-------------------------------------------------
class CheckPointGift  : public Gift
{

public:
	CheckPointGift(sf::Vector2f location , giftType gt, bool soundOn)
		:Gift(location,gt)
	{
		if (soundOn)
			m_sound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_check_point));
		
	
	}
	
	~CheckPointGift() = default;

	virtual void handleCollision(Player& p) override {}
};