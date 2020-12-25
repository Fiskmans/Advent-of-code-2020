#include "stdafx.h"
#include "Day13.h"

Day13::Day13(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	file >> now;
	std::string num;
	while (file >> num)
	{
		int number = -1;
		if (num != "x")
		{
			std::stringstream(num) >> number;
		}
		departures.push_back(number);
	}

}

void Day13::RunPuzzle1()
{
	int nextBus = std::numeric_limits<int>::max();
	int busId;
	for (auto& id : departures)
	{
		if (id == -1)
		{
			continue;
		}
		int departs = now / id;
		int next = (departs + 1) * id;
		if (next < nextBus)
		{
			nextBus = next;
			busId = id;
		}
	}

	std::cout << "Value: " << (nextBus - now) * busId << std::endl;
}

void Day13::RunPuzzle2()
{
	size_t lcd = 1;
	size_t at = departures[0];
	for (size_t i = 0; i < departures.size(); i++)
	{
		if (departures[i] == -1)
		{
			continue;
		}
		while ((at + i) % departures[i] != 0)
		{
			at += lcd;
		}
		lcd *= departures[i];
	}

	std::cout << "Timepoint: " << at << std::endl;
}
