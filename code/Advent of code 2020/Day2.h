#pragma once

#include "Puzzle.h"

class Day2
	: public Puzzle
{
public:
	Day2(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	struct PasswordWithRule
	{
		int lower;
		int upper;
		char letter;
		std::string password;
	};

	std::vector<PasswordWithRule> passwords;
};

