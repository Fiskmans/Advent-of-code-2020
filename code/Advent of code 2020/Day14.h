#pragma once

#include "Puzzle.h"


class Day14 : public Puzzle
{
public:
	Day14(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

