#pragma once

#include "Puzzle.h"


class Day16 : public Puzzle
{
public:
	Day16(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	struct Rule
	{
		std::string name;
		size_t min1;
		size_t min2;
		size_t max1;
		size_t max2;
		int fieldIndex = -1;
	};

	struct Ticket
	{
		std::vector<size_t> fields;
		bool valid;
	};

	std::vector<Rule> rules;
	Ticket myTicket;
	std::vector<Ticket> tickets;


	static bool FitsRule(Rule& aRule, size_t aValue);
};

