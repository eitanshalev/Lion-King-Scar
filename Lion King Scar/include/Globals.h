#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>


enum pictures_t { background_menu, level_passed_background, fail_background, };
enum class fontType { menuFont, gameFont };
enum class block_type_t {

	topLeft,
	ground,
	topRight,
	left_wall,
	inner_floor,
	right_wall,
	botLeft,
	ceiling,
	botRight,
	left_island,
	mid_island,
	right_island
};

enum class sound_t {
s_Botton_Click,
s_check_point,
s_gift,
s_hyena,
s_jumping,
s_level_1,
s_level_2,
s_level_3,
s_level_failure,
s_level_passed,
s_lizard_attak,
s_lizard_hurt,
s_main_player_attak,
s_main_player_hurt,
s_menu_sound,
s_scar_falling,
s_vulture
};

const float PLAYER_SPEED = 100.0f;
const float HYENA_SPEED = 30.0f;
const float VULTURE_SPEED = 35.0f;
const float LIZARD_SPEED = 15.0f;

enum class decoration_type_t {
	animal1,
	animal2,
	tree1,
	tree2,
	tree3,
	item1,
	item2
};

enum class options { Start_Game, Options, game_instructions,exit };
enum class objectOption { block, background, gift };
enum class menuOptions { sound, music, difficulty, backToMenu };
enum class difficulty_t { easy, normal, hard };
enum class animationType{ moving, jumping, standing, attacking, hanging, rotating, defeating, moving_up, flying , injured};
enum class giftType { _healing, _Onelife, checkPoint, endPoint };
enum class direction { Left, Right };

#define WORLD_MAP "level.txt" 

enum {
	findSun,
	runMessage,
	goodJob,
	pauseMessage
};

//-----------------------menu
const int FIVE = 5;
const int STEP = 12;
const int OPTIONS = 4 ;
const int VELOCITY = 50;
const int END_LIMIT = 30;
const int NEXT_FRAME = 84;
const int FRAME_LIMIT = 30;
const int JUMP_EFFECT = 25;
const int VIEW_WIDTH = 800;
const int VIEW_HEIGHT = 500;
const int JUMP_DISTANCE = 30;
const int LOCATION_LIM = 300;
const int TWO_DIRECTIONS = 2;
const int NUM_OF_OPTIONS = 4;
const int GAME_FONT_SIZE = 20;
const int DIFFICULT_LEVEL = 3;
const int MENU_FONT_SIZE = 50;
const int FONTMENUSAPACE = 90;
const int WINDOW_SIZE_X = 640 * 2;
const int WINDOW_SIZE_Y = 480 * 2;
const int WORLD_BLOCK_SIZE_X = 33;
const int WORLD_BLOCK_SIZE_Y = 33;
const int NUM_OF_ROTATION_ANIMATIONS = 6;
