#pragma once

#include "Puzzle.h"


class Day4 : public Puzzle
{
public:
	Day4(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

