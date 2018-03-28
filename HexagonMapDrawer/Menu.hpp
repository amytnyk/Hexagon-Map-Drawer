#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Monster.hpp"
#include "DrawText.hpp"
#include "IsOnSquare.hpp"

using namespace std;
using namespace sf;

bool Menu(RenderWindow &window)
{
	RectangleShape rectangle;
	rectangle.setPosition(800, 500);
	rectangle.setSize(Vector2f(350, 75));
	rectangle.setFillColor(Color::Green);
	RectangleShape rect;
	rect.setPosition(200, 500);
	rect.setSize(Vector2f(350, 75));
	rect.setFillColor(Color::Green);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			Vector2i position = Mouse::getPosition();
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{

				if (IsOnSquare(800, 500, 350, 75, position.x, position.y))
				{
					return false;
				}
				if (IsOnSquare(200, 500, 350, 75, position.x, position.y))
				{
					return true;
				}
			}
		}
		window.clear();
		window.draw(rectangle);
		window.draw(rect);
		DrawText(200, 500, 50, "Load map", Color::Blue, false, window);
		DrawText(800, 500, 50, "Generate Map", Color::Blue, false, window);
		window.display();
	}
}