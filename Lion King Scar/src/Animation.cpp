#include "Animation.h"

//-----------------------------------------------------------------
//			_______________Animation_________________________
//		This Cass control al about the animation at this game
//		is means - here each player, enemy, object recive
//		the require animation he needs to preform in an animation way
//-----------------------------------------------------------------
void Animation::animation(sf::Sprite& sprite, float deltaTime, direction dir)
{

	if (injuredIndex == 0)
		setAnimation();
	else m_animation = animationType::injured;
		int vectorSize = 0;

		switch (m_animation)
		{
		case animationType::moving:
			if (m_movingVector.size() == 0)
				return;
			sprite.setTextureRect(m_movingVector[movingIndex]);
			sprite.setOrigin(m_movingVector[movingIndex].width / 2.0f, m_movingVector[movingIndex].height / 2.0f);
			if (deltaTime >= switchTime)
				movingIndex = (movingIndex + 1) % (int)m_movingVector.size();
		//	std::cout <<"move index: " << movingIndex << std::endl;
			currIndex = movingIndex;
			break;
		case animationType::injured:
			if (m_injuredVector.size() == 0)
				return;
			sprite.setTextureRect(m_injuredVector[injuredIndex]);
			sprite.setOrigin(m_injuredVector[injuredIndex].width / 2.0f, m_injuredVector[injuredIndex].height / 2.0f);
			vectorSize = (int)m_injuredVector.size();
			manageAnimation(deltaTime, injuredIndex, vectorSize, inInjured);
			currIndex = injuredIndex;

			break;


		case animationType::rotating:
			if (m_rotatingVector.size() == 0)
				return;
			//if (inRotation)
			{
				sprite.setTextureRect(m_rotatingVector[rotatingIndex]);
				sprite.setOrigin(m_rotatingVector[rotatingIndex].width / 2.0f, m_rotatingVector[rotatingIndex].height / 2.0f);
				vectorSize = (int)m_rotatingVector.size();
				//inRotation = true;
				manageAnimation(deltaTime, rotatingIndex, vectorSize, inRotation);

			//	if (rotatingIndex == 0)
				//if (m_direction == direction::Right)
				if(dir == direction::Right)
					sprite.setScale(-1, 1);
			}
			currIndex = rotatingIndex;
			break;
		case animationType::jumping:
			if (m_jumpingVector.size() == 0)
				return;
			sprite.setTextureRect(m_jumpingVector[jumpingIndex]);
			sprite.setOrigin(m_jumpingVector[jumpingIndex].width / 2.0f, m_jumpingVector[jumpingIndex].height / 2.0f);
			vectorSize = (int)m_jumpingVector.size();
			manageAnimation(deltaTime, jumpingIndex, vectorSize, inJumping);
			currIndex = jumpingIndex;
			break;
		case animationType::standing:
			if (m_standingVector.size() == 0)
				return;
			sprite.setTextureRect(m_standingVector[standingIndex]);
			sprite.setOrigin(m_standingVector[standingIndex].width / 2.0f, m_standingVector[standingIndex].height / 2.0f);
			vectorSize = (int)m_standingVector.size();
			manageAnimation(deltaTime, standingIndex, vectorSize, inStanding);
			currIndex = standingIndex;
			break;

		case animationType::attacking:
			if (m_attackingVector.size() == 0)
				return;
			sprite.setTextureRect(m_attackingVector[attackingIndex]);
			sprite.setOrigin(m_attackingVector[attackingIndex].width / 2.0f, m_attackingVector[attackingIndex].height / 2.0f);
			vectorSize = (int)m_attackingVector.size();
			manageAnimation(deltaTime, attackingIndex, vectorSize, inAttacking);
			currIndex = attackingIndex;
			break;
		case animationType::flying:
			if (m_flyingVector.size() == 0)
				return;
			sprite.setTextureRect(m_flyingVector[flyingIndex]);
			sprite.setOrigin(m_flyingVector[flyingIndex].width / 2.0f, m_flyingVector[flyingIndex].height / 2.0f);

			vectorSize = (int)m_flyingVector.size();
			manageAnimation(deltaTime, flyingIndex, vectorSize, inFlying);
			currIndex = flyingIndex;
			break;

		case animationType::defeating:
			if (m_defeatingVector.size() == 0) 
			{
				m_defeated = true;
				break;
			}
			sprite.setTextureRect(m_defeatingVector[defeatingIndex]);
			sprite.setOrigin(m_defeatingVector[defeatingIndex].width / 2.0f, m_defeatingVector[defeatingIndex].height / 2.0f);

			vectorSize = (int)m_defeatingVector.size();
			manageAnimation(deltaTime, defeatingIndex, vectorSize, inDefeating);
			currIndex = defeatingIndex;
			if (defeatingIndex == 0)
				m_defeated = true;
			break;

		default:
			break;
		}

}

void Animation::updateCurrentAnimation(animationType newAnimation)
{
	if (rotatingIndex != 0)// && newAnimation == animationType::defeating)
		return;
	if (currIndex == 0 || newAnimation == animationType::defeating)
		resetAnimations();

	if (newAnimation == animationType::moving)
		inMoving = true;
		m_animation = newAnimation;
}

//-----------------------------------------------------------------
//		this function controls of ehich king of animation yepe will be on the currect object
//-----------------------------------------------------------------
void Animation::setAnimationFlags(animationType& newAnimation)
{
	switch (newAnimation)
	{
	case animationType::attacking:
		inAttacking = true;
		break;
	case animationType::moving:
		inMoving = true;
		break;
	case animationType::jumping:
		inJumping = true;
		break;
	case animationType::injured:
		inInjured = true;
		break;
	case animationType::defeating:
		inDefeating = true;
		break;
	case animationType::standing:
		inStanding = true;
		break;
	case animationType::flying:
		inFlying = true;
	default:
		break;
	}

}

//-----------------------------------------------------------------
//		this function reset all the deferent animation types at case the object change his animation (for instance - from walking to attaking)
//-----------------------------------------------------------------
void Animation::resetAnimations()
{
		inRotation = false,
		inJumping = false,
		inAttacking = false,
		inFlying = false,
		inDefeating = false,
		inInjured = false,
		inMoving = false,
		inStanding = false;
}

//-----------------------------------------------------------------
//		this function set the animation that decided to be this currect time at the currect object
//-----------------------------------------------------------------
void Animation::setAnimation()
{
	if (!inMoving) 
	{
		if (inRotation)
			m_animation = animationType::rotating;

		else if (inAttacking)
			m_animation = animationType::attacking;

		else if (inJumping)
			m_animation = animationType::jumping;

		else if (inInjured)
			m_animation = animationType::injured;

		else if (inDefeating)
			m_animation = animationType::defeating;
		else if (inFlying)
			m_animation = animationType::flying;
		else m_animation = animationType::standing;
	}
}


//-----------------------------------------------------------------
//		this function controls the time each animation will be shown!
//-----------------------------------------------------------------
void Animation::manageAnimation(float& deltaTime, int& index, int& size, bool& in_animation)
{
	if (deltaTime >= switchTime)
			index++;
	
	if (index > size - 1)
	{
		in_animation = false;
		index = 0;	
	}
}