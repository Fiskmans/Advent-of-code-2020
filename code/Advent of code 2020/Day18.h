#pragma once

#include "Puzzle.h"


class Day18 : public Puzzle
{
public:
	Day18(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;


	enum class TokenType
	{
		LParen,
		RParen,
		Plus,
		Mult,
		Number
	};

	struct Token
	{
		TokenType type;
		size_t number;
	};

	std::vector<std::vector<Token>> AllTokens;

	size_t Evaluate(std::vector<Token>& aTokens, size_t aStartAt = 0);
};

