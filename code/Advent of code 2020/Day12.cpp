#include "stdafx.h"
#include "Day12.h"

Day12::Day12(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;
	char c;
	int number;

	while (file >> c >> number)
	{
		Instruction  i;
		i.myNumber = number;
		switch (c)
		{
		case 'N': i.myType = Instruction::Type::N; break;
		case 'S': i.myType = Instruction::Type::S; break;
		case 'E': i.myType = Instruction::Type::E; break;
		case 'W': i.myType = Instruction::Type::W; break;
		case 'L': i.myType = Instruction::Type::L; break;
		case 'R': i.myType = Instruction::Type::R; break;
		case 'F': i.myType = Instruction::Type::F; break;
		default:
			break;
		}
		instructions.push_back(i);
	}
}

void Day12::RunPuzzle1()
{
	int direction = 0;
	int x = 0;
	int y = 0;

	std::pair<int, int> dir[4] =
	{
		{1,0},
		{0,1},
		{-1,0},
		{0,-1}
	};

	for (Instruction& instr : instructions)
	{
		switch (instr.myType)
		{
		case Instruction::Type::N:
			y += instr.myNumber;
			break;
		case Instruction::Type::S:
			y -= instr.myNumber;
			break;
		case Instruction::Type::E:
			x += instr.myNumber;
			break;
		case Instruction::Type::W:
			x -= instr.myNumber;
			break;
		case Instruction::Type::L:
			direction += instr.myNumber;
			break;
		case Instruction::Type::R:
			direction -= instr.myNumber;
			{
				if (direction < 0)
				{
					direction += 360;
				}
			}
			break;
		case Instruction::Type::F:
		{
			x += dir[direction % 360 / 90].first * instr.myNumber;
			y += dir[direction % 360 / 90].second * instr.myNumber;
		}
			break;
		}
	}


	std::cout << "Manhattandistance at end: " << std::abs(x) + std::abs(y) << std::endl;
}

void Day12::RunPuzzle2()
{
	int x = 0;
	int y = 0;

	int dx = 10;
	int dy = 1;

	for (Instruction& instr : instructions)
	{
		switch (instr.myType)
		{
		case Instruction::Type::N:
			dy += instr.myNumber;
			break;
		case Instruction::Type::S:
			dy -= instr.myNumber;
			break;
		case Instruction::Type::E:
			dx += instr.myNumber;
			break;
		case Instruction::Type::W:
			dx -= instr.myNumber;
			break;
		case Instruction::Type::L:
			for (size_t i = 0; i < instr.myNumber/90; i++)
			{
				int olddx = dx;
				int olddy = dy;
				dx = -olddy;
				dy = olddx;
			}
			break;
		case Instruction::Type::R:
			for (size_t i = 0; i < instr.myNumber / 90; i++)
			{
				int olddx = dx;
				int olddy = dy;
				dx = olddy;
				dy = -olddx;
			}
			break;
		case Instruction::Type::F:
		{
			x += dx * instr.myNumber;
			y += dy * instr.myNumber;
		}
		break;
		}
	}


	std::cout << "Manhattandistance at end: " << std::abs(x) + std::abs(y) << std::endl;
}
