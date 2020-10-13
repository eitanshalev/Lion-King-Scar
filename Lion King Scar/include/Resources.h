#pragma once

#include "Globals.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>


//-----------------------------------------------------------------
//			_______________Resources________________________
//		This Cass is of our Resources
//		here we do a singletone that get all the resourses of the game/
//		HERE WE GET PICURES, MANY KIND OF BACKSOUND , OR SONGS!
//-----------------------------------------------------------------
class Resources
{
public:
	~Resources();
	sf::Texture& getdatascar();
	sf::Texture& getgiftTextures();
	sf::Texture& gethealthbarscar();
	sf::Texture& gethyneaTextures();
	sf::Texture& getScarTextures();
	sf::Texture& getlizardTextures();
	sf::Font& getFont(fontType type);
	static Resources& loadResources();
	sf::Texture& getvultureTextures();
	sf::Texture& gethedgehogTextures();
	sf::Texture& getTexture(pictures_t type);
	std::vector<sf::Texture>& getBackground();
	sf::Texture& getWorldTexture(int worldNumber);
	std::vector<sf::IntRect>& getDecoration(int worldNum);
	std::vector<sf::IntRect>& getWorldBlocks(int worldNumber);
	std::vector<sf::IntRect>& getEndPoint() { return m_endPointRect; }
	std::vector<sf::IntRect>& getgiftsLife() { return m_giftlifeRect; }
	std::vector<sf::IntRect>& getCheckPoint() { return m_checkPointRect; }
	std::vector<sf::IntRect>& getScarStanding() { return m_scarStandingRect; }
	std::vector<sf::IntRect>& getgiftshealing() { return m_giftshealiRect; }
	std::vector<sf::IntRect>& getscarDataFace() { return m_scardata_faceRect; }
	std::vector<sf::IntRect>& getscarhealthBar() { return m_scardata_health_barRect; }
	std::vector<sf::IntRect>& getScarMovingRect() { return m_scarMovingRect; }
	std::vector<sf::IntRect>& getScarJumpingRect() { return m_scarJumpingingRect; }
	std::vector<sf::IntRect>& gethyenaWalkingRect() { return  m_hyena_walking; }
	std::vector<sf::IntRect>& gethyenaJumpingRect() { return	m_hyena_jump; }
	std::vector<sf::IntRect>& getScargotheartRect() { return m_scargotheartRect; }
	std::vector<sf::IntRect>& getScarRotationRect() { return m_scarRotatingRect; }
	std::vector<sf::IntRect>& gethyenaRotationRect() { return  m_hyena_rotation; }
	std::vector<sf::IntRect>& getScarAttackingRect() { return m_scarAttackingRect; }
	std::vector<sf::IntRect>& gethyenastandingRect() { return m_hyena_standindRect; }
	std::vector<sf::IntRect>& gethyenasattakingRect() { return m_hyena_attakRect; }
	std::vector<sf::IntRect>& gethyenadefeatingRect() { return	m_hyena_defeating; }
	std::vector<sf::IntRect>& getlizardstandingRect() { return m_lizard_standindRect; }
	std::vector<sf::IntRect>& getvueltureflyingRect() { return m_vulture_flying_Rect; }
	std::vector<sf::IntRect>& getvulturetwalkingRect() { return m_vulture_walkindRect; }
	sf::SoundBuffer& getSoundBuffer(sound_t soundType) { return m_sounds[(int)soundType]; }
	std::vector<sf::IntRect>& getlizardwalkingingRect() { return m_lizard_walking_Rect; }
	std::vector<sf::IntRect>& getheadghogrotatingRect() { return m_hedgehog_rotatinging_Rect; }
	std::vector<sf::IntRect>& getlizardsdefeatingRect() { return m_lizard_defeatdingRect; }
	std::vector<sf::IntRect>& getvulturetstandingRect() { return m_vulture_standindRect; }
	std::vector<sf::IntRect>& getvuelturedefeatingRect() { return m_vulture_deafitindRect; }
	std::vector<sf::IntRect>& getvulturetmoving_up_Rect() { return m_vulture_move_updRect; }
	std::vector<sf::IntRect>& getheadghogwalkingingRect() { return m_hedgehog_walking_Rect; }
private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//-------------------------------------game object's textures----------------------------
	sf::Texture scar;
	sf::Texture gift;
	sf::Texture hyena;
	sf::Texture	lizard;
	sf::Texture vulture;
	sf::Texture datascar;
	sf::Texture hedgehog;
	sf::Texture healthBarscar;

	//-------------------------------------base vector textures------------------------------
	std::vector<sf::Font> m_fonts;
	std::vector<sf::Image> m_images;
	std::vector<sf::SoundBuffer> m_sounds;
	//---------------------
	std::vector<sf::Texture> m_textures;
	std::vector<sf::IntRect> m_scarMovingRect;
	std::vector<sf::IntRect> m_scarStandingRect;
	std::vector<sf::IntRect> m_scarRotatingRect;
	std::vector<sf::IntRect> m_scargotheartRect;
	std::vector<sf::IntRect> m_scardata_faceRect;
	std::vector<sf::IntRect> m_scarAttackingRect;
	std::vector<sf::IntRect> m_scarJumpingingRect;
	std::vector<sf::IntRect> m_scardata_health_barRect;

	std::vector<sf::IntRect>  m_giftshealiRect, m_giftlifeRect, m_checkPointRect, m_endPointRect;

	//-------------------------------------vulture's textures----------------------------
	std::vector<sf::IntRect> m_vulture_standindRect;
	std::vector<sf::IntRect> m_vulture_walkindRect;
	std::vector<sf::IntRect> m_vulture_deafitindRect;
	std::vector<sf::IntRect> m_vulture_move_updRect;
	std::vector<sf::IntRect> m_vulture_flying_Rect;

	//-------------------------------------_hyena's textures----------------------------
	std::vector<sf::IntRect> m_hyena_standindRect;
	std::vector<sf::IntRect> m_hyena_attakRect;
	std::vector<sf::IntRect> m_hyena_defeating;
	std::vector<sf::IntRect> m_hyena_jump;
	std::vector<sf::IntRect> m_hyena_rotation;
	std::vector<sf::IntRect> m_hyena_walking;
	//-------------------------------------_hedgehog's textures----------------------------
	std::vector<sf::IntRect> m_hedgehog_walking_Rect;
	std::vector<sf::IntRect> m_hedgehog_rotatinging_Rect;

	//-------------------------------------_lizard's textures----------------------------
	std::vector<sf::IntRect> m_lizard_walking_Rect;
	std::vector<sf::IntRect> m_lizard_standindRect;
	std::vector<sf::IntRect> m_lizard_defeatdingRect;

	//-------------------------------------_World1Rect's textures----------------------------
	std::vector<sf::IntRect> m_World1Rect;
	std::vector<sf::IntRect> m_World2Rect;
	std::vector<sf::IntRect> m_World3Rect;

	//-------------------------------------_world1Tilest's textures----------------------------
	sf::Texture world1Tiles;
	sf::Texture world2Tiles;
	sf::Texture world3Tiles;

	//-------------------------------------_m_world1Decoration's textures---------------------------
	std::vector<sf::IntRect> m_world1Decoration;
	std::vector<sf::IntRect> m_world2Decoration;
	std::vector<sf::IntRect> m_world3Decoration;

	std::vector < sf::Texture> backgrounds;
};