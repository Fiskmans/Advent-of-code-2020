#pragma once

#include "Puzzle.h"


class Day11 : public Puzzle
{
public:
	Day11(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	enum Slot
	{
		Floor,
		Seat,
		Person
	};

	std::vector<std::vector<Slot>> playfield;
};

