#pragma once

#include "Puzzle.h"


class Day23 : public Puzzle
{
public:
	Day23(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

