#include "stdafx.h"
#include "Day15.h"

Day15::Day15(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;
	size_t num;
	while (file >> num)
	{
		startingNumbers.push_back(num);
	}
}

void Day15::RunPuzzle1()
{
	std::vector<size_t> memory = startingNumbers;
	while (memory.size() < 2020)
	{
		size_t dist = 0;
		for (int i = memory.size()-2; i >= 0; i--)
		{
			if (memory.back() == memory[i])
			{
				dist = memory.size() - 1 - i;
				break;
			}
		}
		memory.push_back(dist);
	}

	std::cout << "2020'th number: " << memory[2019] << std::endl;
}

void Day15::RunPuzzle2()
{
	int nextNumber = startingNumbers.back();
	size_t total = 30000000;
	int* lastSpokenAt = new int[total];
	for (size_t i = 0; i < total; i++)
	{
		lastSpokenAt[i] = -1;
	}
	for (size_t i = 0; i < startingNumbers.size() - 1; i++)
	{
		lastSpokenAt[startingNumbers[i]] = i;
	}
	std::cout << std::string(100, ' ') << "|\r";
	for (size_t at = 5; at < total-1; at++)
	{
		for (size_t i = 0; i < total/100 && at < total - 1; i++,at++)
		{
			int opt[] = { 0, at - lastSpokenAt[nextNumber] };
			int tmp = opt[(int)(lastSpokenAt[nextNumber] != -1)];
			lastSpokenAt[nextNumber] = at;
			nextNumber = tmp;
		}

		std::cout << "#";
	}
	std::cout << "\r" << std::string(101, ' ') << "\r";
	std::cout << "30000000'th number: " << nextNumber << std::endl;
}
