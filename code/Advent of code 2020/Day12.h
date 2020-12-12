#pragma once

#include "Puzzle.h"


class Day12 : public Puzzle
{
public:
	Day12(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	struct Instruction
	{
		enum class Type
		{
			N,
			S,
			E,
			W,
			L,
			R,
			F
		};
		Type myType;
		int myNumber;
	};

	std::vector<Instruction> instructions;
};

