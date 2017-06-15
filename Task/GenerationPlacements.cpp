#include "stdafx.h"
#include "GenerationPlacements.h"

Placements::Placements(int sizeSet)
{
	this->sizeSet = sizeSet;
	this->sizePlacements = this->Factorial(this->sizeSet);
	for (int i = 0; i < this->sizeSet; i++)
	{
		this->set.push_back(i);
	}

	for (int i = 0; i < this->sizeSet; i++)
	{
		this->direction.push_back(this->LEFT);
	}
}

int Placements::GetSizePlacements()
{
	return this->sizePlacements;
}

std::vector<std::vector<int>> Placements::GetPlacements()
{
	return this->placements;
}

void Placements::Generetion()
{
	std::vector<int> temp;
	for (int i = 0; i < this->sizeSet; i++)
	{
		temp.push_back(i);
	}
	this->placements.push_back(temp);
	
	bool flag = false;
	do
	{
		// поиск максимального мобильного элемента
		std::pair<int, bool> pair(INT_MIN, false);
		int tempI = 0;
		flag = false;
		for (int i = 0; i < this->sizeSet; i++)
		{
			if ((this->direction[i] == this->LEFT) && (i != 0)
						 && (temp[i] > temp[i - 1]))
			{
				if (pair.first < temp[i])
				{
					pair.first = temp[i];
					pair.second = this->direction[i];
					tempI = i;
					flag = true;
				}
			}
			else if ((this->direction[i] == this->RIGHT) && (i != this->sizeSet - 1)
															&& (temp[i] > temp[i + 1]))
			{
				if (pair.first < temp[i])
				{
					pair.first = temp[i];
					pair.second = this->direction[i];
					tempI = i;
					flag = true;
				}
			}
		} 

		// перемещение мобильного элемента и смена направлений
		if (flag == true)
		{
			if (this->direction[tempI] == this->LEFT)
			{
				std::swap(direction[tempI], direction[tempI - 1]);
				std::swap(temp[tempI], temp[tempI - 1]);
				tempI--;
			}
			else if (this->direction[tempI] == this->RIGHT)
			{
				std::swap(direction[tempI], direction[tempI + 1]);
				std::swap(temp[tempI], temp[tempI + 1]);
				tempI++;
			}
			this->placements.push_back(temp);

			for (int i = 0; i < this->sizeSet; i++)
			{
				if (temp[tempI] < temp[i])
				{
					if (this->direction[i] == true)
					{
						this->direction[i] = false;
					}
					else
					{
						this->direction[i] = true;
					}
				}
			}
		}
	} while (flag == true);
}


void Placements::ShowPlacementsAlph()
{
	std::ofstream file("laba3.txt", std::ios::app);

	file << "Перестановки:" << std::endl;
	for (int i = 0; i < this->sizePlacements; i++)
	{
		file << "{ ";
		for (int j = 0; j < this->placements[i].size(); j++)
		{
			file << char(97 + this->placements[i][j]) << " ";
		}
		file << "}" << std::endl;
	}

	file.close();
}

__int64 Placements::Factorial(int number)
{
	if ((number == 1) | (number == 0))
	{
		return 1;
	}
	return Factorial(number - 1) * number;
}