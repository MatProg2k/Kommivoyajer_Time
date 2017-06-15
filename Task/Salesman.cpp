#include "stdafx.h"
#include "Salesman.h"
#include "GenerationPlacements.h"

Salesman::Salesman(int sizeCity, std::vector<std::vector<int>> distance)
{
	this->sizeCity = sizeCity;
	this->distance = distance;

	Placements placements(sizeCity);
	placements.Generetion();

	for (int i = 0; i < placements.GetSizePlacements(); i++)
	{
		if (placements.GetPlacements()[i][NULL] == NULL)
		{
			this->placements.push_back(placements.GetPlacements()[i]);
		}
	}

	for (int i = 0; i < this->placements.size(); i++)
	{
		this->placements[i].push_back(NULL);
	}
}

void Salesman::Generation()
{
	int tempDistance = 0;
	bool flag = true;

	for (int i = 0; i < placements.size(); i++)
	{
		for (int j = 0; j < placements[i].size() - 1; j++)
		{
			if (this->distance[this->placements[i][j]][this->placements[i][j + 1]] == INF)
			{
				flag = false;
				break;
			}

			tempDistance += this->distance[this->placements[i][j]][this->placements[i][j + 1]];
		}

		if ((this->minDistance > tempDistance) && (flag == true))
		{
			this->minDistance = tempDistance;
			this->way = this->placements[i];
		}

		tempDistance = 0;
		flag = true;
	}
}

void Salesman::ShowResult()
{
	std::cout << "Путь";
	for (auto i : this->way)
	{
		std::cout << "->" << i + 1;
	}
	std::cout << std::endl << "Расстояние пути: " << this->minDistance << std::endl;
}