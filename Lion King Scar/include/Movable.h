#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "StaticBlock.h"
#include "SpecialBlock.h"

class WorldBlock; // for handle collision

//-----------------------------------------------------------------
//			_______________Movable________________________
//		This Cass is like the father of all the movable objects
//-----------------------------------------------------------------
class Movable : public GameObject { 

public:
	Movable(sf::Vector2f location, float speed, sf::Texture *texture);
	~Movable() = default;
	void switchDirection();
	virtual bool isDead() { return m_dead; }
	virtual void move(float deltaTime)  override;
	direction getDirection() { return m_direction; }
	virtual void handleCollision(StaticBlock& block);
	virtual void handleCollision(SpecialBlock& block) {}
	virtual void animation(float deltaTime) override;
	void resetRecoveryClock() { recoveryClock.restart();  }
	void setAnimation(Animation& animation) { m_animation = animation; }
	virtual bool checkCollision(const sf::FloatRect& floatRect) const override;
	void setAnimationType(animationType animate) { m_animationType = animate; }
	sf::FloatRect getRect() const override { return m_futureSprite.getGlobalBounds(); }
	bool isRecoveryTime()  { return (recoveryClock.getElapsedTime().asSeconds() > 1.0f); }

	virtual void draw(sf::RenderWindow& window) override { 
		window.draw(m_sprite); 
		setLocation(m_sprite.getPosition());
	}
protected:
	int m_lives;
	float m_speed;
	bool m_dead = false;
	sf::Sprite m_sprite;
	bool canJump = false;
	Animation m_animation;
	sf::Vector2f velocity;
	sf::Sprite m_futureSprite;
	bool handle_with_liz =false;
	direction m_direction = direction::Right;
	animationType m_animationType = animationType::standing;

private:
	sf::Texture *m_texture;
	sf::Clock recoveryClock;
	bool isDeafeated = false;
	bool time_to_heal = false;
 };

