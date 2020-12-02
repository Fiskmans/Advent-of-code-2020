#pragma once

#include "Puzzle.h"


class Day24 : public Puzzle
{
public:
	Day24(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

