#include "Vulture.h"

 

Vulture::Vulture(sf::Vector2f location, bool& soundOn, int& difficulty)
	: Enemy(location, VULTURE_SPEED* difficulty, &Resources::loadResources().getvultureTextures())
{

	m_lives = 2;
	m_sprite.setTextureRect(Resources::loadResources().getvulturetstandingRect()[0]);


	Animation animation(20);
	animation.addStandingVector(Resources::loadResources().getvulturetstandingRect());
	animation.addDefeatingVector(Resources::loadResources().getvuelturedefeatingRect());
	animation.addMovingVector(Resources::loadResources().getvulturetwalkingRect());
	animation.addRotatingVector(Resources::loadResources().getheadghogrotatingRect());
	animation.addFlyingVector(Resources::loadResources().getvueltureflyingRect());
	//animation.addTAKINGOFF(Resources::loadResources().getvulturetmoving_up_Rect());
	//Resources::loadResources().getvulturetmoving_up_Rect();
	Movable::setAnimation(animation);


	if (soundOn)
	{
		sf::Sound scar_is_around;
		scar_is_around.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_vulture));
		setSound(scar_is_around);
	}

}

void Vulture::update(float deltaTime)
{
	m_futureSprite = m_sprite;
	if (!m_animation.isDefeating())
	setAnimationType(animationType::flying);
	
	if (isNearPlayer()) {
		sf::Vector2f playerLocation = getPlayerLocation();
		
		if (playerLocation.x < getLocation().x)
			velocity.x -= m_speed;
		else velocity.x += m_speed;

		if (playerLocation.y < getLocation().y)
			velocity.y -= m_speed;
		else velocity.y += 3;

		

		m_futureSprite.move(velocity * deltaTime);
	}

	else Enemy::update(deltaTime);

}

void Vulture::handleCollision(Player& player)
{
	animationType animation;

	if (isRecoveryTime())
	{

		if (player.isAttacking()) {

			//std::cout << "m_lives " << m_lives << std::endl;
			m_lives--;
			//resetRecoveryClock();//set 3 secound to avoid another hard 
			playScarIsAround();
			animation = animationType::injured;
			if (m_lives <= 0) {
				animation = animationType::defeating;
				m_animation.setDefeating();
			}

		}
	}





}
