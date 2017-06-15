#pragma once // перестановок
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

class Placements
{
private:
	const bool LEFT = true;
	const bool RIGHT = false;

	int sizeSet;
	int sizePlacements;

	std::vector<bool> direction;
	std::vector<int> set;
	std::vector<std::vector<int>> placements;

public:
	Placements(int sizeSet);

	int GetSizePlacements();
	std::vector<std::vector<int>> GetPlacements();

	void Generetion();
	void ShowPlacementsAlph();

private:
	__int64 Factorial(int);
};