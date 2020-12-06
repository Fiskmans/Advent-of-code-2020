#include "stdafx.h"
#include "Day5.h"

Day5::Day5(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	std::string line;
	while (file >> line)
	{
		unsigned int val = 0;
		for (size_t i = 0; i < 10; i++)
		{
			val <<= 1;
			char c = line[i];
			switch (c)
			{
			case 'B':
			case 'R':
				val += 1;
				break;
			}
		}
		numbers.push_back(val);
	}
}

void Day5::RunPuzzle1()
{
	unsigned int max = 0;
	for (auto& i : numbers)
	{
		max = std::max(max, i);
	}
	std::cout << "max id: " << max << std::endl;
}

void Day5::RunPuzzle2()
{
	std::sort(numbers.begin(), numbers.end());
	for (size_t i = 1; i < numbers.size(); i++)
	{
		if (numbers[i - 1] + 1 != numbers[i])
		{
			std::cout << "Your seat: " << numbers[i]-1 << std::endl;
		}
	}
}
