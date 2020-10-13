#include "Lizard.h"


Lizard::Lizard(sf::Vector2f location)
	: Enemy(location, LIZARD_SPEED, &Resources::loadResources().getlizardTextures())
{
	m_lives = 3;
	if (rand() % 2 == 0)
		m_animation.setAnimationType(animationType::standing);
	else
		m_animation.setAnimationType(animationType::moving);

	m_sprite.setTextureRect(Resources::loadResources().getlizardwalkingingRect()[0]);

	Animation animation(switchTime);
	animation.addStandingVector(Resources::loadResources().getlizardstandingRect());
	animation.addDefeatingVector(Resources::loadResources().getlizardsdefeatingRect());
	animation.addMovingVector(Resources::loadResources().getlizardwalkingingRect());

	Movable::setAnimation(animation);



}

void Lizard::handleCollision(Player& player)
{

	if ((player.getLocation().y + JUMP_EFFECT < getLocation().y && !player.scarjumping()) || player.isAttacking())
		setAnimationType(animationType::defeating);
}
