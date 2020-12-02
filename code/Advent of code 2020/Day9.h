#pragma once

#include "Puzzle.h"


class Day9 : public Puzzle
{
public:
	Day9(std::string aInputFile);
	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	std::vector<int> expenseReport;
};
