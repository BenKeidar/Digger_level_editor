#pragma once

#include "Toolbar.h"
#include "Icon.h"

#include <iostream>

class Digger : public Icon
{
public:
	// digger c-tor
	Digger(Toolbar_t color) { m_color = color; m_shape = DIGGER; }

	// draw digger icon
	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite)
	{
		sprite.setPosition(pos);
		window.draw(sprite);
	}
};