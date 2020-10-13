#include "Resources.h"

std::vector<sf::IntRect>& Resources::getDecoration(int worldNum)
{
	switch (worldNum)
	{
	case 1: return m_world1Decoration;
	case 2: return m_world2Decoration;
	case 3: return m_world3Decoration;
	default:
		break;
	}
}


std::vector<sf::Texture>& Resources::getBackground()
{
	return backgrounds;
}
//---------------------------------------------
//	here the definition of all the resources should get onto the program
//---------------------------------------------
Resources::Resources()
{
	sf::Texture texture;
	texture.loadFromFile("_preview_lion_king.png");
	m_textures.push_back(texture);

	texture.loadFromFile("_level_complete_lion_king.png"); // end with success
	m_textures.push_back(texture);

	texture.loadFromFile("_game_over.png"); // end with failure
	m_textures.push_back(texture);

	sf::Font font;
	font.loadFromFile("lion_king.ttf");
	m_fonts.push_back(font);
	font.loadFromFile("game_font.ttf");
	m_fonts.push_back(font);
//sound loaded!
	sf::SoundBuffer sound;
	sound.loadFromFile("s_Botton_Click.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_check_point.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_gift.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_hyena.ogg");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_jumping.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_level_1.ogg");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_level_2.ogg");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_level_3.ogg");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_level_failure.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_level_passed.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_lizard_attak.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_lizard_hurt.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_main_player_attak.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_main_player_hurt.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_menu_sound.ogg");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_scar_falling.wav");
	m_sounds.emplace_back(sound);
	sound.loadFromFile("s_vulture.wav");
	m_sounds.emplace_back(sound);
	//


	//skar walking
	//sf::Texture s;
	scar.loadFromFile("scar.png");
	m_scarMovingRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scarMovingRect.emplace_back(sf::IntRect(85, 8, 81, 31));   
	m_scarMovingRect.emplace_back(sf::IntRect(169, 8, 81, 31));
	m_scarMovingRect.emplace_back(sf::IntRect(258, 8, 81, 31)); 
	m_scarMovingRect.emplace_back(sf::IntRect(338, 8, 81, 31));  
	m_scarMovingRect.emplace_back(sf::IntRect(421, 8, 81, 31)); 
	m_scarMovingRect.emplace_back(sf::IntRect(507, 8, 81, 31));  
	m_scarMovingRect.emplace_back(sf::IntRect(0, 48, 81, 31));
	m_scarMovingRect.emplace_back(sf::IntRect(88, 48, 81, 31));  
	m_scarMovingRect.emplace_back(sf::IntRect(169, 48, 81, 31)); 
