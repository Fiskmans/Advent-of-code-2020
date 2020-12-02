#pragma once

#include "Puzzle.h"


class Day8 : public Puzzle
{
public:
	Day8(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

