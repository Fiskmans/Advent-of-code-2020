#include "stdafx.h"

#include "Puzzles.h"

Puzzle* Select()
{
	int selected = 11;
	switch (selected)
	{
	case 0:
		return new Day1("Input/Day1.txt");
	case 1:
		return new Day2("Input/Day2.txt");
	case 2:
		return new Day3("Input/Day3.txt");
	case 3:
		return new Day4("Input/Day4.txt");
	case 4:
		return new Day5("Input/Day5.txt");
	case 5:
		return new Day6("Input/Day6.txt");
	case 6:
		return new Day7("Input/Day7.txt");
	case 7:
		return new Day8("Input/Day8.txt");
	case 8:
		return new Day9("Input/Day9.txt");
	case 9:
		return new Day10("Input/Day10.txt");
	case 10:
		return new Day11("Input/Day11.txt");
	case 11:
		return new Day12("Input/Day12.txt");
	case 12:
		return new Day13("Input/Day13.txt");
	case 13:
		return new Day14("Input/Day14.txt");
	case 14:
		return new Day15("Input/Day15.txt");
	case 15:
		return new Day16("Input/Day16.txt");
	case 16:
		return new Day17("Input/Day17.txt");
	case 17:
		return new Day18("Input/Day18.txt");
	case 18:
		return new Day19("Input/Day19.txt");
	case 19:
		return new Day20("Input/Day20.txt");
	case 20:
		return new Day21("Input/Day21.txt");
	case 21:
		return new Day22("Input/Day22.txt");
	case 22:
		return new Day23("Input/Day23.txt");
	case 23:
		return new Day24("Input/Day24.txt");
	case 24:
		return new Day25("Input/Day25.txt");
	}
}

int main()
{
	auto* puzzle = Select();
	std::cout << "Puzzle 1" << std::endl;
	puzzle->RunPuzzle1();
	std::cout << "Puzzle 2" << std::endl;
	puzzle->RunPuzzle2();
	delete puzzle;
	return 1;
}
