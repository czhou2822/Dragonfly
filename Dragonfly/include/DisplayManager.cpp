#include <iostream>

#include "DisplayManager.h"



df::DisplayManager::DisplayManager()
	:m_p_window(nullptr)
	,m_window_horizontal_pixels(WINDOW_HORIZONTAL_PIXELS_DEFAULT) // Horizontal pixels in window.
	,m_window_vertical_pixels(WINDOW_VERTICAL_PIXELS_DEFAULT)   // Vertical pixels in window.
	,m_window_horizontal_chars(WINDOW_HORIZONTAL_CHARS_DEFAULT)  // Horizontal ASCII spaces in window.
	,m_window_vertical_chars(WINDOW_VERTICAL_CHARS_DEFAULT)    // Vertical ASCII spaces in window.
{
	setType("DisplayManager");
}

df::DisplayManager& df::DisplayManager::getInstance()
{
	static DisplayManager displayManager;
	return displayManager;
}

int df::DisplayManager::startUp()
{	
	//if window exists, return
	if (m_p_window)	
	{
		return 0;
	}

	//else create
	m_p_window = new sf::RenderWindow(sf::VideoMode(m_window_horizontal_pixels, m_window_vertical_pixels), "SFML-Hello world");
	if (!m_p_window)
	{
		std::cout << "Error! Unable to allocate RenderWindow" << std::endl;
		return -1;
	}


	m_p_window->setMouseCursorVisible(false);
	
	m_p_window->setVerticalSyncEnabled(true);


	//set font
	if (m_font.loadFromFile("df-font.ttf") == false)
	{
		std::cout << "Error! Unable to allocate 'df-font.ttf'." << std::endl;
		return -1;
	}
	
	Manager::startUp();
	return 0;


}

void df::DisplayManager::shutDown()
{
	Manager::shutDown();
}

int df::DisplayManager::drawCh(Vector world_pos, char ch, Color color) const
{
	if (!m_p_window)
	{
		return -1;
	}

	//convert spaces(x,y) to pixels(x,y)
	Vector pixel_pos = spacesToPixels(world_pos);

	//draw background rectangle since text is "see through" in SFML
	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	rectangle.setPosition(pixel_pos.getX() - charWidth() / 10,
						  pixel_pos.getY() + charHeight() / 5);
	m_p_window->draw(rectangle);

	//create character text to draw
	static sf::Text text("", m_font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold);

	//scale to right size
	if (charWidth() < charHeight())
	{
		text.setCharacterSize(charWidth() * 2);
	}
	else
	{
		text.setCharacterSize(charHeight() * 2);
	}

	//set SFML color based on Dragonfly color
	sf::Color newColor;
	switch (color)
	{
	case df::BLACK:
		newColor = sf::Color::Black;
		break;
	case df::RED:
		newColor = sf::Color::Red;
		break;
	case df::GREEN:
		newColor = sf::Color::Green;
		break;
	case df::YELLOW:
		newColor = sf::Color::Yellow;
		break;
	case df::BLUE:
		newColor = sf::Color::Blue;
		break;
	case df::MAGENTA:
		newColor = sf::Color::Magenta;
		break;
	case df::CYAN:
		newColor = sf::Color::Cyan;
		break;
	case df::WHITE:
		newColor = sf::Color::White;
		break;
	default:
		break;
	}
	text.setFillColor(newColor);


	text.setPosition(pixel_pos.getX(), pixel_pos.getY());

	m_p_window->draw(text);




	return 0;
}

int df::DisplayManager::drawString(Vector world_pos, std::string str, Justification just, Color color) const
{
	Vector starting_pos = world_pos;
	switch (just)
	{
	case df::CENTER_JUSTIFIED:
		starting_pos.setX(world_pos.getX() - str.size() / 2);
		break;
	case df::RIGHT_JUSTIFIED:
		starting_pos.setX(world_pos.getX() - str.size());
		break;
	case df::LEFT_JUSTIFIED:
	default:
		break;
	}

	for (int i = 0; i < str.size(); i++)
	{
		Vector temp_pos(starting_pos.getX() + i, starting_pos.getY());
		drawCh(temp_pos, str[i], color);
	}


	return 0;
}

int df::DisplayManager::swapBuffers()
{
	if (!m_p_window)
	{
		return -1;
	}

	m_p_window->display();

	m_p_window->clear();

	return 0;
}

float df::charHeight(void)
{
	float output = (float) DM.getVerticalPixels() / (float) DM.getVertical();
	return output;
}

float df::charWidth(void)
{
	float output = (float) DM.getHorizontalPixels() / (float) DM.getHorizontal();
	return output;
}

df::Vector df::spacesToPixels(Vector spaces)
{
	Vector output;
	output.setXY(spaces.getX() * charWidth(), spaces.getY() * charHeight());
	return output;
}

df::Vector df::pixelsToSpaces(Vector pixels)
{
	Vector output;
	output.setXY(pixels.getX() / charWidth(), pixels.getY() / charHeight());
	return output;
}
