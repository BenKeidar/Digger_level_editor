#include "00-WindowExample.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

Window::Window() 
{
}

void Window::win()
{

	sf::RenderWindow window(sf::VideoMode(800, 900),"Menu");
	

	
	auto font = sf::Font();
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	text[0].setFont(font);
	text[0].setColor(sf::Color::Red);
	text[0].setString("Button1");
	text[0].setCharacterSize(20);
	text[0].setOutlineThickness(5);
	text[0].setOutlineColor(sf::Color::Black);
	text[0].setPosition(sf::Vector2f(50, 500));
	
	text[1].setFont(font);
	text[1].setColor(sf::Color::Green);
	text[1].setString("Button 2");
	text[1].setCharacterSize(20);
	text[1].setPosition(sf::Vector2f(150, 500));

	text[2].setFont(font);
	text[2].setColor(sf::Color::Yellow);
	text[2].setString("Button 3");
	text[2].setCharacterSize(20);
	text[2].setPosition(sf::Vector2f(250, 500));
	
	text[3].setFont(font);
	text[3].setColor(sf::Color::Blue);
	text[3].setString("Button 4");
	text[3].setCharacterSize(20);
	text[3].setPosition(sf::Vector2f(350, 500));

	text[4].setFont(font);
	text[4].setColor(sf::Color::Magenta);
	text[4].setString("Button 5");
	text[4].setCharacterSize(20);
	text[4].setPosition(sf::Vector2f(450, 500));
	
	int i, j;
	/*for (i = 0; x[i][j] != 30; i++)
	{
		for (j = 0; j != NULL; j++)
		{
			x[i][j] = sf::RectangleShape({ 100, 100 });
			x[i][j].setOutlineColor(sf::Color::Black);
			x[i][j].setOutlineThickness(5);
		}
	} */
	i = 0;
	j = 0;
	std::vector<std::vector<sf::RectangleShape >> rec;

	/*for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			auto rectangle = sf::RectangleShape({ 100,100 });
			rectangle.setOutlineThickness(5);
			rectangle.setOutlineColor(sf::Color::Black);
			rec[i][j] = rectangle;
		}

	} */

	//rec.push_back = a;
	/*rec[0][0] = a;
	rec[0][0] = a;
	rec[0][0] = a;
	rec[0][0] = a;
	rec[0][0] = a;
	rec[0][0] = a; */


	auto digger = sf::Texture();
	digger.loadFromFile("digger.png");

	auto wall = sf::Texture();
	wall.loadFromFile("wall.png");

	auto demon = sf::Texture();
	demon.loadFromFile("demon.png");

	auto diamond = sf::Texture();
	diamond.loadFromFile("diamond.png");

	auto save = sf::Texture();
	save.loadFromFile("save.png");

	auto del = sf::Texture();
	del.loadFromFile("delete.png");

	auto clear = sf::Texture();
	clear.loadFromFile("clear.png");

	auto stone = sf::Texture();
	stone.loadFromFile("stone.png");
	
	/*if (!digger.loadFromFile("digger.png"))
		std::cout << "load failed" << std::endl;
		*/
	//std::vector<sf::Sprite> m_sprites;

	auto sprite = sf::Sprite(digger);
	sprite.setPosition(sf::Vector2f(0, 820));

	auto sprite2 = sf::Sprite(wall);
	sprite2.setPosition(sf::Vector2f(120, 830));

	auto sprite3 = sf::Sprite(demon);
	sprite3.setPosition(sf::Vector2f(200, 810));

	auto sprite4 = sf::Sprite(diamond);
	sprite4.setPosition(sf::Vector2f(300, 800));

	auto sprite5 = sf::Sprite(stone);
	sprite5.setPosition(sf::Vector2f(420, 820));

	auto sprite6 = sf::Sprite(del);
	sprite6.setPosition(sf::Vector2f(520, 810));

	auto sprite7 = sf::Sprite(clear);
	sprite7.setPosition(sf::Vector2f(620, 810));

	auto sprite8 = sf::Sprite(save);
	sprite8.setPosition(sf::Vector2f(720, 810));


	while (window.isOpen())
	{

		window.clear(sf::Color::White);
		/* 
		for (i = 0; i < 6; i++)
		{
			for (j = 0; j < 6; j++)
			{
				auto rectangle = sf::RectangleShape({ 100,100 });
				rectangle.setOutlineThickness(5);
				rectangle.setOutlineColor(sf::Color::Black);
				rec[i].push_back(rectangle);
			
			}
           
		} 

		for (int i = 0; i < 6 ; i++)
		{
				window.draw(rec[i][0]);
		}
*/
		for (int i = 0; i < 800; i += 100)
		{
			for (int j = 0; j < 800; j+= 100)
			{
				auto a = sf::RectangleShape({ 100, 100 });
				a.setOutlineColor(sf::Color::Black);
				a.setOutlineThickness(5);
				a.setPosition(sf::Vector2f(i, j));
				window.draw(a);
			}
		} 

		window.draw(sprite);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);


	//	for (int i = 0; i < 800; i + 100)
		{
				//for (int j = 0; j < 800; j + 100)
				{
			//		window.draw(rec[i][j]);
					//rectangle.setPosition(sf::Vector2f(i / 2, j / 2));
				}

		}  
		//window.draw(rectangle);

		//window.draw(rectangle);
		//window.display();

		//window.draw(grid, (rows + 1 + cols + 1), sf::Lines);

		//rectangle.setPosition(sf::Vector2f(800 / 2, 800 / 2));

		//rectangle.setPosition(sf::Vector2f(800 / 2, 800 / 2));



		/*for (int i = 0; i < 800; i + 100)
		{
			for (int j = 0; j < 800; j + 100)
			{
				window.draw(rectangle);
				rectangle.setPosition(sf::Vector2f(i / 2, j / 2));
			}

		}  */
		//sf::Vector2u shapeSize = shapeSize.x()
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				handleClick(event.mouseButton);
				break;
			}
		}
	}
}


void Window::handleClick(const sf::Event::MouseButtonEvent& event)
{
	if (m_shape.getGlobalBounds().contains(
		m_window.mapPixelToCoords({ event.x, event.y })))
	{
		m_shape.setFillColor(computeNextColor(m_shape.getFillColor()));
	}
}

sf::Color Window::computeNextColor(const sf::Color& color)
{
	if (color == sf::Color::Red)
	{
		return sf::Color::Yellow;
	}

	if (color == sf::Color::Yellow)
	{
		return sf::Color::Green;
	}

	// color == sf::Color::Green
	return sf::Color::Red;

}
