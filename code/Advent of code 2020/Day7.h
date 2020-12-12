#pragma once

#include "Puzzle.h"


class Day7 : public Puzzle
{
public:
	typedef std::string BagIdentifier;
	struct Bag
	{
		struct BagContent
		{
			int amount;
			BagIdentifier ident;
		};

		std::vector<BagContent> contents;
	};

	std::unordered_map<BagIdentifier, Bag> bagRules;

	Day7(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	size_t TotalBags(Bag& aBag);
};

