/*#include <SFML/Graphics.hpp>

class Grid
{
public:
	//Grid(int r, int c, sf::RenderWindow* window);
	Grid() = default;
	 x = sf::RenderWindow (sf::VideoMode(800, 800), "window");

	Grid(int r, int c, sf::RenderWindow* window) : row(r), col(c), gridWindow(window) //add intitilize to window in fridWindow
	{
		int w = gridWindow->getSize().x * 1.0 / row;
		int h = gridWindow->getSize().y * 1.0 / col;

		Rects = new sf::RectangleShape[r];
		for (int i = 0; i < row; i++)
			Rects = new sf::RectangleShape[col]; //CHECK

		int baseX = 100;
		int baseY = 100;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < row; j++)
			{
				Rects[j] = sf::RectangleShape();
				Rects[j].setPosition(baseX, baseY);
				Rects[j].setFillColor(sf::Color::Yellow);
				Rects[j].setOutlineColor(sf::Color::White);
				Rects[j].setOutlineThickness(10);
				baseX += w;
			}
		baseX = 10;
		baseY += h;

	}
private:
	sf::RectangleShape* Rects;
	sf::RenderWindow* gridWindow;

	int row;
	int col;
		
}; */