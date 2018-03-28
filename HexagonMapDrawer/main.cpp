#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Monster.hpp"
#include "Terrain.hpp"
#include "AddMonster.hpp"
#include "GetPath.hpp"
#include "Menu.hpp"
#include "Error.hpp"
#include "GenerateMap.hpp"
#include <map>
#include "Map.hpp"
#include "GetMapFromFile.hpp"
#include "GetTerrain.hpp"
#include "Save.hpp"
#include "DrawMap.hpp"

using namespace std;
using namespace sf;

#define PI 3.14159265

int main()
{
	Texture mountain_texture;
	Texture plain_texture;
	Texture swamp_texture;
	Texture water_texture;
	Texture road_texture;
	Texture forest_texture;
	Texture city_texture;
	mountain_texture.loadFromFile("mountain.png");
	plain_texture.loadFromFile("grass.png");
	swamp_texture.loadFromFile("boloto.png");
	water_texture.loadFromFile("water.png");
	road_texture.loadFromFile("road.jpg");
	forest_texture.loadFromFile("forest.png");
	city_texture.loadFromFile("forest.png");
	vector<Texture> textures;
	textures.push_back(water_texture);
	textures.push_back(plain_texture);
	textures.push_back(road_texture);
	textures.push_back(forest_texture);
	textures.push_back(swamp_texture);
	textures.push_back(mountain_texture);
	textures.push_back(city_texture);
	vector<string> keys;
	keys.push_back("water");
	keys.push_back("plain");
	keys.push_back("road");
	keys.push_back("forest");
	keys.push_back("swamp");
	keys.push_back("mountain");
	keys.push_back("city");
	vector<Monster> monsters;
	vector<vector<Terrain> > tmap;
	RenderWindow window(VideoMode(500, 500), "Your map is here!", Style::Fullscreen);
	bool current = Menu(window);
	if (!current)
	{
		GenerateMap(window);
	}
	string path = GetPath(window);
	if (ifstream(path))
	{
		tmap = GetMapFromFile(path, monsters);
	}
	else
	{
		Error("File " + path + " does not exits!", window);
	}
	tmap = GetMapFromFile(path, monsters);
	int last_x = -1, last_y = -1;
	int last = 0;
	string text;
	int index = -1;
	int index3 = 0;
	float size = 20;
	bool auto_place = false;
	bool monster = false;
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
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			if (auto_place && index == -1)
			{
				auto_place = false;
			}
			if (auto_place)
			{
				for (size_t i = 0; i < tmap.size(); i++)
				{
					for (size_t j = 0; j < tmap[i].size(); j++)
					{
						double k = (j % 2 == 0) ? size * cos(30 * PI / 180) : 0;
						double x = 50 + j * size + j * size * sin(30 * PI / 180);
						double y = 50 + i * size * cos(30 * PI / 180) * 2 + k;
						if (IsOnSquare(x, y, size, size * cos(30 * PI / 180) * 2, position.x, position.y))
						{
							if (index != -1)
							{
								tmap[i][j] = GetTerrain(index);
								break;
							}
							if (last == 0)
							{
								int index2 = GetTerrain(tmap[i][j]);
								index2++;
								if (index2 == textures.size())
								{
									index2 = 0;
								}
								tmap[i][j] = GetTerrain(index2);
								last_x = i;
								last_y = j;
								last = 10;
							}
						}
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::A)) // Auto place
			{
				if (index != -1)
				{
					auto_place = (auto_place) ? false : true;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::M))
			{
				monster = true;
			}
			if (Keyboard::isKeyPressed(Keyboard::C))
				index = index3;
			if (Keyboard::isKeyPressed(Keyboard::V))
				index = -1;
			if (Keyboard::isKeyPressed(Keyboard::S))
				Save(tmap, path, monsters);
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				for (size_t i = 0; i < tmap.size(); i++)
				{
					for (size_t j = 0; j < tmap[i].size(); j++)
					{
						//50 + j * 50 + j * 50 * sin(30 * PI / 180)
						//50 + j * 50 + j * 50 * cos(30 * PI / 180) * 2
						double k = (j % 2 == 0) ? size * cos(30 * PI / 180) : 0;
						double x = 50 + j * size + j * size * sin(30 * PI / 180);
						double y = 50 + i * size * cos(30 * PI / 180) * 2 + k;
						if (IsOnSquare(x, y, size, size * cos(30 * PI / 180) * 2, position.x, position.y))
						{
							if (monster == true)
							{
								int monster_x = j;
								int monster_y = i;
								AddMonster(monster_x, monster_y, monsters, window);
								monster = false;
							}
							if (index != -1)
							{
								tmap[i][j] = GetTerrain(index);
								break;
							}
							if (last == 0)
							{
								int index2 = GetTerrain(tmap[i][j]);
								index2++;
								if (index2 == textures.size())
								{
									index2 = 0;
								}
								index3 = index2;
								tmap[i][j] = GetTerrain(index2);
								last_x = i;
								last_y = j;
								last = 10;
							}
						}
					}
				}
			}
		}
		if (last > 0)
			last--;
		window.clear();
		DrawMap(textures, keys ,tmap, window, monsters, size);
		window.display();
	}

	return 0;
}