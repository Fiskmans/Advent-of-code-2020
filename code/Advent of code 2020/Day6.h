#pragma once

#include "Puzzle.h"


class Day6 : public Puzzle
{
public:
	static const size_t charachters = 'z' - 'a' + 1;

	Day6(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	std::vector<std::bitset<charachters>> surveys;
	std::vector<std::bitset<charachters>> andsurveys;
};

