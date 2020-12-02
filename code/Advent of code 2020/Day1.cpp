#include "stdafx.h"

#include "Day1.h"

Day1::Day1(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	int number;
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;
	while (file >> number)
	{
		expenseReport.push_back(number);
	}
}

void Day1::RunPuzzle1()
{
	std::cout << "Puzzle 1" << std::endl;
	for (int& a : expenseReport)
	{
		for (int& b : expenseReport)
		{
			if (a + b == 2020)
			{
				std::cout << a << " and " << b << " sum to 2020 and multiply to: " << a * b << std::endl;
			}
		}
	}
}

void Day1::RunPuzzle2()
{
	std::cout << "Puzzle 2" << std::endl;
	for (int& a : expenseReport)
	{
		for (int& b : expenseReport)
		{
			for (int& c : expenseReport)
			{
				if (a + b + c == 2020)
				{
					std::cout << a << ", " << b << " and " << c << " sum to 2020 and multiply to: " << a * b * c << std::endl;
				}
			}
		}
	}
}