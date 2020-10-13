#pragma once
#include "Globals.h"
#include "World.h"


//-----------------------------------------------------------------
//			_______________Controller_________________________
//		This Cass control al about the game's proccess - 
//		as this name hint - here we run the game, and communicate with player
//		
//-----------------------------------------------------------------
class Controller 
{
public:
	Controller(sf::RenderWindow&,bool,bool,int);
	~Controller() = default;
	void run();
	void displayLevelPassed();
	void displayStartMessage();
	void displayFailedMessage();
	bool pauseGame();
private:


	sf::Sprite gameOverBackground;
	bool musicOn;
	sf::View m_view;
	sf::RenderWindow &m_window;
	World m_world;
	sf::Clock dtClock;
	float deltaTime = 0;
	sf::Clock gameTime;
	std::vector<sf::Text> m_texts;
	std::string m_messages[OPTIONS] = { "Find the sun!" , "RUN!", "Good job, get ready for the next level!",
		"            Level Paused\n\n Press Enter to continue or E to exit"};

	sf::Sprite levelPassedBackground;
};