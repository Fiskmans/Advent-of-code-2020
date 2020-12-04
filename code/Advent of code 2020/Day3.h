#pragma once

#include "Puzzle.h"

class Day3 : public Puzzle
{
public:
	Day3(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	std::vector<std::vector<bool>> map;
};

