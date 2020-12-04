#pragma once

#include "Puzzle.h"


class Day4 : public Puzzle
{
public:
	Day4(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;


	struct Passport
	{
		std::string byr;
		std::string iyr;
		std::string eyr;
		std::string hgt;
		std::string hcl;
		std::string ecl;
		std::string pid;
		std::string cid;
	};
	std::vector<Passport> passports;
};

