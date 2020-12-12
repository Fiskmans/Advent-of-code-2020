#pragma once

#include "Puzzle.h"


class Day10 : public Puzzle
{
public:
	Day10(std::string aInputFile);
	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	std::vector<int> joltConverters;
	std::vector<int> gaps;
};
