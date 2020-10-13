#include "Enemy.h"

Enemy::Enemy(sf::Vector2f location, float speed, sf::Texture* texture)
	: Movable(location, speed, texture)
{
	int randomDirection = rand() % 2;
	m_direction = (direction) randomDirection;
}

//---------------------------------------------
//here we upddata the animation sprite
//---------------------------------------------
void Enemy::update(float deltaTime)
{
	m_futureSprite = m_sprite;
	animationType animation = m_animation.getCurrentAnimation();
	
	if (m_animation.isDefeating())
	{
		animation = animationType::defeating;
		setAnimationType(animation);
		return;
	}
	if (nearPlayer)
	{
		moveToPlayer();
			return;
	}

	velocity.x *= 0.5;

	if (movingClock.getElapsedTime().asSeconds() > m_movingTime)
	{
		int randomDirection = rand() % TWO_DIRECTIONS;
		m_direction = (direction) randomDirection;
		movingClock.restart();
		
		animation = animationType::moving;
		isStanding = false;
	}
	if (standClock.getElapsedTime().asSeconds() > m_standingTime)
	{
		isStanding = true;
		animation = animationType::standing;
		movingClock.restart();
		standClock.restart();
	}

	if (!isStanding) {
		if (m_direction == direction::Left)
		{
			velocity.x -= m_speed;
			m_sprite.setScale(-1, 1);
		}
		else
		{
			velocity.x += m_speed;
			m_sprite.setScale(1, 1);
		}
	}

	else velocity.x = 0;

	velocity.y += 50;
	m_futureSprite.move(velocity * deltaTime);

	setAnimationType(animation);
}

void Enemy::checkPlayerLocation(const sf::Vector2f& playerLocation)
{
	if ((abs(getLocation().x - playerLocation.x) < LOCATION_LIM)
		&& (abs(getLocation().y - playerLocation.y) < LOCATION_LIM))
	{
		nearPlayer = true;
		m_playerLocation = playerLocation;
	}

	else nearPlayer = false;

}

void Enemy::animation(float deltaTime)
{	
	m_animation.setAnimationFlags(m_animationType);
	Movable::animation(deltaTime);
}

//---------------------------------------------
//at situation acar is arund we come here!
//---------------------------------------------
void Enemy::moveToPlayer()
{
	animationType animation;
	if (soundTime.getElapsedTime().asSeconds() < 3.0f)
	{
		scar_is_around.play();
		soundTime.restart();
	}

	if (m_playerLocation.x > getLocation().x)
	{
		velocity.x = m_speed * 2;
		m_direction = direction::Right;
	}
	else if (m_playerLocation.x < getLocation().x)
	{
		velocity.x = -m_speed * TWO_DIRECTIONS; 
		m_direction = direction::Left;
	}
	animation = animationType::moving;
	velocity.y += VELOCITY;

	setAnimationType(animation);
}
