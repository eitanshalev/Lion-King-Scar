#include "Player.h"
#include <sstream>
#include "Lizard.h"

Player::Player(sf::Vector2f location, bool &soundOn) : Movable(location, PLAYER_SPEED, &Resources::loadResources().getScarTextures()){
	float switchTime = 32.0f;


	m_lives = 1;
	
	Animation animation(switchTime);
	animation.addAttackingVector(Resources::loadResources().getScarAttackingRect());
	animation.addRotatingVector(Resources::loadResources().getScarRotationRect());
	animation.addStandingVector(Resources::loadResources().getScarStanding());
	animation.addJumpingVector(Resources::loadResources().getScarJumpingRect());
	animation.addInjuredVector(Resources::loadResources().getScargotheartRect());
	animation.addMovingVector(Resources::loadResources().getScarMovingRect());
	Movable::setAnimation(animation);

	m_sprite.setTextureRect(Resources::loadResources().getScarMovingRect()[3]);
	m_animation.setAnimationType(animationType::standing);
	setAnimation(animation);

	auto spriteOrigin = m_sprite.getTextureRect();
	m_data.setOrigin(spriteOrigin.width / 2.0f, spriteOrigin.height / 2.0f);
	m_data.setTexture(Resources::loadResources().getdatascar());
	m_data.setTextureRect(m_dataFacerectVector[0]);
	m_data.setPosition(location);
	m_data.setScale(-1, 1);

	m_healthBar.setOrigin(spriteOrigin.width / 2.0f, spriteOrigin.height / 2.0f);
	m_healthBar.setTexture(Resources::loadResources().gethealthbarscar());
	m_healthBar.setTextureRect(m_dataHealthBarrectVector[0]);
	m_healthBar.setPosition(location);
	
	life_show.setFont(Resources::loadResources().getFont(fontType::menuFont));
	life_show.setOutlineThickness(2);


	if (soundOn)
	{
		jump.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_jumping));
		fallingSound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_scar_falling));
		attacking.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_main_player_attak));
		ouch.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_main_player_hurt));
		failure.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_level_failure));
		
	}





}


//---------------------------------------------------------
// This Function Helps Main Player Define Wheter He
//  Has Passed The Correct View Limit
//  this will help us espesiialy at levels the view moves by indenpence way
//---------------------------------------------------------
void Player::checkLimits(const sf::Vector2f& viewcenter)
{
	if (m_futureSprite.getPosition().x + END_LIMIT >= viewcenter.x + VIEW_WIDTH/2.0f)
	{
		velocity.x = 0; 
	}

	if (m_futureSprite.getPosition().x <= viewcenter.x - VIEW_WIDTH / 2.0f)
	{
		m_health = 0;
		m_lives--;
		failure.play();
		if (m_lives == 0)
			m_dead = true;
	}
}


void  Player::handleCollision(Hedgehog& h)
{
	if(isRecoveryTime()) 
		handlewithEnemy(h.getLocation().x);

}

void Player::handleCollision(Decoration& decoration)
{
	 if (decoration.getType() != decoration_type_t::animal2)
		return; 
	if (decoration.getType() == decoration_type_t::tree3)
		return;

	if (abs(decoration.getLocation().x - getLocation().x) <= 50 && (decoration.getLocation().y - decoration.getRect().height/2.0f > getLocation().y) && velocity.y >= 0.0f)
		{

 			velocity.y = 0;
			canJump = true;
		
		}

}

//---------------------------------------------
//	here the definition of ehat wiell haped with enemy
//---------------------------------------------
void Player::handlewithEnemy(float enemyX)
{
	
	if (!m_animation.isAttacking())
	{
		if (enemyX > getLocation().x) 
			velocity.x -= 500;
		else velocity.x += 500;
		setAnimationType(animationType::injured);
		ouch.play();
		m_health--;
		m_animation.setInjured();
		resetRecoveryClock();//set 3 secound to avoid another hard 
	}
	if (m_health == 0)
	{
		//return to checkpoint
		m_lives --;
		failure.play();
	
	}

	if (m_lives == 0)
	{
		m_dead = true;
	}
}



