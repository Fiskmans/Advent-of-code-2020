#pragma once

#include "Puzzle.h"


class Day5 : public Puzzle
{
public:
	Day5(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;


	std::vector<unsigned int> numbers;
};

