#pragma once

#include "Puzzle.h"


class Day25 : public Puzzle
{
public:
	Day25(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

