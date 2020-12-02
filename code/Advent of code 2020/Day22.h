#pragma once

#include "Puzzle.h"


class Day22 : public Puzzle
{
public:
	Day22(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

