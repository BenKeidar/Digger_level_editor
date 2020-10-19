#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

using std::vector;

// icon names
enum Toolbar_t { DIGGER, MONSTER, DIAMOND, WALL, STONE, ERASE, CLEAR, SAVE, NONE };

const int NUM_OF_ICONS = 8; // number of icons
const unsigned int P_SIZE = 40; // pixel size

class Toolbar
{
public:
	Toolbar();
	~Toolbar();

	void set_toolbar();
	void setTitle();
	void SetNewToolbar(sf::Vector2f& vec);

	void draw_toolbar(sf::RenderWindow& window);
	void draw_title(sf::RenderWindow& window);

	Toolbar_t get_icon_name(sf::Vector2f vec);
	sf::Sprite get_icon_sprite(Toolbar_t icon_name) { return m_sprite[icon_name]; };

protected:
	sf::Vector2f m_positions[NUM_OF_ICONS];
	sf::Color m_color;
	sf::Texture m_pTexture[NUM_OF_ICONS];
	sf::Sprite m_sprite[NUM_OF_ICONS];

private:
	sf::Font font;
	sf::Text text;
};
