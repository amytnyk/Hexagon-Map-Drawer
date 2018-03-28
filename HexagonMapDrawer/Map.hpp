#pragma once
#include <vector>

using namespace std;
template <typename Key, typename Data>
class Map
{
public:
	Map()
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
		this->data.push_back(water_texture);
		this->data.push_back(plain_texture);
		this->data.push_back(road_texture);
		this->data.push_back(forest_texture);
		this->data.push_back(swamp_texture);
		this->data.push_back(mountain_texture);
		this->data.push_back(city_texture);
		this->keys.push_back("water");
		this->keys.push_back("plain");
		this->keys.push_back("road");
		this->keys.push_back("forest");
		this->keys.push_back("swamp");
		this->keys.push_back("mountain");
		this->keys.push_back("city");
	}
	const Data operator[] (string key)
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			if (keys[i] == key)
			{
				return data[i];
			}
		}
	}
	int size()
	{
		return data.size();
	}
	void push_back(Key key, Data data)
	{
		keys.push_back(key);
		this->data.push_back(data);
	}
private:
	vector<Key> keys;
	vector<Data> &data;
};