#pragma once

#include "Toolbar.h"
#include "Digger.h"
#include "Monster.h"
#include "Diamond.h"
#include "Stone.h"
#include "Wall.h"
#include <fstream>
#include "Icon.h"
#include <memory>

using std::fstream;
using std::cerr;

struct Item
{
	Toolbar_t _shape;
	Toolbar_t _color;
};

class Board
{
public:
	Board() : m_new_icon(), m_stone(), m_boardsize() {};
	Board(bool read);

	sf::Vector2f getBoardSize() { return m_boardsize; }
	sf::Vector2i get_mouse() { return m_mouse; };
	float getBoardHeight() { return m_boardsize.y; };
	bool getRead() { return m_read; }

	void draw_grid(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void mouse_button_released(sf::Event event, sf::RenderWindow& window);
	void draw_icons(sf::RenderWindow& window);
	void mouse_moved(sf::Event event, sf::RenderWindow& window);
	bool in_window(sf::Event event);

	~Board() {};

private:
	void setToolbarRect(sf::RectangleShape& rect, sf::Vector2f pos, sf::Color color);
	void save_grid();
	void clear_grid();
	void read_data();
	void read_from_usr();
	void set_board();

	bool open_file(fstream& input);
	bool m_digger_placed = false;
	bool m_read = false;
	bool erase_mode = true;

	int m_stone;

	Toolbar m_toolbar;
	Toolbar m_title;
	vector < vector < std::unique_ptr < Icon > > > m_grid;
	Item m_new_icon;

	sf::Vector2i m_mouse;
	sf::Vector2f m_boardsize;
	sf::Vector2f m_digger_pos;
	sf::RectangleShape m_shape_rect;
	sf::RectangleShape m_color_rect;
	sf::RectangleShape m_grid_rect;
	sf::RectangleShape m_moving_rect;
	sf::Sprite m_moving_icon;
	sf::Font font;
	sf::Text text;
};

