#pragma once
#include "Toolbar.h"

class Wall : public Icon
{
public:
	// wall c-tor
	Wall(Toolbar_t color) { m_color = color; m_shape = WALL; }

	// draws the wall icon
	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite)
	{
		sprite.setPosition(pos);
		window.draw(sprite);
	};
};