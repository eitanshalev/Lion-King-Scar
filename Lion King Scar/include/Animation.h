#pragma once
#include "Globals.h"

//-----------------------------------------------------------------
//			_______________Animation_________________________
//		This Cass control al about the animation at this game
//		is means - here each player, enemy, object recive
//		the require animation he needs to preform in an animation way
//-----------------------------------------------------------------
class Animation
{

public:

	Animation(float switchTime) : switchTime(switchTime) , m_animation(animationType::standing) {}
	~Animation() = default;
	void animation(sf::Sprite& sprite, float deltaTime, direction dir);
	void addAttackingVector(std::vector<sf::IntRect>& vector) { m_attackingVector = vector; }
	void addStandingVector(std::vector<sf::IntRect>& vector) { m_standingVector = vector; }
	void addMovingVector(std::vector<sf::IntRect>& vector) { m_movingVector = vector; }
	void addDefeatingVector(std::vector<sf::IntRect>& vector) { m_defeatingVector = vector; }
	void addRotatingVector(std::vector<sf::IntRect>& vector) { m_rotatingVector = vector; }
	void addJumpingVector(std::vector<sf::IntRect>& vector) { m_jumpingVector = vector; }
	void addInjuredVector(std::vector<sf::IntRect>& vector) { m_injuredVector = vector; }
	void addFlyingVector(std::vector<sf::IntRect>& vector) { m_flyingVector = vector; }

	void updateCurrentAnimation(animationType newAnimation);
	void setAnimationFlags(animationType &newAnimation);
	void resetAnimations();
	void setAnimation();
	void setAnimationType(animationType animation) { m_animation = animation; }
	void rotate() { inRotation = true; }
	void setMoving(){ inMoving = true; }
	void setJump() { inJumping = true; }// inMoving = false; }
	void setAttacking() { inAttacking = true; }
	void setFlying() { inFlying = true; }
	void setDefeating() { inDefeating = true; }
	void setInjured() { inInjured = true; }
	void setStanding() { inStanding = true; inMoving = false; }

	bool isRotating() { return inRotation ; }
	bool isMoving(){ return inMoving ; }
	bool isJumping() { return inJumping; }
	bool isAttacking() {return inAttacking ; }
	bool isFlying() { return inFlying ; }
	bool isDefeating() { return inDefeating ; }
	bool isDead() { return m_defeated; }

	bool inrotation() { return inRotation; }
	void setRotation() { inRotation = true; }
	bool isInjured() { return inInjured && injuredIndex != 0; }
	void isNotInjured() { inInjured = false; injuredIndex = 0; }
	//bool isRotation() {return }

	animationType getCurrentAnimation() { return m_animation; }

private:
	void manageAnimation(float& deltaTime, int& index, int& size, bool& in_animation);

	bool inRotation = false,
		 inJumping = false,
		 inAttacking = false,
		 inFlying = false,
		 inDefeating = false,
		 inInjured = false,
		 inMoving = false,
		 inStanding = false;

	int standingIndex = 0,
		movingIndex = 0,
		attackingIndex = 0,
		defeatingIndex = 0,
		rotatingIndex = 0,
		jumpingIndex = 0,
		flyingIndex = 0,
		injuredIndex = 0,
		currIndex = 0;

	std::vector<sf::IntRect>
		m_standingVector, m_movingVector,
		m_defeatingVector, m_jumpingVector,
		m_injuredVector, m_rotatingVector,
		m_attackingVector,m_flyingVector;

	float switchTime;
	bool m_defeated = false;
	animationType m_animation;

};