#pragma once
#include "Terrain.hpp"

Terrain GetTerrain(int i)
{
	if (i == 0)
	{
		return Terrain::Forest;
	}
	if (i == 1)
	{
		return Terrain::Plain;
	}
	if (i == 2)
	{
		return Terrain::Mountain;
	}
	if (i == 3)
	{
		return Terrain::Water;
	}
	if (i == 4)
	{
		return Terrain::Road;
	}
	if (i == 5)
	{
		return Terrain::Swamp;
	}
	if (i == 6)
	{
		return Terrain::City;
	}
}

int GetTerrain(Terrain t)
{
	if (t == Terrain::Forest)
	{
		return 0;
	}
	if (t == Terrain::Plain)
	{
		return 1;
	}
	if (t == Terrain::Mountain)
	{
		return 2;
	}
	if (t == Terrain::Water)
	{
		return 3;
	}
	if (t == Terrain::Road)
	{
		return 4;
	}
	if (t == Terrain::Swamp)
	{
		return 5;
	}
	if (t == Terrain::City)
	{
		return 6;
	}
}