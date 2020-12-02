#pragma once

#include "Puzzle.h"


class Day7 : public Puzzle
{
public:
	Day7(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