//scar standing


	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(175, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(175, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(175, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(175, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(263, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(263, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(263, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(263, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(346, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(346, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(346, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(346, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(346, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(346, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(346, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(346, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(263, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(263, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(263, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(263, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(175, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(175, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(175, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(175, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));
	m_scarStandingRect.emplace_back(sf::IntRect(88, 307, 80, 35));

//scar rotation
	m_scarRotatingRect.emplace_back(sf::IntRect(0, 79, 80, 40));
	m_scarRotatingRect.emplace_back(sf::IntRect(168, 79, 80, 40));
	m_scarRotatingRect.emplace_back(sf::IntRect(257, 79, 80, 40));
	m_scarRotatingRect.emplace_back (sf::IntRect(337, 79, 80, 40));
	m_scarRotatingRect.emplace_back(sf::IntRect(420, 79, 80, 40));
	m_scarRotatingRect.emplace_back(sf::IntRect(420, 79, 80, 40));

 //scar attaking
	m_scarAttackingRect.emplace_back(sf::IntRect(0, 132, 86, 37));
	m_scarAttackingRect.emplace_back(sf::IntRect(87, 132, 83, 37));
	m_scarAttackingRect.emplace_back(sf::IntRect(171, 132, 82, 37)); 
	m_scarAttackingRect.emplace_back(sf::IntRect(254, 132, 87, 37));   
	m_scarAttackingRect.emplace_back(sf::IntRect(342, 132, 106, 37));   
	m_scarAttackingRect.emplace_back(sf::IntRect(453, 132, 97, 37)); 
	m_scarAttackingRect.emplace_back(sf::IntRect(0, 0, 80, 40));
	 
//scar jumping
	m_scarJumpingingRect.emplace_back(sf::IntRect(0, 215, 71, 36));
	m_scarJumpingingRect.emplace_back(sf::IntRect(72, 215, 68, 36));
	m_scarJumpingingRect.emplace_back(sf::IntRect(141, 215, 63, 36));
	m_scarJumpingingRect.emplace_back(sf::IntRect(215, 215, 65, 36));
	m_scarJumpingingRect.emplace_back(sf::IntRect(271, 206, 70, 45));
	m_scarJumpingingRect.emplace_back(sf::IntRect(342, 201, 69, 50));
	m_scarJumpingingRect.emplace_back(sf::IntRect(412, 197, 84, 53));
	m_scarJumpingingRect.emplace_back(sf::IntRect(496, 197, 81, 54));
	m_scarJumpingingRect.emplace_back(sf::IntRect(3, 252, 82, 41));
	m_scarJumpingingRect.emplace_back(sf::IntRect(3, 252, 82, 41));
	m_scarJumpingingRect.emplace_back(sf::IntRect(90, 250, 81, 40));
	m_scarJumpingingRect.emplace_back(sf::IntRect(191, 251, 77, 41));
	m_scarJumpingingRect.emplace_back(sf::IntRect(292, 254, 64, 39));
	m_scarJumpingingRect.emplace_back(sf::IntRect(379, 261, 64, 31));
	m_scarJumpingingRect.emplace_back(sf::IntRect(466, 261, 68, 32));
	m_scarJumpingingRect.emplace_back(sf::IntRect(0, 0, 80, 40));
//scar got hearted

	m_scargotheartRect.emplace_back(sf::IntRect(0, 360, 86, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(86, 357, 77, 46));
	m_scargotheartRect.emplace_back(sf::IntRect(166, 356, 76, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(244, 358, 76, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(328, 359, 77, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(412, 365, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));

	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));
	m_scargotheartRect.emplace_back(sf::IntRect(504, 356, 81, 45));
	m_scargotheartRect.emplace_back(sf::IntRect(0, 8, 81, 31));

//datascar
	datascar.loadFromFile("scar_data.png");
	m_scardata_faceRect.emplace_back(sf::IntRect(0,0, 100, 115));

	//healthBarscar
	healthBarscar.loadFromFile("scar_data.png");
	m_scardata_health_barRect.emplace_back(sf::IntRect(169, 27, 44, 34));
	m_scardata_health_barRect.emplace_back(sf::IntRect(216, 27, 44, 34));
	m_scardata_health_barRect.emplace_back(sf::IntRect(262, 27, 44, 34));
	m_scardata_health_barRect.emplace_back(sf::IntRect(310, 27, 44, 34));
	m_scardata_health_barRect.emplace_back(sf::IntRect(361, 27, 44, 34));
	m_scardata_health_barRect.emplace_back(sf::IntRect(421, 27, 44, 34));


	world1Tiles.loadFromFile("level1.png");
	m_World1Rect.emplace_back(sf::IntRect(68, 106,190 , 169)); //top left
	m_World1Rect.emplace_back(sf::IntRect(282,106 , 190, 169)); //ground
	m_World1Rect.emplace_back(sf::IntRect(487, 106, 190, 169)); // topright
	m_World1Rect.emplace_back(sf::IntRect(68, 290, 190, 169)); //left wall
	m_World1Rect.emplace_back(sf::IntRect(282, 290, 190, 169)); //inner floor
	m_World1Rect.emplace_back(sf::IntRect(487, 290, 190, 169)); //right wall
	m_World1Rect.emplace_back(sf::IntRect(68,477 , 190, 169)); //top left
	m_World1Rect.emplace_back(sf::IntRect(282, 477, 190, 169)); //top left
	m_World1Rect.emplace_back(sf::IntRect(487, 477, 190, 169)); //top left
	m_World1Rect.emplace_back(sf::IntRect(68, 660, 190, 169)); //top left
	m_World1Rect.emplace_back(sf::IntRect(282, 660, 190, 169)); //top left
	m_World1Rect.emplace_back(sf::IntRect(487, 660, 190, 169)); //top left

	m_world1Decoration.emplace_back(sf::IntRect(444,1179,95,95));	//hippo
	m_world1Decoration.emplace_back(sf::IntRect(288, 1068, 121, 215));	//giraphe

	m_world1Decoration.emplace_back(sf::IntRect(250, 1372, 148, 109));	//tree1
	m_world1Decoration.emplace_back(sf::IntRect(448, 1372, 147, 108));	//tree2
	m_world1Decoration.emplace_back(sf::IntRect(1121, 702, 98, 55));	//tree3 - bush
	m_world1Decoration.emplace_back(sf::IntRect(566, 1186, 151, 97));	//another animal - item1



	std::string string = "le2.png";
	world2Tiles.loadFromFile(string);
	m_World2Rect.emplace_back(sf::IntRect(70, 111, 192, 170)); //top left
	m_World2Rect.emplace_back(sf::IntRect(282, 111, 192, 170)); //ground
	m_World2Rect.emplace_back(sf::IntRect(487, 111, 192, 170)); // topright
	m_World2Rect.emplace_back(sf::IntRect(70, 296, 192, 170)); //left wall
	m_World2Rect.emplace_back(sf::IntRect(282, 296, 192, 169)); //inner floor
	m_World2Rect.emplace_back(sf::IntRect(487, 296, 190, 169)); //right wall
	m_World2Rect.emplace_back(sf::IntRect(70, 483, 190, 169)); //top left
	m_World2Rect.emplace_back(sf::IntRect(282, 483, 190, 169)); //top left
	m_World2Rect.emplace_back(sf::IntRect(487, 483, 190, 169)); //top left
	m_World2Rect.emplace_back(sf::IntRect(70, 666, 190, 169)); //top left
	m_World2Rect.emplace_back(sf::IntRect(282, 666, 190, 169)); //top left
	m_World2Rect.emplace_back(sf::IntRect(487, 666, 190, 169)); //top left

	
	m_world2Decoration.emplace_back(sf::IntRect(1360, 35, 361, 221));	//gigantic stone
	m_world2Decoration.emplace_back(sf::IntRect(1117, 108, 63, 58));	//small stone
	m_world2Decoration.emplace_back(sf::IntRect(1076,1350,138, 128));	//DIAMOND
	m_world2Decoration.emplace_back(sf::IntRect(1537, 967, 254, 314));	//warning
	m_world2Decoration.emplace_back(sf::IntRect(818, 1125, 65, 55));	//precius stone
	m_world2Decoration.emplace_back(sf::IntRect(1038,933, 250, 90));	//spikes

	world3Tiles.loadFromFile("Spritesheet_tileset.png");
	m_World3Rect.emplace_back(sf::IntRect(82,108 ,201 ,182 )); //top left
	m_World3Rect.emplace_back(sf::IntRect(283, 108,  201, 182)); //ground
	m_World3Rect.emplace_back(sf::IntRect(484,  108 , 201, 182)); //topright
	m_World3Rect.emplace_back(sf::IntRect(82,  290 , 201, 182)); //left wall
	m_World3Rect.emplace_back(sf::IntRect(283,  290 , 201, 182)); //inner floor
	m_World3Rect.emplace_back(sf::IntRect(484,290 , 201, 182)); //right wall
	m_World3Rect.emplace_back(sf::IntRect(82, 472, 201, 182)); //bottom left
	m_World3Rect.emplace_back(sf::IntRect(283,472, 201, 182)); //ceiling 
	m_World3Rect.emplace_back(sf::IntRect(484,472, 201, 182)); //bottom right
	m_World3Rect.emplace_back(sf::IntRect(82, 876, 201, 182)); //left island 
	m_World3Rect.emplace_back(sf::IntRect(283, 876, 201, 182)); //mid island
	m_World3Rect.emplace_back(sf::IntRect(484, 876, 201, 182)); //right island
	m_World3Rect.emplace_back(sf::IntRect(288, 1068, 119, 205)); //giraphh  
	m_World3Rect.emplace_back(sf::IntRect(444, 1179, 92, 96)); //hipo
	
	m_world3Decoration.emplace_back(sf::IntRect(444,1179,95,95));	//hippo
	m_world3Decoration.emplace_back(sf::IntRect(288, 1068, 121, 215));	//giraphe

	m_world3Decoration.emplace_back(sf::IntRect(250, 1372, 148, 109));	//tree1
	m_world3Decoration.emplace_back(sf::IntRect(448, 1372, 147, 108));	//tree2
	m_world3Decoration.emplace_back(sf::IntRect(1121, 702, 98, 55));	//tree3 - bush
	m_world3Decoration.emplace_back(sf::IntRect(566, 1186, 151, 97));	//another animal - item1




	gift.loadFromFile("gifts.png"); 
	m_giftshealiRect.emplace_back(sf::IntRect(24, 65, 20, 21)); //bug 1-healing
	m_giftshealiRect.emplace_back(sf::IntRect(47, 65, 20, 21)); //bug 2 bug-healing

	m_giftshealiRect.emplace_back(sf::IntRect(71, 65, 20, 21)); //bug 2 bug-healing
	m_giftshealiRect.emplace_back(sf::IntRect(94, 65, 20, 21)); //bug 2 bug-healing
	m_giftshealiRect.emplace_back(sf::IntRect(116, 65, 20, 21)); //bug 2 bug-healing
	m_giftshealiRect.emplace_back(sf::IntRect(24, 88, 20, 21)); //bug 2 bug-healing
	m_giftshealiRect.emplace_back(sf::IntRect(47, 88, 20, 21)); //bug 2 bug-healing
	m_giftshealiRect.emplace_back(sf::IntRect(73, 88, 20, 21)); //bug 2 bug-healing
	m_giftshealiRect.emplace_back(sf::IntRect(97, 88, 20, 21)); //bug 2 bug-healing
	m_giftshealiRect.emplace_back(sf::IntRect(120, 88, 20, 21)); //bug 2 bug-healing

	m_giftlifeRect.emplace_back(sf::IntRect(30, 134, 25, 21)); //life -extra one life
	m_giftlifeRect.emplace_back(sf::IntRect(56, 134, 25, 21)); //life -extra one life
	m_giftlifeRect.emplace_back(sf::IntRect(81, 134, 25, 21)); //life -extra one life
	m_giftlifeRect.emplace_back(sf::IntRect(108, 134, 25, 21)); //life -extra one life

	m_checkPointRect.emplace_back(sf::IntRect(5, 30, 35, 35)); //
	m_checkPointRect.emplace_back(sf::IntRect(44, 30,35, 35)); //
	m_checkPointRect.emplace_back(sf::IntRect(82, 30, 35, 35)); //
	//m_checkPointRect.emplace_back(sf::IntRect(119, 30, 30, 30)); //

	m_endPointRect.emplace_back(sf::IntRect(7, 0, 30, 30)); //
	m_endPointRect.emplace_back(sf::IntRect(43, 0, 30, 30)); //
	m_endPointRect.emplace_back(sf::IntRect(83, 0, 30, 30)); //
	m_endPointRect.emplace_back(sf::IntRect(123, 0, 30, 30)); //
	//àôùø ìäåñéó ôä àú äàåáé÷è ùì ùîéøú ùìá

//hedgehog walking
	hedgehog.loadFromFile("enemys.png");
	m_hedgehog_walking_Rect.emplace_back(sf::IntRect(2, 121, 35, 28));
	m_hedgehog_walking_Rect.emplace_back(sf::IntRect(38 , 121, 35, 28));
	m_hedgehog_walking_Rect.emplace_back(sf::IntRect(74 , 121, 35, 28));
	m_hedgehog_walking_Rect.emplace_back(sf::IntRect(111 , 121, 35, 28));
	m_hedgehog_walking_Rect.emplace_back(sf::IntRect(152 , 121, 35, 28));
	m_hedgehog_walking_Rect.emplace_back(sf::IntRect(193 , 121, 35, 28));

	//hesghog rotating
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(286, 121, 35, 28));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(317, 121, 35, 28));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(351, 121, 35, 28));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(5 ,169  , 36 ,29  ));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(5, 169, 36, 29));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(5, 169, 36, 29));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(5, 169, 36, 29));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(287,155 ,15 ,20 ));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(302,155 , 21,28 ));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(324,155 , 28,31 ));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(352,155 , 32,33 ));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(383,155 , 33, 33));
	m_hedgehog_rotatinging_Rect.emplace_back(sf::IntRect(416,155 , 34, 33));
	//lizard walking
	lizard.loadFromFile("enemys.png");
	m_lizard_walking_Rect.emplace_back(sf::IntRect(0, 16, 35, 20));
	m_lizard_walking_Rect.emplace_back(sf::IntRect(40, 16, 35, 20));
	m_lizard_walking_Rect.emplace_back(sf::IntRect(77, 14, 35, 20));
	m_lizard_walking_Rect.emplace_back(sf::IntRect(114, 16, 35, 20));
	m_lizard_walking_Rect.emplace_back(sf::IntRect(152, 16, 35, 20));
	m_lizard_walking_Rect.emplace_back(sf::IntRect(195, 16, 35, 20));
	m_lizard_walking_Rect.emplace_back(sf::IntRect(236, 15, 35, 20));
	m_lizard_walking_Rect.emplace_back(sf::IntRect(276, 14, 35, 20));
//lizard standing
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 19));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 19));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 19));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 16, 35, 19));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 16, 35, 19));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 16, 35, 19));
//lizard defeating
	m_lizard_defeatdingRect.emplace_back(sf::IntRect(287, 155, 15, 20));
	m_lizard_defeatdingRect.emplace_back(sf::IntRect(302, 155, 21, 28));
	m_lizard_defeatdingRect.emplace_back(sf::IntRect(324, 155, 28, 31));
	m_lizard_defeatdingRect.emplace_back(sf::IntRect(352, 155, 32, 33));
	m_lizard_defeatdingRect.emplace_back(sf::IntRect(383, 155, 33, 33));
	m_lizard_defeatdingRect.emplace_back(sf::IntRect(416, 155, 34, 33));

	m_lizard_standindRect.emplace_back(sf::IntRect(5 ,49, 30,30  ));
	m_lizard_standindRect.emplace_back(sf::IntRect( 42, 49, 30, 30 ));
	m_lizard_standindRect.emplace_back(sf::IntRect(72 , 49 ,30, 30));
	m_lizard_standindRect.emplace_back(sf::IntRect( 100 , 49, 30, 30));
	m_lizard_standindRect.emplace_back(sf::IntRect( 131, 49 ,50, 30 ));
	m_lizard_standindRect.emplace_back(sf::IntRect( 182, 49, 76, 30 ));
	m_lizard_standindRect.emplace_back(sf::IntRect(262, 49, 40, 28  ));
	m_lizard_standindRect.emplace_back(sf::IntRect(312, 49,40, 30  ));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 30));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 30));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 30));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 30));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 30));
	m_lizard_standindRect.emplace_back(sf::IntRect(0, 14, 35, 30));


	//m_vulture_standing
	vulture.loadFromFile("vulture.png");
	m_vulture_standindRect.emplace_back(sf::IntRect(11, 52, 51, 38));
	m_vulture_standindRect.emplace_back(sf::IntRect(60, 52, 38, 38));
	m_vulture_standindRect.emplace_back(sf::IntRect(102, 52, 51, 38));
	m_vulture_standindRect.emplace_back(sf::IntRect(163, 52, 51, 38));
	//m_vulture_walking
	m_vulture_walkindRect.emplace_back(sf::IntRect(10, 5, 50, 35));
	m_vulture_walkindRect.emplace_back(sf::IntRect(62, 5, 51, 34));
	m_vulture_walkindRect.emplace_back(sf::IntRect(114, 5, 51, 35));
	m_vulture_walkindRect.emplace_back(sf::IntRect(166, 5, 52, 34));
	m_vulture_walkindRect.emplace_back(sf::IntRect(222, 5, 50, 35));
	m_vulture_walkindRect.emplace_back(sf::IntRect(277, 5, 50, 34));
	m_vulture_walkindRect.emplace_back(sf::IntRect(331, 5, 50, 34));
	m_vulture_walkindRect.emplace_back(sf::IntRect(389, 5, 50, 34));
	//m_vulture_deafeating
	m_vulture_deafitindRect.emplace_back(sf::IntRect(10, 363, 61, 44));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(84, 363, 62, 48));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(155, 363, 56, 49));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(235, 363, 44, 49));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(297, 363, 39, 48));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(340, 363, 41, 48));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(379, 363, 41, 48));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(424, 363, 41, 48));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(465, 363, 41, 52));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(511, 363, 36, 54));
	m_vulture_deafitindRect.emplace_back(sf::IntRect(551, 363, 37, 53));
	//m_vulture_move_up
	m_vulture_move_updRect.emplace_back(sf::IntRect(15, 139, 33, 50));
	m_vulture_move_updRect.emplace_back(sf::IntRect(55, 139, 72, 47));
	m_vulture_move_updRect.emplace_back(sf::IntRect(139, 139, 93, 47));
	m_vulture_move_updRect.emplace_back(sf::IntRect(235, 139, 61, 63));

	//m_vulture_flying
	m_vulture_flying_Rect.emplace_back(sf::IntRect(8, 206, 74, 58));
	m_vulture_flying_Rect.emplace_back(sf::IntRect(103, 206, 86, 54));
	m_vulture_flying_Rect.emplace_back(sf::IntRect(202, 206, 65, 78));
	m_vulture_flying_Rect.emplace_back(sf::IntRect(288, 206, 57, 64));
	m_vulture_flying_Rect.emplace_back(sf::IntRect(360, 206, 83, 66));
