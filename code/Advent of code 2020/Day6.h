#pragma once

#include "Puzzle.h"


class Day6 : public Puzzle
{
public:
	Day6(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

