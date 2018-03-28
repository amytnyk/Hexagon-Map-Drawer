#pragma once
#include <string>
#include "Coord.hpp"

using namespace std;

class Monster
{
public:
	Monster()
	{

	}
	Monster(int X, int Y, std::string name)
	{
		string copy = name;
		this->name = name.erase(name.find(" "), name.size() - name.find(" "));
		this->power = stoi(copy.erase(0, copy.find(" ")));
		this->X = X;
		this->Y = Y;
	}
	std::vector<Coord> coords;
	int X;
	int Y;
	int power;
	std::string name;
};