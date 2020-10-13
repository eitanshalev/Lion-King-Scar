#pragma once
#include "Globals.h"
#include "Resources.h"
#include "Controller.h"
#include <string>
#include "Globals.h"


//-----------------------------------------------------------------
//			_______________Menu_________________________
//		This Cass is menu, the user see him firstly while the game stars
//			here we acxtually commucinicate with player 
//			here we recive playe's decision - play with backgrouns sounds. or music, difficaulty,etc...
//-----------------------------------------------------------------
class Menu
{
public:
	Menu();
	~Menu() = default;
	void run();
	void select();
	void setMenu();
	void showInstructions();
	void execCommand(options option);
	void draw(sf::RenderWindow& window);
	void highlight(const sf::Vector2f &);
private:

	sf::Sound clickSound;
	sf::RenderWindow window;
	sf::Sprite m_background;
	sf::Sound backgroundMusic;
	std::vector<sf::Text> menu;
	std::vector<sf::Text> m_options;

	std::string m_optionsStrings[NUM_OF_OPTIONS] = { "Start Game", "Options","Game Instructions","Exit" };
	std::string m_menuOptions[6] = { "Sound Effects: ON", "Music: ON" ,"Difficulty: Easy", "Return to menu", "Music: OFF", "Sound Effects: OFF" };
	std::string difficultyString[3] = { "Difficulty: Easy", "Difficulty: Normal","Difficulty: Hard " };
	std::string instructions =
		"                             Insructions:\n"
		"          The objective is to finish the levels without losing lives first\n"
		"               To move to Right or Left press the Right/Left Keys\n"
		"                          To jump Press SPACE\n"
		"     You can hurt your enemies by jumping on them or attacking by pressing 'X'\n"
		"             BUT! don't jump on the hedghog because they're spiky!\n"
		"             bugs give you health bonus and '+1' increases lives by 1\n\n"
		"                         To pause game press ESCAPE\n\n"
		"                  BEST OF LUCK IN YOUR ADVANTURES, YONA & EITAN\n\n"
		"                         press enter to go back to menu      ";
	sf::Text m_instructions;

	bool m_sound;
	bool m_music;
	int m_difficaulty;
	bool inOptions = false;
	bool exit_game = false;
	bool gameOver = false;
};
