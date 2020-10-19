#pragma once
#include "Toolbar.h"

class Stone : public Icon
{
public:
	// stone c-tor
	Stone(Toolbar_t color) { m_color = color; m_shape = STONE; };

	// draw stone icon
	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite)
	{
		sprite.setPosition(pos);
		window.draw(sprite);
	};
};