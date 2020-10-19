#include <iostream>
#include "Board.h"


// board c-tor 
Board::Board(bool read) : m_read(read)
{
	m_new_icon._shape = NONE;
	m_new_icon._color = NONE;
	m_moving_rect.setSize(sf::Vector2f((float)P_SIZE, (float)P_SIZE));
	m_moving_rect.setFillColor(sf::Color::Transparent);
	read_data();
	m_toolbar.SetNewToolbar(m_boardsize);
	m_toolbar.set_toolbar();
	m_title.setTitle();
}

// draws the grid
void Board::draw_grid(sf::RenderWindow& window)
{
	float toolbar_gap = P_SIZE;
	sf::RectangleShape col(sf::Vector2f(3, (P_SIZE * m_boardsize.x)));
	sf::RectangleShape row(sf::Vector2f((P_SIZE * m_boardsize.y), 3));
	for (size_t i = 0; i < m_boardsize.y; i++) // columns
	{
		col.setFillColor(sf::Color::White);
		col.setOutlineThickness(1);
		col.setOutlineColor(sf::Color::Blue);
		col.setPosition((float)(i * P_SIZE), (float)P_SIZE);
		window.draw(col);
	}

	for (size_t i = 0; i < m_boardsize.x; i++) //rows
	{
		row.setFillColor(sf::Color::White);
		row.setOutlineThickness(1);
		row.setOutlineColor(sf::Color::Blue);
		row.setPosition(0, toolbar_gap);
		window.draw(row);
		toolbar_gap += P_SIZE;
	}
}

// draw all the relevent objects 
void Board::draw(sf::RenderWindow& window)
{
	draw_grid(window);
	m_toolbar.draw_toolbar(window);
	m_title.draw_title(window);
	window.draw(m_shape_rect);
	window.draw(m_color_rect);
	draw_icons(window);
	erase_mode ? window.draw(m_moving_rect) : window.draw(m_moving_icon);
}

// in case the user clicked on the mouse
void Board::mouse_button_released(sf::Event event, sf::RenderWindow& window)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	if (pos.y == (m_boardsize.x + 1) * P_SIZE && pos.x < P_SIZE * 8) // means toolbar button was pressed
	{
		erase_mode = false;
		Toolbar_t icon = m_toolbar.get_icon_name(pos);
		switch (icon)
		{
		case DIGGER:
			m_new_icon._shape = DIGGER;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case MONSTER:
			m_new_icon._shape = MONSTER;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case DIAMOND:
			m_new_icon._shape = DIAMOND;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case WALL:
			m_new_icon._shape = WALL;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case STONE:
			m_new_icon._shape = STONE;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case SAVE:
			setToolbarRect(m_shape_rect, pos, sf::Color(0, 150, 255, 200));
			save_grid();
			m_read = true;
			break;
		case ERASE:
			setToolbarRect(m_shape_rect, pos, sf::Color(0, 150, 255, 200));
			erase_mode = true;
			break;
		case CLEAR:
			m_read = false;
			clear_grid();
			window.close();
			break;
		}
	}
	else if (pos.y != (m_boardsize.y + 1) * P_SIZE && pos.y != 0) // means a cell in the grid was pressed 
	{
		int x = ((int)pos.y / P_SIZE) - 1;
		int y = (int)pos.x / P_SIZE;
		if (erase_mode)
			m_grid[x][y] = nullptr;
		else if (m_grid[x][y] == nullptr)
		{
			switch (m_new_icon._shape)
			{
			case DIGGER:
				if (m_digger_placed)
					m_grid[(int)m_digger_pos.x][(int)m_digger_pos.y] = nullptr;
				m_grid[x][y] = std::make_unique < Digger >(m_new_icon._color);
				m_digger_pos = sf::Vector2f((float)x, (float)y);
				m_digger_placed = true;
				break;
			case MONSTER:
				m_grid[x][y] = std::make_unique < Monster >(m_new_icon._color);
				break;
			case DIAMOND:
				m_grid[x][y] = std::make_unique < Diamond >(m_new_icon._color);
				break;
			case WALL:
				m_grid[x][y] = std::make_unique < Wall >(m_new_icon._color);
				break;
			case STONE:
				m_grid[x][y] = std::make_unique < Stone >(m_new_icon._color);
				break;
			}
		}
	}
}

