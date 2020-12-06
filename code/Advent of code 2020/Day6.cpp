#include "stdafx.h"
#include "Day6.h"

Day6::Day6(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	std::bitset<charachters> set;
	std::bitset<charachters> set2;
	std::string line;

	set.reset();
	set2.set();
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::string out;
			for (size_t i = 0; i < set.size(); i++)
			{
				if (set[i])
				{
					out += ('a' + i);
				}
			}

			surveys.push_back(set);
			set.reset();
			andsurveys.push_back(set2);
			set2.set();
		}
		else
		{
			std::bitset<charachters> setSub;
			for (char& c : line)
			{
				if (c > 'z' || c < 'a')
				{
					continue;
				}
				set.set(c - 'a');
				setSub.set(c - 'a');
			}
			for (size_t i = 0; i < set.size(); i++)
			{
				if (!setSub[i])
				{
					set2.reset(i);
				}
			}
		}
	}
	surveys.push_back(set);
	set.reset();
	andsurveys.push_back(set2);
	set2.set();
}

void Day6::RunPuzzle1()
{
	int total = 0;
	for (auto& surv : surveys)
	{
		total += surv.count();
	}
	std::cout << "Total or'es: " << total << std::endl;
}

void Day6::RunPuzzle2()
{
	int total = 0;
	for (auto& surv : andsurveys)
	{
		total += surv.count();
	}
	std::cout << "Total or'es: " << total << std::endl;
}
