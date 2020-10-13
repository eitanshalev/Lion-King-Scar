#pragma once
#include "Globals.h"
#include "Resources.h"
#include "GameObject.h"
//-----------------------------------------------------------------
//			_______________NonMovable________________________
//		This Cass is like the father of all the movable objects
//-----------------------------------------------------------------
template <typename T>
class NonMovable : public GameObject {

public:

    virtual void update(float deltaTime) override {}
    virtual void draw(sf::RenderWindow& window) override { window.draw(m_sprite); }
	NonMovable(sf::Vector2f& location, T bt, int worldNum);// : GameObject(location)
	~NonMovable() = default;
    virtual sf::FloatRect getRect() const override { return m_sprite.getGlobalBounds(); };
    virtual bool checkCollision(const sf::FloatRect& floatRect) const override
    {
        return m_sprite.getGlobalBounds().intersects(floatRect);
    }
	
	T getType() { return m_type; }
protected:
    sf::Sprite m_sprite;
	T m_type;
};



template<typename T>
inline NonMovable<T>::NonMovable(sf::Vector2f& location, T bt, int worldNum) : GameObject(location) ,m_type(bt)
{
	m_sprite.scale(0.2f, 0.2f);
	m_sprite.setPosition(location);
	setLocation(m_sprite.getPosition());
	m_sprite.setTexture(Resources::loadResources().getWorldTexture(worldNum));
	m_sprite.setTextureRect(Resources::loadResources().getWorldBlocks(worldNum)[(int)bt]);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.0f, m_sprite.getTextureRect().height / 2.0f);
	
}
