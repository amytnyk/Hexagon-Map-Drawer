#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Monster.hpp"
#include "DrawText.hpp"

using namespace std;
using namespace sf;

string GetPath(RenderWindow &window)
{
	string path = "map.txt";
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
				if (path.size() != 0)
					path.resize(path.size() - 1);
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				return path;
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128 && event.text.unicode != 8)
					path += static_cast<char>(event.text.unicode);
			}
		}
		window.clear();
		DrawText(100, 100, 40, path, Color::Red, false, window);
		window.display();
	}
	return path;
}