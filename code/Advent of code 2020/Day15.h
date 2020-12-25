#pragma once

#include "Puzzle.h"


class Day15 : public Puzzle
{
public:
	Day15(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	std::vector<size_t> startingNumbers;
};

