#pragma once

#include "Puzzle.h"


class Day21 : public Puzzle
{
public:
	Day21(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

