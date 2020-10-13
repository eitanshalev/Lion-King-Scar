#include "World.h"


//---------------------------------------------
//	here the definition of all the world block at a genery way!
//---------------------------------------------
World::World(bool &music, bool&sound, int &difficulty) : musicOn(music), soundEffects(sound), m_difficulty(difficulty)
{
	worlds.push_back("World.txt");
	worlds.push_back("World2.txt");
	worlds.push_back("World3.txt");

	m_background.setTexture(Resources::loadResources().getBackground()[worldNumber - 1]);
	m_background.setScale(VIEW_WIDTH / m_background.getLocalBounds().width, VIEW_HEIGHT / m_background.getLocalBounds().height);
	create_board();
}

void World::draw(sf::RenderWindow& window)
{

	for (auto& gameObject : gameObjects)
		gameObject->draw(window);

	m_player->showStats(window, m_viewCenter);//should be secound in order to be seen all over the  available objects
	

}

void World::collision()
{
	for_each_pair(gameObjects.begin(), gameObjects.end(), [](auto& a, auto& b) {
		if (collide(*a, *b))
		{
			processCollision(*a, *b);
		}
		});
}


bool collide(GameObject& a, GameObject& b)
{
	return	a.checkCollision(b.getRect()) || b.checkCollision(a.getRect());
}



void World::moveCharacters(sf::Time deltaTime)
{

	for (auto& figure : gameObjects)
	{
		figure->update(deltaTime.asSeconds()); // to change his location
	}
	collision();
	for (auto& figure : gameObjects) {

		Hyena* hyena = dynamic_cast<Hyena*>(figure.get());
		if (hyena)
			hyena->checkPlayerLocation(m_player->getLocation());

		Vulture* vulture = dynamic_cast<Vulture*>(figure.get());
		if (vulture)
			vulture->checkPlayerLocation(m_player->getLocation());
	}


	for (int i = 0; i < gameObjects.size(); i++)
		if (!gameObjects[i]->exists())
			gameObjects.erase(gameObjects.begin() + i);
	


	for (auto& figure : gameObjects)
	{
		figure->move(deltaTime.asSeconds()); // to change his location
		figure->animation(deltaTime.asMilliseconds()); /// to visualize his animation	
	}

	m_player->checkLimits(m_viewCenter);
	if (m_player->isOut()) // in case the main player lost one life
	{
		if (m_player->isDead())
		{
			std::cout << "player is Dead\n";
			levelFailed = true;
			finish();
			return;
		}
		m_player->setHealth();
		resetView = true;

		for (auto& figure : gameObjects)
			figure->resetLocation();
		
	}
	if (m_player->finished())
	{
		finish();
		return;
	}
}

void World::create_board()
{
	m_levelFinished = false;

	if (musicOn) {
		switch (levelIndex)
		{
		case 0: 	m_music.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_level_1));
			
			break;
		case 1: m_music.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_level_2));
			break;
		case 2:	m_music.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_level_3));
			break;
		default: break;
		}
		m_music.setLoop(true);
		m_music.play();
	}

	
	
	//Read World.txt:
	std::ifstream newlevel;
	std::cout << worlds[levelIndex] << std::endl;
	newlevel.open(worlds[levelIndex].c_str());

		if (!newlevel.is_open())	//cant open file. throw exception
			throw(std::exception());
		
	std::string tmp;
	while (std::getline(newlevel, tmp)) //leading corrent level
	{
		_world_file.push_back(tmp);
	}


	if (true) //end reading leveles
		newlevel.close(); // maybey use a bool to say that the game was over and congratulations.


	//int randomObjectIndex = 0;
	for (int y = 0; y < _world_file.size(); y++)
		for (int x = 0; x < _world_file[y].length(); x++)
		{
			sf::Vector2f location((float)(x * WORLD_BLOCK_SIZE_X), (float) (y * WORLD_BLOCK_SIZE_Y));
			//sf::Vector2f location(x * WINDOW_SIZE_X / 2, y * WINDOW_SIZE_Y / 2);
			char c = _world_file[y][x];
			if (c != ' ')
				addObject(c, location);

		}


	for (int y = 0; y < _world_file.size(); y++)
		for (int x = 0; x < _world_file[y].length(); x++)
		{
			float X = (float) (x * WORLD_BLOCK_SIZE_X);
			float Y = (float)(y * WORLD_BLOCK_SIZE_Y);
			sf::Vector2f location(X, Y);
			//sf::Vector2f location(x * WINDOW_SIZE_X / 2, y * WINDOW_SIZE_Y / 2);
			char c = _world_file[y][x];
			if (c != ' ')
				addCharacter(c, location);

		}
}
void World::drawBackground(sf::RenderWindow &window)
{
	m_background.setOrigin(m_background.getTextureRect().width / 2.0f, m_background.getTextureRect().height /2.0f);
	m_background.setPosition(m_viewCenter);
	window.draw(m_background);
}

void World::finish()
{
	m_levelFinished = true;
	levelIndex++;
	
	//if (levelIndex % 3 == 0)
		worldNumber++;
		if ((worldNumber == worlds.size()+1) || levelFailed)
			m_gameOver = true;
		else m_background.setTexture(Resources::loadResources().getBackground()[(float)worldNumber - 1]);


	index = 0;
	gameObjects.clear();
	_world_file.clear();
	resetView = true;
}

