#include "Toolbar.h"
#include <iostream>

Toolbar::Toolbar()
{

}
void Toolbar::SetNewToolbar(sf::Vector2f& vec)
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		m_positions[i] = sf::Vector2f(i * (float)P_SIZE, (vec.x + 1) * P_SIZE);
}

Toolbar::~Toolbar()
{
}

// load textures  and set the sprites to the toolbar
void Toolbar::set_toolbar()
{
	m_pTexture[DIGGER].loadFromFile("digger.png");
	m_pTexture[MONSTER].loadFromFile("monster.png");
	m_pTexture[DIAMOND].loadFromFile("diamond.png");
	m_pTexture[WALL].loadFromFile("wall.png");
	m_pTexture[SAVE].loadFromFile("save.png");
	m_pTexture[CLEAR].loadFromFile("clear.png");
	m_pTexture[ERASE].loadFromFile("erase.png");
	m_pTexture[STONE].loadFromFile("stone.png");

	for (size_t i = 0; i < NUM_OF_ICONS; i++)
	{
		m_sprite[i].setTexture(m_pTexture[i]);
		float x = m_sprite[0].getGlobalBounds().width;
		float y = m_sprite[0].getScale().y;
		m_sprite[i].setScale(sf::Vector2f(((float)P_SIZE / m_sprite[i].getGlobalBounds().height)
			, ((float)P_SIZE / m_sprite[i].getGlobalBounds().height)));
		m_sprite[i].setPosition(m_positions[i]);
	}

}
void Toolbar::setTitle()
{
	if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
		std::cout << "load font is failed" << std::endl;

	text.setFont(font);
	text.setFillColor(sf::Color::Cyan);
	text.setString("Digger Level Editor");
	text.setCharacterSize(23);
	text.setOutlineThickness(1);
	text.setOutlineColor(sf::Color::Blue);
	text.setPosition(sf::Vector2f(0, 0));
}



// draws the toolbar
void Toolbar::draw_toolbar(sf::RenderWindow& window)
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		window.draw(m_sprite[i]);
}

// draws the title
void Toolbar::draw_title(sf::RenderWindow& window)
{
	window.draw(text);
}

// returns the icons name
Toolbar_t Toolbar::get_icon_name(sf::Vector2f vec)
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
	{
		if (m_positions[i] == vec)
			return (Toolbar_t)i;
	}
	return (Toolbar_t)0;
}



