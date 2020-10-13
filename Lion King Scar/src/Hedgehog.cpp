#include "Hedgehog.h"


Hedgehog::Hedgehog(sf::Vector2f location)
	: Enemy(location, 40.0f, &Resources::loadResources().gethedgehogTextures())
{
	m_lives = 1;

	m_sprite.setTextureRect(Resources::loadResources().getheadghogwalkingingRect()[0]);

	Animation animation(32.5);
	animation.addRotatingVector(Resources::loadResources().getheadghogrotatingRect());
	animation.addMovingVector(Resources::loadResources().getheadghogwalkingingRect());
	animation.addDefeatingVector(Resources::loadResources().getheadghogrotatingRect());
	animation.setAnimationType(animationType::moving);
	setAnimation(animation);
	setAnimationType(animationType::moving);
}

void Hedgehog::handleCollision(Player& player)
{
	if (player.isAttacking())
		setAnimationType(animationType::defeating);
}