void World::updateView(sf::View& view)
{
	if(resetView)
	{
		view.setCenter(getplayerPosition());
			resetView = false;
			m_player->resetSpeed();
		viewSpeedClock.restart();
		viewSpeed = 4.0f;
	}
		
	if (levelIndex % 2 == 1)
		{
			if(viewSpeedClock.getElapsedTime().asSeconds() > 5.0f)
				{
					viewSpeed *= 1.1;
					m_player->speedUp();
					viewSpeedClock.restart();
				}
			view.move(viewSpeed, 0);
		}
	
	else view.setCenter(getplayerPosition());
	
	m_viewCenter = view.getCenter();

	

}

void World::setMusic(const bool& music)
{
	musicOn = music;
}

void World::setSoundEffects(const bool& sound)
{
	soundEffects = sound;
}

void World::addGift(giftType gt, const sf::Vector2f& sfLocation)
{
	switch (gt)
	{
	case giftType::_healing:
			gameObjects.push_back(std::make_unique< HealthGift >(sfLocation, gt, soundEffects));
			break;
	case giftType::_Onelife:
			gameObjects.push_back(std::make_unique< LifeGift >(sfLocation, gt, soundEffects));
			break;
	case giftType::checkPoint:
			gameObjects.push_back(std::make_unique< CheckPointGift >(sfLocation, gt, soundEffects));
			break;
	case giftType::endPoint:
			gameObjects.push_back(std::make_unique< SunGift >(sfLocation, gt, soundEffects));
			break;
	default: break;
	}
}

void World::addCharacter(char c, sf::Vector2f& sfLocation)
{
	
	 index = (int) gameObjects.size();
	bool foundObject = true;
	switch (c)
	{
	case 'H':
		gameObjects.push_back(std::make_unique< Hyena >(sfLocation, soundEffects,m_difficulty));
		break;
	case 'S':
		gameObjects.push_back(std::make_unique< Player >(sfLocation,soundEffects));
		m_player = dynamic_cast<Player*>(gameObjects[index].get());
		break;
	case 'V':
		gameObjects.push_back(std::make_unique< Vulture >(sfLocation, soundEffects,m_difficulty));
		break;
	case 'h':
		gameObjects.push_back(std::make_unique< Hedgehog >(sfLocation));
		break;
	case 'l':
		gameObjects.push_back(std::make_unique< Lizard >(sfLocation));
		break;
	default:
		foundObject = false;

	}

	if (foundObject)
		index++;

}

void World::addObject(char c, sf::Vector2f& sfLocation)
{
	
	block_type_t blocktype;// = -1;
	decoration_type_t decorationType;
	giftType gt;
	bool foundObject = true;

	objectOption option = objectOption::block;
	switch (c)
	{
	case '<':
		option = objectOption::block;
		blocktype = block_type_t::left_island;
		break;
	case '>':
		option = objectOption::block;
		blocktype = block_type_t::right_island;
		break;
	case '-':
		option = objectOption::block;
		blocktype = block_type_t::mid_island;
		break;
	case '=':
		option = objectOption::block;
		blocktype = block_type_t::ground;
		break;
	case '*':
		option = objectOption::block;
		blocktype = block_type_t::ceiling;
		break;
	case '|':
		option = objectOption::block;
		blocktype = block_type_t::inner_floor;
		break;
	case '(':
		option = objectOption::block;
		blocktype = block_type_t::topLeft;
		break;
	case ')':
		option = objectOption::block;
		blocktype = block_type_t::topRight;
		break;
	case '.':
		option = objectOption::block;
		blocktype = block_type_t::botRight;
		break;
	case ',':
		option = objectOption::block;
		blocktype = block_type_t::botLeft;
		break;
	case '_':
		option = objectOption::block;
		blocktype = block_type_t::ceiling;
		break;
	case ':':
		option = objectOption::block;
		blocktype = block_type_t::left_wall;
		break;
	case ';':
		option = objectOption::block;
		blocktype = block_type_t::right_wall;
		break;
		/*GIFTS*/
	case 'L': //ADD 1 LIfE
		option = objectOption::gift;
		gt = giftType::_Onelife;
		break;
	case '+'://ADD HEALING 
		option = objectOption::gift;
		gt = giftType::_healing;
		break;
	case 'C':
		option = objectOption::gift;
		gt = giftType::checkPoint;
		break;
	case '1':
		option = objectOption::background;
		decorationType = decoration_type_t::animal1;
		break;
	case '2':
		option = objectOption::background;
		decorationType = decoration_type_t::animal2;
		break;
	case '3':
		option = objectOption::background;
		decorationType = decoration_type_t::tree1;
		break;
	case '4':
		option = objectOption::background;
		decorationType = decoration_type_t::tree2;
		break;
	case '5':
		option = objectOption::background;
		decorationType = decoration_type_t::tree3;
		break;
	case '6':
		option = objectOption::background;
		decorationType = decoration_type_t::item1;
		break;
	case '7':
		option = objectOption::background;
		decorationType = decoration_type_t::item2;
		break;
	case 'D':
		option = objectOption::gift;
		gt = giftType::endPoint;
		break;
	default:
		foundObject = false;
		break;
	}



	if (foundObject)
		if (option == objectOption::block) {
			if (blocktype == block_type_t::inner_floor)
				gameObjects.push_back(std::make_unique< SpecialBlock >(sfLocation, blocktype, worldNumber));
			else gameObjects.push_back(std::make_unique< StaticBlock >(sfLocation, blocktype, worldNumber));

		}
		else if (option == objectOption::background)
			gameObjects.push_back(std::make_unique< Decoration >(sfLocation, decorationType, worldNumber));

		else
			addGift(gt,sfLocation);
			

		

}