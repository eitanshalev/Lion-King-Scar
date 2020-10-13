#include "Movable.h"


Movable::Movable(sf::Vector2f location, float speed, sf::Texture *texture)
	: GameObject(location), m_speed(speed), m_texture(texture), m_animation(0)

{
	m_sprite.setTexture(*m_texture);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.0f, m_sprite.getTextureRect().height / 2.0f);
	m_sprite.setPosition(location);
	setLocation(m_sprite.getPosition());

}

void Movable::switchDirection()
{
	if (m_direction == direction::Right)
		m_direction = direction::Left;
	else m_direction = direction::Right;
}

void Movable::move(float deltaTime)
{
	m_sprite.move(velocity * deltaTime);
	setLocation(m_sprite.getPosition());
}

void Movable::animation(float deltaTime)
{
	m_animation.updateCurrentAnimation(m_animationType);
	m_animation.setAnimationFlags(m_animationType);  //for enemy
	m_animation.animation(m_sprite, deltaTime, m_direction);

	if (m_animation.isDead())
		remove();

	if (m_direction == direction::Left && !m_animation.inrotation())
		m_sprite.setScale(-1, 1);
	else m_sprite.setScale(1, 1);
}

bool Movable::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_futureSprite.getGlobalBounds().intersects(floatRect);
}

void Movable::handleCollision(StaticBlock& block)
{

	auto blockX = block.getLocation().x;
	auto blockY = block.getLocation().y;
	auto myX = m_futureSprite.getPosition().x;
	auto myY = m_futureSprite.getPosition().y;


	if (blockY > myY && velocity.y >= 0.0f)
	{

		velocity.y = 0;
		canJump = true;
		handle_with_liz = false;
	}

	else if (blockX >= myX && velocity.x >= 0)
	{

		velocity.x = 0;
	}
	else if (blockX <= myX && velocity.x < 0)
	{

		velocity.x = 0;
	}

	if (blockY <= myY && velocity.y <= 0 && abs(blockX - myX) < block.getRect().width)
	{

		velocity.y = 0;
	}

}

