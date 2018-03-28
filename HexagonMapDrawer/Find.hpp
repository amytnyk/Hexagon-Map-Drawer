#pragma once
#include <vector>

template <typename T>
int Find(vector<T> elements, T element)
{
	for (size_t i = 0; i < elements.size(); i++)
	{
		if (elements[i] == element)
		{
			return i;
		}
	}
}