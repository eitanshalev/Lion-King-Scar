#include "..\include\Menu.h"
//05/06/2020

Menu::Menu() 
{
	
	window.create(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Lion King: The Official Game");
	window.setFramerateLimit(FRAME_LIMIT);
	setMenu();
	m_sound = true;
	m_music = true;
	m_difficaulty = 1;
}

void Menu::setMenu()
{
	 backgroundMusic.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_menu_sound));
	clickSound.setBuffer(Resources::loadResources().getSoundBuffer(sound_t::s_Botton_Click));
	//clickSound.play();
	backgroundMusic.play();


	m_background.setTexture(Resources::loadResources().getTexture(background_menu));
	m_background.setScale(WINDOW_SIZE_X / m_background.getLocalBounds().width, WINDOW_SIZE_Y / m_background.getLocalBounds().height);


	for (int i = 0; i < NUM_OF_OPTIONS; i++)	 //this is were we put the strongs.
	{
		menu.push_back(sf::Text(m_optionsStrings[i], Resources::loadResources().getFont(fontType::menuFont), MENU_FONT_SIZE));
		auto textRect = menu[i].getLocalBounds();
		menu[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		menu[i].setPosition(sf::Vector2f(WINDOW_SIZE_X / 2.0f, WINDOW_SIZE_Y / 2.0f - 100 + FONTMENUSAPACE * i));

		menu[i].setOutlineThickness(TWO_DIRECTIONS);
		menu[i].setOutlineColor(sf::Color::Black);

		menu[i].setFillColor(sf::Color::Magenta);
		menu[i].Bold;
	}

	for (int i = 0; i < OPTIONS; i++)
	{
		m_options.push_back(sf::Text(m_menuOptions[i], Resources::loadResources().getFont(fontType::menuFont), MENU_FONT_SIZE));
		auto textRect = m_options[i].getLocalBounds();
		m_options[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		m_options[i].setPosition(sf::Vector2f(WINDOW_SIZE_X / 2.0f, WINDOW_SIZE_Y / 2.0f - 100 + FONTMENUSAPACE * i));
		m_options[i].setOutlineThickness(TWO_DIRECTIONS);
		m_options[i].setOutlineColor(sf::Color::Black);	
		
		m_options[i].setFillColor(sf::Color::Magenta);
		m_options[i].Bold;
	}

	m_instructions = sf::Text(instructions, Resources::loadResources().getFont(fontType::gameFont), GAME_FONT_SIZE);
	auto textRect = m_instructions.getLocalBounds();
	m_instructions.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_instructions.setPosition(sf::Vector2f(WINDOW_SIZE_X / 2.0f, WINDOW_SIZE_Y / 2.0f));
	m_instructions.setOutlineThickness(2);
	m_instructions.setOutlineColor(sf::Color::Black);
	m_instructions.setFillColor(sf::Color(252, 154, 64));
	m_instructions.Bold;

}


void Menu::run()
{

	while (window.isOpen())
	{
		
		window.draw(m_background);
		draw(window);
		window.display();

		//handle events fron user...
		auto event = sf::Event{};
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed || gameOver)
			{
				window.close();
				return;
			}

			switch (event.type)
			{
			case sf::Event::MouseMoved:
			{
				const auto locationmove = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
				highlight(locationmove);
				break;
			}
			case sf::Event::MouseButtonReleased:
			{

				select();
				break;
			}


			};



		}

		//print backround
		//manage tool bar
		// manage user keboard pressed
	}
}


void Menu::select()
{

	if (!inOptions)
		for (int i = 0; i < menu.size(); i++)
		{
			if (menu[i].getFillColor() == sf::Color::Green)
				execCommand((options)i);
		}
	else
	{
		for (int i = 0; i < m_options.size(); i++)
		{
			if (m_options[i].getFillColor() == sf::Color::Green)
				execCommand((options)i);
		}
	}

}

void Menu::execCommand( options option)
{
	clickSound.play();
	if (!inOptions) 
		switch (option)  //here me convert the command to its real purpose.
		{
		case options::Start_Game:
		{
			
			backgroundMusic.stop();
			Controller controller(window, m_music ,m_sound, m_difficaulty+1);
			controller.run();
			window.create(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Lion King: The Official Game");
			window.setFramerateLimit(FRAME_LIMIT);
			//showGameOver(window); //---needs to be done.

			break;
		}


		case options::Options:
			inOptions = true;
			break;
		 case options::game_instructions:
			 showInstructions();
			break;
		case options::exit:
			gameOver = true;
		break;
		}

	else
		switch ((menuOptions)option)  //here me convert the command to its real purpose.
		{
		case menuOptions::music:
		{
			if (m_music) {
				m_options[(int)menuOptions::music].setString(m_menuOptions[OPTIONS]);// = m_menuOptions[]
				backgroundMusic.stop();
			}
			else
			{
				m_options[(int)menuOptions::music].setString(m_menuOptions[(int)menuOptions::music]);
				backgroundMusic.play();
			}
			m_music = !m_music;
			//std::cout << m_music;
		}
		break;
		case menuOptions::sound:
		{
			if (m_sound)
				m_options[(int)menuOptions::sound].setString(m_menuOptions[5]);
			else
				m_options[(int)menuOptions::sound].setString(m_menuOptions[(int)menuOptions::sound]);

			m_sound = !m_sound;
		}
		break;
		case menuOptions::difficulty:
		{
			m_difficaulty = (m_difficaulty + 1) % DIFFICULT_LEVEL;
			m_options[(int)menuOptions::difficulty].setString(difficultyString[m_difficaulty]);
			
		}
			break;
		case menuOptions::backToMenu:
			inOptions = false;
			break;
		default:
			break;
	
		}

	
}



void Menu::highlight(const sf::Vector2f& location)
{
	
	if (!inOptions)
		for (auto& text : menu)
		{
			if (text.getGlobalBounds().contains(location))
			{
				text.setFillColor(sf::Color::Green);
				//clickSound.play();
			}
			else text.setFillColor(sf::Color::Magenta);
		}

	else {
		for (auto& option : m_options)
		{
			if (option.getGlobalBounds().contains(location))
			{
				option.setFillColor(sf::Color::Green);
				//clickSound.play();
			}
			else option.setFillColor(sf::Color::Magenta);
		}
	}
}

void Menu::showInstructions()
{

	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || !(sf::Event::MouseButtonReleased))
	{
		window.clear();
		window.draw(m_background);
		window.draw(m_instructions);
		window.display();
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	if (!inOptions)
		for (auto& text : menu)
			window.draw(text);

	else
		for (auto& option : m_options)
			window.draw(option);

		
}