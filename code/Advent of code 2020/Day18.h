#pragma once

#include "Puzzle.h"


class Day18 : public Puzzle
{
public:
	Day18(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

