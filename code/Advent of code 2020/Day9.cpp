#include "stdafx.h"

#include "Day9.h"

Day9::Day9(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;
	long number;
	while (file >> number)
	{
		numbers.push_back(number);
	}
}

void Day9::RunPuzzle1()
{
	long firstWrong = 0;
	std::vector<long> last25;
	for (auto& i : numbers)
	{
		if (last25.size() == 25)
		{
			bool found = false;
			for (size_t a = 0; a < last25.size() && !found; a++)
			{
				for (size_t b = 0; b < last25.size(); b++)
				{
					if (a != b)
					{
						if (last25[a] + last25[b] == i)
						{
							found = true;
							break;
						}
					}
				}
			}
			if (found)
			{
				last25.erase(last25.begin());
			}
			else
			{
				firstWrong = i;
				break;
			}
		}
		last25.push_back(i);
	}
	std::cout << "First wrong number: " << firstWrong << std::endl;
}

void Day9::RunPuzzle2()
{
	long firstWrong = 0;
	std::vector<long> last25;
	for (auto& i : numbers)
	{
		if (last25.size() == 25)
		{
			bool found = false;
			for (size_t a = 0; a < last25.size() && !found; a++)
			{
				for (size_t b = 0; b < last25.size(); b++)
				{
					if (a != b)
					{
						if (last25[a] + last25[b] == i)
						{
							found = true;
							break;
						}
					}
				}
			}
			if (found)
			{
				last25.erase(last25.begin());
			}
			else
			{
				firstWrong = i;
				break;
			}
		}
		last25.push_back(i);
	}

	long weakness = 0;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		long sum = 0;
		long largest = std::numeric_limits<long>::min();
		long smallest = std::numeric_limits<long>::max();
		for (size_t a = i; a < numbers.size(); a++)
		{
			sum += numbers[a];
			largest = std::max(largest,numbers[a]);
			smallest = std::min(smallest, numbers[a]);
			if (sum >= firstWrong)
			{
				break;
			}
		}
		if (sum == firstWrong)
		{
			weakness = smallest + largest;
			break;
		}
	}
	std::cout << "Encryption weakness: " << weakness << std::endl;
}