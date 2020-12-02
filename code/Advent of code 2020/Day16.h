#pragma once

#include "Puzzle.h"


class Day16 : public Puzzle
{
public:
	Day16(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

};

