#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Monster.hpp"
#include "Terrain.hpp"
#include "GetTerrain.hpp"

using namespace std;
using namespace sf;

void Save(vector<vector<Terrain> > tmap, string path, vector<Monster> monsters)
{
	ofstream out;
	out.open(path);
	out << tmap.size() << ' ' << tmap[0].size() << ' ';
	for (size_t i = 0; i < tmap.size(); i++)
	{
		for (size_t j = 0; j < tmap[i].size(); j++)
		{
			out << GetTerrain(tmap[i][j]) << ' ';
		}
		out << endl;
	}
	out << monsters.size() << " ";
	for (size_t i = 0; i < monsters.size(); i++)
	{
		out << monsters[i].X << " " << monsters[i].Y << " " << monsters[i].name << " " << monsters[i].power << endl;
	}
	out.close();
}
