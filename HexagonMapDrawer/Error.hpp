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
#include "DrawError.hpp"

using namespace std;
using namespace sf;

int Error(string text, RenderWindow &window)
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			Vector2i position = Mouse::getPosition();
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				if (IsOnSquare(525, 500, 100, 50, position.x, position.y))
				{
					ofstream out;
					out.open("map.txt");
					out << 2 << ' ' << 2 << ' ' << 0 << ' ' << 1 << '\n' << 2 << ' ' << 3;
					window.close();
					exit(0);
				}
			}
		}
		window.clear();
		DrawError(text, window);
		window.display();
	}
	return 0;
}
