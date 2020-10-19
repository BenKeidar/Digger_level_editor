#pragma once
#include "Toolbar.h"

class Diamond : public Icon
{
public:
	// diamond c-tor
	Diamond(Toolbar_t color) { m_color = color; m_shape = DIAMOND; };

	// draw diamond icon
	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite)
	{
		sprite.setPosition(pos);
		window.draw(sprite);
	};


private:

};