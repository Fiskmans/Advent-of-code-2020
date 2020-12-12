#include "stdafx.h"
#include "Day11.h"

Day11::Day11(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;
	std::string line;
	while (std::getline(file,line))
	{
		std::vector<Slot> row;
		for (auto& i : line)
		{
			switch (i)
			{
			case '.':
				row.push_back(Slot::Floor);
				break;
			case 'L':
				row.push_back(Slot::Seat);
				break;
			case '#':
				row.push_back(Slot::Person);
				break;
			}
		}
		playfield.push_back(row);
	}
}

void Day11::RunPuzzle1()
{
	std::vector<std::vector<Slot>> current = playfield;

	int changed = 0;
	do
	{
		changed = 0;
		std::vector<std::vector<Slot>> next;
		for (int y = 0; y < current.size(); y++)
		{
			std::vector<Slot>& currRow = current[y];
			std::vector<Slot> nextRow;

			for (int x = 0; x < currRow.size(); x++)
			{
				int surroundedCount = 0;
				const static std::vector<std::pair<int, int>> offsets =
				{
					{ 0, 1},
					{ 0,-1},
					{ 1, 0},
					{-1, 0},
					{ 1, 1},
					{-1, 1},
					{ 1,-1},
					{-1,-1},
				};
				for (auto& off : offsets)
				{
					int x2 = x + off.first;
					int y2 = y + off.second;
					if (x2 >= 0 && y2 >= 0)
					{
						if (x2 < currRow.size() && y2 < current.size())
						{
							if (current[y2][x2] == Slot::Person)
							{
								surroundedCount++;
							}
						}
					}
				}
				Slot nextTick = Slot::Floor;
				switch (currRow[x])
				{
				case Slot::Person:
					if (surroundedCount > 3)
					{
						nextTick = Slot::Seat;
						changed++;
					}
					else
					{
						nextTick = Slot::Person;
					}
					break;
				case Slot::Seat:
					if (surroundedCount == 0)
					{
						nextTick = Slot::Person;
						changed++;
					}
					else
					{
						nextTick = Slot::Seat;
					}
					break;

				default:
					break;
				}
				nextRow.push_back(nextTick);
			}
			next.push_back(nextRow);
		}
		current = next;
	} while (changed > 0);

	int endCount = 0;
	for (auto& i : current)
	{
		for (auto& x : i)
		{
			if (x == Slot::Person)
			{
				endCount++;
			}
		}
	}


	std::cout << "Total takes seats once stable: "<< endCount << std::endl;
}

void Day11::RunPuzzle2()
{
	std::vector<std::vector<Slot>> current = playfield;

	int changed = 0;
	do
	{
		changed = 0;
		std::vector<std::vector<Slot>> next;
		for (int y = 0; y < current.size(); y++)
		{
			std::vector<Slot>& currRow = current[y];
			std::vector<Slot> nextRow;

			for (int x = 0; x < currRow.size(); x++)
			{
				int surroundedCount = 0;
				const static std::vector<std::pair<int, int>> offsets =
				{
					{ 0, 1},
					{ 0,-1},
					{ 1, 0},
					{-1, 0},
					{ 1, 1},
					{-1, 1},
					{ 1,-1},
					{-1,-1},
				};
				for (auto& off : offsets)
				{
					int x2 = x;
					int y2 = y;
					while (true)
					{
						x2 += off.first;
						y2 += off.second;
						if (x2 >= 0 && y2 >= 0 && x2 < currRow.size() && y2 < current.size())
						{
							Slot at = current[y2][x2];
							if (at == Slot::Person)
							{
								surroundedCount++;
								break;
							}
							else if (at == Slot::Seat)
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
				}
				Slot nextTick = Slot::Floor;
				switch (currRow[x])
				{
				case Slot::Person:
					if (surroundedCount > 4)
					{
						nextTick = Slot::Seat;
						changed++;
					}
					else
					{
						nextTick = Slot::Person;
					}
					break;
				case Slot::Seat:
					if (surroundedCount == 0)
					{
						nextTick = Slot::Person;
						changed++;
					}
					else
					{
						nextTick = Slot::Seat;
					}
					break;

				default:
					break;
				}
				nextRow.push_back(nextTick);
			}
			next.push_back(nextRow);
		}
		current = next;
	} while (changed > 0);

	int endCount = 0;
	for (auto& i : current)
	{
		for (auto& x : i)
		{
			if (x == Slot::Person)
			{
				endCount++;
			}
		}
	}

	std::cout << "Total takes seats once stable: " << endCount << std::endl;
}
