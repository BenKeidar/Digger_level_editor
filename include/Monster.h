#pragma once
#include "Toolbar.h"

class Monster : public Icon
{
public:
	// Demon c-tor 
	Monster(Toolbar_t color) { m_color = color; m_shape = MONSTER; }

	// draw monster icon
	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite)
	{
		sprite.setPosition(pos);
		window.draw(sprite);
	};
};