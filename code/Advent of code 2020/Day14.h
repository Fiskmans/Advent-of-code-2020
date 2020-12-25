#pragma once

#include "Puzzle.h"


class Day14 : public Puzzle
{
public:
	Day14(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	struct Instruction
	{
		struct Mem
		{
			size_t address;
			size_t data;
		};

		struct Mask
		{
			size_t maskOn;
			size_t maskOff;
			size_t floating;
		};

		std::variant<Mem, Mask> data;
	};

	std::vector<Instruction> instructions;
};

