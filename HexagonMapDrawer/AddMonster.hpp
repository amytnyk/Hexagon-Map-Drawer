#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "DrawText.hpp"
#include "Monster.hpp"

using namespace std;
using namespace sf;

void AddMonster(int X, int Y, vector<Monster> &monsters, RenderWindow &window)
{
	string monster = "";
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
				if (monster.size() != 0)
					monster.resize(monster.size() - 1);
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				if (monster != "")
				{
					monsters.push_back(Monster(X, Y, monster));
					return;
				}
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128 && event.text.unicode != 8)
					monster += static_cast<char>(event.text.unicode);
			}
		}
		window.clear();
		DrawText(100, 100, 40, monster, Color::Red, false, window);
		window.display();
	}
}