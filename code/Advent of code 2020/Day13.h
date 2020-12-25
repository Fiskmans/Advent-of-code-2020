#pragma once

#include "Puzzle.h"


class Day13 : public Puzzle
{
public:
	Day13(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	int now;
	std::vector<int> departures;
};