//m_hyena_standind
	hyena.loadFromFile("hyenas.png");
	m_hyena_standindRect.emplace_back(sf::IntRect(98, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(98, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(181, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(181, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(258, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(258, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(335, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(335, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(409, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(409, 109, 65, 47));
	m_hyena_standindRect.emplace_back(sf::IntRect(98, 109, 65, 47));
//m_hyena_attaking

	m_hyena_attakRect.emplace_back(sf::IntRect(20, 441, 68, 46));
	m_hyena_attakRect.emplace_back(sf::IntRect(103, 439, 56, 51));
	m_hyena_attakRect.emplace_back(sf::IntRect(185, 438, 57, 51));
	m_hyena_attakRect.emplace_back(sf::IntRect(268, 438, 56, 52));
	m_hyena_attakRect.emplace_back(sf::IntRect(347, 431, 59, 50));
	m_hyena_attakRect.emplace_back(sf::IntRect(428, 434, 57, 53));
	m_hyena_attakRect.emplace_back(sf::IntRect(513, 435, 56, 55));
	m_hyena_attakRect.emplace_back(sf::IntRect(610, 435, 60, 53));
	m_hyena_attakRect.emplace_back(sf::IntRect(693, 435, 69, 51));
	m_hyena_attakRect.emplace_back(sf::IntRect(786, 435, 72, 51));
	m_hyena_attakRect.emplace_back(sf::IntRect(877, 437, 65, 49));
	m_hyena_attakRect.emplace_back(sf::IntRect(971, 439, 71, 48));
	m_hyena_attakRect.emplace_back(sf::IntRect(1067, 433, 79, 50));
	m_hyena_attakRect.emplace_back(sf::IntRect(1156, 433, 70, 51));
	m_hyena_attakRect.emplace_back(sf::IntRect(1240, 436, 56, 49));



//m_hyena_defeating
	m_hyena_defeating.emplace_back(sf::IntRect(18, 526, 56, 62));
	m_hyena_defeating.emplace_back(sf::IntRect(87 , 526 , 56, 62));
	m_hyena_defeating.emplace_back(sf::IntRect(156, 522, 58, 64));
	m_hyena_defeating.emplace_back(sf::IntRect(225 , 523 , 80 , 60 ));
	m_hyena_defeating.emplace_back(sf::IntRect(303 , 523 , 80, 60));
	m_hyena_defeating.emplace_back(sf::IntRect(395 , 523 , 80, 60));
	m_hyena_defeating.emplace_back(sf::IntRect(498 , 523 , 80, 60));
	m_hyena_defeating.emplace_back(sf::IntRect(606 , 523, 80, 60));
	m_hyena_defeating.emplace_back(sf::IntRect(713, 523, 80, 60));
	m_hyena_defeating.emplace_back(sf::IntRect(880, 523, 80, 60));

//hyena jumping
	m_hyena_jump.emplace_back(sf::IntRect(23 , 241 , 70, 80));
	m_hyena_jump.emplace_back(sf::IntRect(110 , 241, 70, 80));
	m_hyena_jump.emplace_back(sf::IntRect(201, 241, 70, 100));
	m_hyena_jump.emplace_back(sf::IntRect(297 , 241, 70, 100));
	m_hyena_jump.emplace_back(sf::IntRect(382 , 241, 70, 100));
	m_hyena_jump.emplace_back(sf::IntRect(479 , 241, 70, 100));
	m_hyena_jump.emplace_back(sf::IntRect(569 , 241, 87, 100));
	m_hyena_jump.emplace_back(sf::IntRect(682 , 241, 87, 100));
	m_hyena_jump.emplace_back(sf::IntRect(791 , 241, 87, 100));
	m_hyena_jump.emplace_back(sf::IntRect(899 , 241, 87, 100));
	m_hyena_jump.emplace_back(sf::IntRect(995 , 241, 87, 100));
	m_hyena_jump.emplace_back(sf::IntRect(1086 , 241, 87, 100));
	m_hyena_jump.emplace_back(sf::IntRect(1176 , 241, 87, 100));
	m_hyena_jump.emplace_back(sf::IntRect(1275 , 241, 87, 100));
//hyena rotation

	m_hyena_rotation.emplace_back(sf::IntRect(713, 534, 72, 43));
	m_hyena_rotation.emplace_back(sf::IntRect(800, 551, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(901, 543, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(800, 551, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(901, 543, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(800, 551, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(901, 543, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(800, 551, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(901, 543, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(800, 551, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(901, 543, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(800, 551, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(901, 543, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(800, 551, 89, 31));
	m_hyena_rotation.emplace_back(sf::IntRect(901, 543, 89, 31));

//hyena walking
	m_hyena_walking.emplace_back(sf::IntRect(99 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(186 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(271 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(355 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(445 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(535 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(617 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(705 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(796 , 172, 70,60));
	m_hyena_walking.emplace_back(sf::IntRect(880 , 172, 70,60));


	texture.loadFromFile("backgrounds1.png");
	backgrounds.emplace_back(texture);
	texture.loadFromFile("backgrounds2.png");
	backgrounds.emplace_back(texture);
	texture.loadFromFile("backgrounds3.png");
	backgrounds.emplace_back(texture);

}

Resources::~Resources()
{
	m_textures.clear();
	m_fonts.clear();
}

Resources& Resources::loadResources()
{
	static Resources loadTextures;
	return loadTextures;
}

sf::Texture& Resources::getTexture(pictures_t type)
{
	return m_textures[type];
}

sf::Texture& Resources::getScarTextures () { return scar;}
sf::Texture& Resources::getgiftTextures() { return gift; }
sf::Texture& Resources::gethyneaTextures() { return hyena; }
sf::Texture& Resources::gethedgehogTextures() { return hedgehog; }
sf::Texture& Resources::getlizardTextures() { return lizard; }
sf::Texture& Resources::getvultureTextures() { return vulture; }

sf::Texture& Resources::getWorldTexture(int worldNum)
{
	switch (worldNum)
	{
	case 1: return world1Tiles;
	case 2: return world2Tiles;
	case 3: return world3Tiles;
	default:
		break;
	}
	return world1Tiles;
	// TODO: insert return statement here
}

std::vector<sf::IntRect>& Resources::getWorldBlocks(int worldNum)
{
		switch (worldNum)
	{
	case 1: return m_World1Rect;
	case 2: return m_World2Rect;
	case 3: return m_World3Rect;
	default:
		break;
	}
	return m_World3Rect;
}


sf::Texture& Resources::getdatascar() { return datascar; }
sf::Texture& Resources::gethealthbarscar() { return healthBarscar; }

sf::Font& Resources::getFont(fontType type)
{
	return m_fonts[(int)type];
}