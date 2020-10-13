#pragma once
#include "Globals.h"





class GameObject {
	
	public:
		virtual void draw(sf::RenderWindow&) = 0;
		GameObject(sf::Vector2f& location) : m_location(location), m_startingLocation(location){}
		virtual void animation(float deltaTime) = 0;
		virtual void update(float deltatime) = 0;
		virtual void move(float deltaTime) = 0;
		virtual ~GameObject() = default;
		sf::Vector2f& getLocation() { return m_location; }
		void setLocation(const sf::Vector2f& location) { m_location = location; }
		virtual bool checkCollision(const sf::FloatRect& floatRect) const = 0;
		virtual sf::FloatRect getRect() const = 0;
 		bool exists() {return m_isExcist;}
		void remove() {  m_isExcist = false; }
		void resetLocation() { m_location = m_startingLocation; }
		void setStartingLocation(const sf::Vector2f& location) { m_startingLocation = location; }
		sf::Vector2f& getStartingLocation() { return m_startingLocation;  }
	private:
		sf::Vector2f m_location;
		sf::Vector2f m_startingLocation;
		bool m_isExcist = true;

};