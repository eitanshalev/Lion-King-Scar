#include "Hyena.h"



Hyena::Hyena(sf::Vector2f location, bool& soundOn, int& difficulty)
	: Enemy(location, HYENA_SPEED* difficulty, &Resources::loadResources().gethyneaTextures()) {
	//m_animation = standing;

	m_lives = 3;
	float switchTime = 10.0f;
	Animation animation(switchTime);

	animation.addStandingVector(Resources::loadResources().gethyenastandingRect());
	animation.addAttackingVector(Resources::loadResources().gethyenasattakingRect());
	animation.addDefeatingVector(Resources::loadResources().gethyenadefeatingRect());
	animation.addJumpingVector(Resources::loadResources().gethyenaJumpingRect());
	//animation.addRotatingVector( Resources::loadResources().gethyenaRotationRect());
	animation.addMovingVector(Resources::loadResources().gethyenaWalkingRect());
	animation.addInjuredVector(Resources::loadResources().gethyenaRotationRect());
	setAnimation(animation);

	m_sprite.setTextureRect(Resources::loadResources().gethyenastandingRect()[0]);

	if (soundOn)
	{
		sf::Sound scar_is_around;
		scar_is_around.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_hyena));
		setSound(scar_is_around);
	}
}


void Hyena::handleCollision(Player& player)
{
	animationType animation = m_animation.getCurrentAnimation();
	if (isRecoveryTime())
	{
		
		if ((player.getLocation().y + JUMP_EFFECT  < getLocation().y && !player.scarjumping()) || player.isAttacking())
		{
			animation = animationType::injured;
			m_animation.setInjured();
			m_lives--;
			playScarIsAround();
			
			resetRecoveryClock();//set 3 secound to avoid another hard 
			if (m_lives <= 0)
			{
				animation = (animationType::defeating);
				m_animation.setDefeating();
				//m_dead = true;
			}
			setAnimationType(animation);
			return;
		}

		animation = animationType::attacking;
		m_animation.setAttacking();// = true;
	}

	setAnimationType(animation);

}
