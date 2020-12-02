#pragma once

#include "Puzzle.h"


class Day20 : public Puzzle
{
public:
	Day20(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