//---------------------------------------------
//	here the definition of ehat wiell haped with enemy
//---------------------------------------------
void Player::handleCollision(Lizard& liz)
{
	

	if (getLocation().y + JUMP_EFFECT < liz.getLocation().y)
	{

		canJump = true;
		handle_with_liz = true;
	}
	else if (isRecoveryTime())
		handlewithEnemy(liz.getLocation().x);
}

void Player::handleCollision(Hyena& hyena)
{

	if (getLocation().y + JUMP_EFFECT-10 < hyena.getLocation().y &&  hyena.isRecoveryTime())
	{
		canJump = true;
		handle_with_liz = true;
	}
	else if (isRecoveryTime() && hyena.isRecoveryTime())
		handlewithEnemy(hyena.getLocation().x);
}

void Player::handleCollision(Vulture& vulture)
{
	 if (isRecoveryTime())
		handlewithEnemy(vulture.getLocation().x);
}

void Player::handleCollision(Gift& gift)
{

	giftSound = gift.getGiftSound();
	giftSound.play();
	
	switch (gift.getType()) {
	case giftType::_healing:

		if (m_health < 5)
			m_health++;
		break;

	case giftType::_Onelife:
		m_lives++;
		break;

	case giftType::checkPoint:
		setStartingLocation(gift.getLocation());
		break;

	case giftType::endPoint:
		m_finished = true;
		break;
		
	default:
		break;
	}
}




//---------------------------------------------
//	here the definition of the time 
//---------------------------------------------
void Player::update(float deltaTime) //update player movement
{
	velocity.x *= 0.5f;
	
	animationType animation = m_animation.getCurrentAnimation();

	m_futureSprite = m_sprite;

	direction newDirection = getDirection();
	m_animation.setStanding();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (!m_animation.isJumping() && !m_animation.isInjured()) {
			m_animation.setMoving();
			animation = animationType::moving;
		}
		velocity.x += m_speed;
		
		newDirection = direction::Right;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (!m_animation.isJumping() && !m_animation.isInjured()) {
			m_animation.setMoving();
			animation = animationType::moving;
		}
			velocity.x -= m_speed;
		newDirection = direction::Left;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X) && !m_animation.isAttacking())
	{
		m_animation.setAttacking();
		attacking.play();
		animation = animationType::attacking;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{	
   		canJump = false;
		velocity.y = -sqrtf(2.0f * 1500.0f * JUMP_DISTANCE);  
		m_animation.setJump();
		animation = animationType::jumping;
		jump.play();
		
	}
	

	if ( canJump && handle_with_liz)
	{
		
		canJump = false;
		handle_with_liz = false;
		velocity.y = -sqrtf(2.0f * 1500.0f * JUMP_DISTANCE);
		m_animation.setJump();
		jump.play();
		animation = animationType::jumping;
	}


	if (getDirection() != newDirection )//|| inRotation())
	{
		Movable::switchDirection();
		if (!m_animation.isJumping())
		{
			animation = animationType::rotating;
			m_animation.setRotation();
		}
	}

	if (!m_animation.isMoving() && !m_animation.isJumping() && !m_animation.isAttacking() && !m_animation.inrotation())
		animation = animationType::standing;
	

	if (!isRecoveryTime() && Movable::m_animation.isInjured())
		animation = animationType::injured;


	else m_animation.isNotInjured();

	setAnimationType(animation);


	velocity.y += 700.0f * deltaTime;


	if (velocity.y > 1500) {	//if FALLING
		fallingSound.play();
		m_lives--;
		m_health = 0;
		velocity.y = 0;
		if(m_lives <= 0)
			m_dead = true;
		
	}

	m_futureSprite.move(velocity * deltaTime); //* deltaTime);
	m_newLocation = m_futureSprite.getPosition();

}


//-------------------------------------------------
//  This Function 
//-------------------------------------------------
void Player::showStats(sf::RenderWindow &window, sf::Vector2f viewCenter)
{
	m_data.setPosition(viewCenter.x - 300, viewCenter.y + 150);

	std::ostringstream lives;
	lives << m_lives;
	life_show.setString(lives.str());

	life_show.setPosition(viewCenter.x - 250, viewCenter.y + 150);
	window.draw(life_show);
	
	window.draw(m_data);

	m_healthBar.setPosition(viewCenter.x - 300,viewCenter.y - 200);
	
	m_healthBar.setTextureRect(m_dataHealthBarrectVector[5 - m_health]);
	window.draw(m_healthBar);
}
