#include "Gift.h"


Gift::Gift(sf::Vector2f& location, giftType gt) : NonMovable(location, gt, 0), m_animation(gt)
{
	sf::Sprite gift;
	gift.setTexture(Resources::loadResources().getgiftTextures());
	gift.setTextureRect((Resources::loadResources().getgiftsLife()[0]));
	bugType = rand() % m_recthealing_Vector.size();
	gift.setOrigin(gift.getTextureRect().width / 2.0f, gift.getTextureRect().height / 2.0f);
	gift.setPosition(location);
	m_sprite = gift;
	
}




void Gift::animation(float deltaTime)
{
	sf::IntRect newOrigin;	
	switch (m_animation)
	{
	case giftType::_healing:	
	
		m_sprite.setTextureRect(m_recthealing_Vector[bugType]);
		newOrigin = m_recthealing_Vector[bugType];
		break;
	case giftType::_Onelife:
		m_sprite.setTextureRect(m_rectlife_Vector[lifeindex]);
		newOrigin = m_rectlife_Vector[lifeindex];
		if (deltaTime >= switchTime)
			lifeindex++;
		
		if (lifeindex > m_rectlife_Vector.size() - 1)
			lifeindex = 0;
		
		break;
	case giftType::checkPoint:
		m_sprite.setTextureRect(m_checkPointVector[checkPointIndex]);
		newOrigin = m_checkPointVector[checkPointIndex];
		if (deltaTime >= switchTime + 1)
			checkPointIndex++;
		if (checkPointIndex > m_checkPointVector.size() - 1)	
			checkPointIndex = 0;
		break;
	case giftType::endPoint:
		m_sprite.setTextureRect(m_endPointVector[endPointIndex]);
		newOrigin = m_endPointVector[endPointIndex];
		if (deltaTime >= switchTime + 1)
			endPointIndex++;
		if (endPointIndex > m_endPointVector.size() - 1)
			endPointIndex = 0;
		break;
	default:
		break;

		m_sprite.setOrigin(newOrigin.width/2.0f, newOrigin.height/2.0f);
	

	}
}

 void Gift::handleCollision(Player& p)
{ 
		remove(); 
}