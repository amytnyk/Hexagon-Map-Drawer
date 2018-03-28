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

void GenerateMap(RenderWindow &window)
{
	string name = "";
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			Vector2i position = Mouse::getPosition();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::BackSpace))
				if (name.size() != 0)
					name.resize(name.size() - 1);
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				if (name != "")
				{
					ofstream out(name);
					out << 16 << " " << 26 << endl;
					for (size_t i = 0; i < 16; i++)
					{
						for (size_t j = 0; j < 26; j++)
						{
							out << 0 << " ";
						}
						out << endl;
					}
					return;
				}
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128 && event.text.unicode != 8)
					name += static_cast<char>(event.text.unicode);
			}
		}
		window.clear();
		DrawText(100, 100, 40, name, Color::Red, false, window);
		window.display();
	}
}