// sets the rectangle around the toolbar icons 
void Board::setToolbarRect(sf::RectangleShape& rect, sf::Vector2f pos, sf::Color color)
{
	rect.setSize(sf::Vector2f((float)P_SIZE, (float)P_SIZE));
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(2);
	rect.setPosition(pos);
	rect.setOutlineColor(color);
}

// draws the icons that the user picked
void Board::draw_icons(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_boardsize.x; i++)
		for (size_t j = 0; j < m_boardsize.y; j++)
			if (m_grid[i][j] != nullptr)
				m_grid[i][j]->draw(window, sf::Vector2f(((float)j) * P_SIZE, ((float)(i + 1)) * P_SIZE)
					, m_toolbar.get_icon_sprite(m_grid[i][j]->getShape()));
}

// in case the mouse moved
void Board::mouse_moved(sf::Event event, sf::RenderWindow& window)
{
	int x = event.mouseMove.x;
	int y = event.mouseMove.y;

	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	x = ((int)pos.y / P_SIZE) - 1;
	y = (int)pos.x / P_SIZE;

	if (pos.y != 0 && pos.y != (m_boardsize.x + 1) * P_SIZE)
	{
		m_moving_rect.setFillColor(sf::Color(0, 255, 0, 90));
		m_moving_rect.setPosition(pos);
		switch (m_new_icon._shape)
		{
		case DIGGER:
			m_moving_icon = m_toolbar.get_icon_sprite(DIGGER);
			break;
		case MONSTER:
			m_moving_icon = m_toolbar.get_icon_sprite(MONSTER);
			break;
		case DIAMOND:
			m_moving_icon = m_toolbar.get_icon_sprite(DIAMOND);
			break;
		case WALL:
			m_moving_icon = m_toolbar.get_icon_sprite(WALL);
			break;
		case STONE:
			m_moving_icon = m_toolbar.get_icon_sprite(STONE);
			break;
		}
		m_moving_icon.setPosition(pos);
		m_moving_icon.setColor(sf::Color(255, 255, 255, 90));
	}
}

// checks if the cursor is in the window
bool Board::in_window(sf::Event event)
{
	int x = event.mouseMove.x;
	int y = event.mouseMove.y;
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));

	if (x > P_SIZE* m_boardsize.x ||
		y > P_SIZE* (m_boardsize.y + 1) ||
		x < 0 || y < 0)
		return false;

	return true;
}

// saves the board to a .txt file
void Board::save_grid()
{
	std::ofstream output;
	output.open("board.txt");
	if (!output.is_open())
	{
		std::cerr << "could not open board.txt";
		exit(EXIT_FAILURE);
	}

	output << m_boardsize.x << "\n" << m_boardsize.y << "\n";
	for (size_t i = 0; i < m_boardsize.x; i++)
	{
		for (size_t j = 0; j < m_boardsize.y; j++)
		{
			if (m_grid[i][j] == nullptr)
				output << " ";
		}
		output << "\n";
	}
}

// deletes all the objects from the board
void Board::clear_grid()
{
	for (size_t i = 0; i < m_boardsize.x; i++)
		for (size_t j = 0; j < m_boardsize.y; j++)
			m_grid[i][j] = nullptr;
}

// opens the file to read
bool Board::open_file(fstream& input)
{
	input.open("board.txt");
	if (!input.is_open())
		return false;
	return true;
}

// read data for the board - from the user or the .txt file
void Board::read_data()
{
	std::fstream input;

	if (open_file(input) && m_read)
	{
		char c;
		input >> m_boardsize.x >> m_boardsize.y;
		input.get();
		set_board();

		for (size_t i = 0; i < m_boardsize.x; i++)
			for (size_t j = 0; j < m_boardsize.y + 1; j++)
			{
				c = input.get();
			}
	}
	else
		read_from_usr();
}

// read data from the user
void Board::read_from_usr()
{
	std::cout << "please enter number of rows: ";
	std::cin >> m_boardsize.x;

	std::cout << "please enter number of columns: ";
	std::cin >> m_boardsize.y;

	std::cout << "please enter number of stones allowed to eat: ";
	std::cin >> m_stone;

	if (m_boardsize.y < 8)
	{
		std::cerr << "too few columns, please enter more columns\n";
		read_from_usr();
	}
	set_board();
}

void Board::set_board()
{
	m_grid.resize((int)m_boardsize.x);
	for (size_t i = 0; i < m_boardsize.x; i++)
		m_grid[i].resize((int)m_boardsize.y);
}
