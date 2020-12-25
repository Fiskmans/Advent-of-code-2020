#include "stdafx.h"
#include "Day14.h"


Day14::Day14(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	std::string type;
	while (file >> type)
	{
		Instruction instr;
		if (type == "mem")
		{
			Instruction::Mem mem;
			file >> mem.address >> mem.data;
			instr.data = mem;
		}
		else if (type == "mask")
		{
			std::string mask;
			size_t on = 0;
			size_t off = 0;
			size_t floating = 0;
			if (file >> mask)
			{
				for (char& c : mask)
				{
					on <<= 1;
					off <<= 1;
					floating <<= 1;
					switch (c)
					{
					case '1':
						on |= 1ULL;
						break;
					case '0':
						off |= 1ULL;
						break;
					}
					floating |= !((off & 1ULL) || (on & 1ULL));
				}
			}
			Instruction::Mask dmask;
			dmask.maskOn = on;
			dmask.maskOff = off;
			dmask.floating = floating;
			instr.data = dmask;
		}
		instructions.push_back(instr);
	}
}

void Day14::RunPuzzle1()
{
	std::unordered_map<size_t, size_t> memory;
	size_t onMask = 0;
	size_t offMask = 0;
	for (Instruction& i : instructions)
	{
		switch (i.data.index())
		{
		case 0:	// Instruction::Mem
		{
			Instruction::Mem mem = std::get<0>(i.data);
			size_t data = mem.data;
			data |= onMask;
			data &= ~offMask;
			memory[mem.address] = data;
		}
		break;

		case 1: // Instruction::Mask
		{
			Instruction::Mask mask = std::get<1>(i.data);
			onMask = mask.maskOn;
			offMask = mask.maskOff;
		}
		break;
		}
	}

	size_t sum = std::accumulate(memory.begin(), memory.end(), std::make_pair<size_t, size_t>(0, 0), [](const std::pair<size_t, size_t>& aLHS, const std::pair<size_t, size_t>& aRHS) { return std::make_pair(aLHS.first + aRHS.first, aLHS.second + aRHS.second); }).second;
	std::cout << "Total sum in memory: " << sum << std::endl;
}

void Day14::RunPuzzle2()
{
	std::unordered_map<size_t, size_t> memory;
	size_t onMask = 0;
	size_t offMask = 0;
	std::vector<size_t> masks;
	for (Instruction& i : instructions)
	{
		switch (i.data.index())
		{
		case 0:	// Instruction::Mem
		{
			Instruction::Mem mem = std::get<0>(i.data);
			size_t address = mem.address;
			address |= onMask;
			for (size_t i = 0; i < 1ULL << masks.size(); i++)
			{
				size_t add = address;
				for (size_t x = 0; x < masks.size(); x++)
				{
					add ^= (i & (1ULL << x)) ? masks[x] : 0ULL;
				}
				memory[add] = mem.data;
			}
		}
		break;

		case 1: // Instruction::Mask
		{
			Instruction::Mask mask = std::get<1>(i.data);
			onMask = mask.maskOn;
			offMask = mask.maskOff;

			masks.clear();
			for (size_t i = 0; i < sizeof(mask.floating) * CHAR_BIT; i++)
			{
				if ((mask.floating & (1ULL << i)) != 0ULL)
				{
					masks.push_back((1ULL << i));
				}
			}
		}
		break;
		}
	}

	size_t sum = std::accumulate(memory.begin(), memory.end(), std::make_pair<size_t, size_t>(0, 0), [](const std::pair<size_t, size_t>& aLHS, const std::pair<size_t, size_t>& aRHS) { return std::make_pair(aLHS.first + aRHS.first, aLHS.second + aRHS.second); }).second;
	std::cout << "Total sum in memory: " << sum << std::endl;
}
