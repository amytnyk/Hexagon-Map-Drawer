#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Monster.hpp"
#include "Terrain.hpp"
#include "Map.hpp"
#include "DrawText.hpp"
#include "Find.hpp"

using namespace std;
using namespace sf;

#define PI 3.14159265

void DrawMap(const vector<Texture> &textures, vector<string> keys, const vector<vector<Terrain> > &tmap, RenderWindow &window, const vector<Monster> monsters, float size)
{
	for (size_t i = 0; i < tmap.size(); i++)
	{
		for (size_t j = 0; j < tmap[i].size(); j++)
		{
			ConvexShape convex;
			convex.setPointCount(6);
			convex.setPoint(0, sf::Vector2f(0, 0));
			convex.setPoint(1, sf::Vector2f(size, 0));
			convex.setPoint(2, sf::Vector2f(size + size * sin(30 * PI / 180), size * cos(30 * PI / 180)));
			convex.setPoint(3, sf::Vector2f(size, 2 * size * cos(30 * PI / 180)));
			convex.setPoint(4, sf::Vector2f(0, 2 * size * cos(30 * PI / 180)));
			convex.setPoint(5, sf::Vector2f(-size * sin(30 * PI / 180), size * cos(30 * PI / 180)));
			int X = 50 + j * size + size * sin(30 * PI / 180) * j;
			int Y = 50 + i * size * cos(30 * PI / 180) * 2;
			if (j % 2 == 0)
			{
				convex.setPosition(X, Y + size * cos(30 * PI / 180));
				//convex.setPosition(50 + j * size + size * sin(30 * PI / 180) * j , 50 + i * size * cos(30 * PI / 180) * 2);// + size * cos(30 * PI / 180));
			}
			else
			{
				convex.setPosition(X, Y);
				//convex.setPosition(50 + j * size + size * sin(30 * PI / 180) * j, 50 + i * size * cos(30 * PI / 180) * 2);
			}
			//convex.setFillColor(Color::Green);
			if (tmap[i][j] == Terrain::City)
			{
				convex.setTexture(&textures[Find<string>(keys, "city")]);
			}
			if (tmap[i][j] == Terrain::Forest)
			{
				convex.setTexture(&textures[Find<string>(keys, "forest")]);
			}
			if (tmap[i][j] == Terrain::Plain)
			{
				convex.setTexture(&textures[Find<string>(keys, "plain")]);
			}
			if (tmap[i][j] == Terrain::Road)
			{
				convex.setTexture(&textures[Find<string>(keys, "road")]);
			}
			if (tmap[i][j] == Terrain::Mountain)
			{
				convex.setTexture(&textures[Find<string>(keys, "mountain")]);
			}
			if (tmap[i][j] == Terrain::Swamp)
			{
				convex.setTexture(&textures[Find<string>(keys, "swamp")]);
			}
			if (tmap[i][j] == Terrain::Water)
			{
				convex.setTexture(&textures[Find<string>(keys, "water")]);
			}
			window.draw(convex);
			for (Monster monster : monsters)
			{
				if (monster.X == j && monster.Y == i)
				{
					DrawText(X + 10, Y + 50, 30, monster.name, Color::Red, true, window);
				}
			}
		}
	}
}