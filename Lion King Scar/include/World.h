#pragma once
#include "Globals.h"
#include "Player.h"
#include "Hyena.h"
#include "Vulture.h"
#include "GameObject.h"
#include "NonMovable.h"
#include "Lizard.h"
#include <vector>
#include "Decoration.h"
#include "World_Block.h"
#include "Collision.h"
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include "Enemy.h"
#include "HealthGift.h"
#include "LifeGift.h"
#include "SunGift.h"
#include "CheckPointGift.h"



class World
{
public:
	
	World(bool&,bool&,int&);
	~World() = default;
	void create_board();
	void addObject(char c, sf::Vector2f&);
	void moveCharacters(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);
	void collision();
	sf::Vector2f& getplayerPosition() { return m_player->getLocation(); }
	void addCharacter(char c, sf::Vector2f& sfLocation);
	void drawBackground(sf::RenderWindow&);
	bool checkFinish() { return m_levelFinished; }
	void finish();
	void updateView(sf::View& view);
	bool gameOver() { return m_gameOver; }
	void setMusic(const bool& music);
	void setSoundEffects(const bool& sound);
	int getLevelIndex() { return levelIndex; }
	bool failed() { return levelFailed; }
	void addGift(giftType gt, const sf::Vector2f & sfLocation);
private:

	int index = 0;
	int levelIndex = 0;
	int worldNumber = 1; //that symbolises the number of level.
	int m_difficulty = 1;
	bool levelFailed = false;
	float viewSpeed = 4.0f; 
	sf::Clock viewSpeedClock;
	Player* m_player;
	std::vector<std::unique_ptr<GameObject> > gameObjects;
	std::vector<std::string> _world_file;
	sf::Vector2f m_destination;
	sf::Vector2f m_startingPosition;	// player starting location
	bool m_levelFinished = false;
	bool musicOn;
	bool soundEffects = true;
	std::vector<std::string> worlds;
	sf::Sprite m_background;
	sf::Vector2f m_viewCenter;
	bool resetView = false;
	 sf::Vector2f m_viewSize;
	 bool m_gameOver = false;

	 sf::Sound  m_music;
};


bool collide(GameObject& a, GameObject& b);
