#include "Controller.h"


Controller::Controller(sf::RenderWindow& window, bool music, bool soundEffectsOn, int difficulty)
    : m_window(window) , musicOn(music), m_world(music,soundEffectsOn,difficulty)
{
    // create a view with its center and size
    m_view = sf::View(sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

    levelPassedBackground.setTexture(Resources::loadResources().getTexture(level_passed_background));
    levelPassedBackground.setScale(m_window.getSize().x / levelPassedBackground.getLocalBounds().width, m_window.getSize().y / levelPassedBackground.getLocalBounds().height);
    gameOverBackground.setTexture(Resources::loadResources().getTexture(fail_background));
    gameOverBackground.setScale(m_window.getSize().x / levelPassedBackground.getLocalBounds().width, m_window.getSize().y / levelPassedBackground.getLocalBounds().height);
    m_world.setMusic(musicOn);
    m_world.setSoundEffects(soundEffectsOn);

    sf::Color gameTextColor(sf::Color(252, 154, 64));

    for (int i = 0; i < OPTIONS; i++)	 //this is were we put the strongs.
    {
        m_texts.push_back(sf::Text(m_messages[i], Resources::loadResources().getFont(fontType::gameFont), GAME_FONT_SIZE));
        auto textRect = m_texts[i].getLocalBounds();
        m_texts[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

        m_texts[i].setOutlineThickness(2);
        m_texts[i].setOutlineColor(sf::Color::Black);

        m_texts[i].setFillColor(gameTextColor);
        m_texts[i].Bold;
    }

}
     
void Controller::run()
{
    while (m_window.isOpen())
    {    


        auto event = sf::Event{};
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }

        m_world.moveCharacters(dtClock.restart());
        
		if (m_world.checkFinish())
		{
            gameTime.restart();
			m_window.clear();
			m_window.display();

            if (m_world.gameOver())
            {
                if(m_world.failed())
                    displayFailedMessage();

                else  displayLevelPassed();
                m_window.clear();
                return; 
            }
           
            displayLevelPassed();
            gameTime.restart();
			dtClock.restart();
			m_world.create_board();
		}

		m_world.updateView(m_view);
        m_window.setView(m_view);
        m_window.clear();
        
        m_world.drawBackground(m_window);
        m_world.draw(m_window);
        displayStartMessage();
        m_window.display();
        if (pauseGame()) 
        {
            m_window.clear();
            return;
        }
    }
}

void Controller::displayLevelPassed()
{
    
    levelPassedBackground.setPosition(m_view.getCenter());
    levelPassedBackground.setOrigin(levelPassedBackground.getLocalBounds().width/2.0f, levelPassedBackground.getLocalBounds().height / 2.0f);
    sf::Clock clock;
	while (!(clock.getElapsedTime().asSeconds() > 3))
	{
		m_window.draw(levelPassedBackground);
		static bool sa = false;

		m_texts[goodJob].setPosition(m_view.getCenter());

		m_window.draw(m_texts[goodJob]);

		m_window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
			break;

	}
   
}

void Controller::displayStartMessage()
{
    if (gameTime.getElapsedTime().asSeconds() < 3.0f)
    {
        auto textPos = sf::Vector2f(m_view.getCenter().x, m_view.getCenter().y - 100.0f);
        if ((m_world.getLevelIndex()) % 2 == 0) 
        {
            m_texts[findSun].setPosition(textPos);
            m_window.draw(m_texts[findSun]);
        }
        else
        {
            m_texts[runMessage].setPosition(textPos);
            m_window.draw(m_texts[runMessage]);
        }
    }
}

void Controller::displayFailedMessage()
{
    gameOverBackground.setPosition(m_view.getCenter());
    gameOverBackground.setOrigin(gameOverBackground.getLocalBounds().width / 2.0f, gameOverBackground.getLocalBounds().height / 2.0f);
    sf::Clock clock;
    while (!(clock.getElapsedTime().asSeconds() > 3))
    {
        m_window.draw(gameOverBackground);
        
        m_window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
            break;

    }
}

bool Controller::pauseGame()
{

    bool escapePressed = false;
    bool exitGame = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
    {
        escapePressed = true;
        m_texts[pauseMessage].setPosition(m_view.getCenter());
        m_window.draw(m_texts[pauseMessage]);
        m_window.display();

        while (escapePressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                 break;
            
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
            {
                exitGame = true;
                break;
            }
        }
        dtClock.restart();
    }

    return exitGame;
}