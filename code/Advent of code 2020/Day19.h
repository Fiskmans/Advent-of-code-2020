#pragma once

#include "Puzzle.h"


class Day19 : public Puzzle
{
public:
	Day19(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

