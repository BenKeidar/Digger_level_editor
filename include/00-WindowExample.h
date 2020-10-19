/*#pragma once

#include <SFML/Graphics.hpp>

class WindowExample
{
public:
    WindowExample();

private:
    sf::RenderWindow m_window;
}; 

#pragma once

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 8

class WindowExample
{
public:
	WindowExample(float width, float height);

	//void draw(sf::RenderWindow& window);
	//void draw2(sf::RenderWindow& window) const;
	//void MoveUp();
	//void MoveDown();

	
private:
	// sf::RenderWindow m_window;
	//sf::CircleShape create() const;
	//sf::Vector2f m_position;
	int selectedItemIndex;
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS];
};
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 8

class Window
{
public:
	Window();

	void win();
	//void handleClick(const sf::Vector2f& clickLocation);
	void draw(sf::RenderWindow& window);

private:

	void handleClick(const sf::Event::MouseButtonEvent& event);
	sf::Color computeNextColor(const sf::Color& color);

	//sf::Vector2f m_position[8][8];
	sf::RenderWindow m_window;

	//std::vector<std::vector<sf::RectangleShape>> rec;
	sf::RectangleShape m_shape ;

	//sf::RectangleShape rec;


	//rec[0][0] = (sf::RectangleShape({ 100, 100 }));
	//rec[0][0].setOutlineThickness(5);



	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS];
};