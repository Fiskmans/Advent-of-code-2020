#pragma once

#include "Puzzle.h"


class Day17 : public Puzzle
{
public:
	Day17(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

