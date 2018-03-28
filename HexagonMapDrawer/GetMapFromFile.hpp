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

vector<vector<Terrain> > GetMapFromFile(string path, vector<Monster> &monsters)
{
	vector<vector<Terrain> > tmap;
	ifstream in;
	in.open(path);
	int h, w;
	in >> h >> w;
	int i = 0;
	tmap.resize(h);
	for (size_t i = 0; i < h; i++)
	{
		tmap[i].resize(w);
		for (size_t j = 0; j < w; j++)
		{
			int k;
			in >> k;
			tmap[i][j] = GetTerrain(k);
		}
	}
	int n = 0;
	in >> n;
	monsters.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		in >> monsters[i].X >> monsters[i].Y >> monsters[i].name >> monsters[i].power;
	}
	in.close();
	return tmap;
}