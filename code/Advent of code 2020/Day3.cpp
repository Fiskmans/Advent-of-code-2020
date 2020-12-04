#include "stdafx.h"
#include "Day3.h"

Day3::Day3(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;
	std::string line;
	while (std::getline(file,line))
	{
		map.emplace_back();
		for (size_t i = 0; i < line.length(); i++)
		{
			map.back().push_back(line[i] == '#');
		}
	}
}

void Day3::RunPuzzle1()
{
	int x = 0;
	int treesHit = 0;
	for (size_t y = 0; y < map.size(); y++)
	{
		x %= map[y].size();
		if (map[y][x])
		{
			treesHit++;
		}
		x += 3;
	}
	std::cout << "3:1 trajectory would hit " << treesHit << " trees." << std::endl;
}

void Day3::RunPuzzle2()
{
	unsigned int total = 1;
	struct traj
	{
		int x;
		int y;
	};
	std::vector<traj> angles = { {1,1}, {3,1},{5,1},{7,1},{1,2} };

	for (size_t i = 0; i < angles.size(); i++)
	{
		int x = 0;
		int y = 0;
		unsigned int treesHit = 0;
		while(y < map.size())
		{
			x %= map[y].size();
			if (map[y][x])
			{
				treesHit++;
			}
			x += angles[i].x;
			y += angles[i].y;
		}
		total *= treesHit;
		std::cout << angles[i].x << ":" << angles[i].y << " trajectory would hit " << treesHit << " trees. [" << total << "]" << std::endl;
	}

	std::cout << "Total multiplated treecollisions: " << total << std::endl;
}
