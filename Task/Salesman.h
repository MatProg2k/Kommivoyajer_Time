#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#define INF -1

class Salesman
{
private:
	int sizeCity;
	std::vector<std::vector<int>> distance;

	int minDistance = INT32_MAX;
	std::vector<int> way;

	std::vector<std::vector<int>> placements;

public:
	Salesman(int sizeCity, std::vector<std::vector<int>> distance);
	void Generation();
	void ShowResult();
};