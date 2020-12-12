#pragma once

#include "Puzzle.h"


class Day8 : public Puzzle
{
public:
	Day8(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	int Exec(bool& aReachedEnd);
	void Reset();

	enum class Opcode
	{
		Nop,
		Acc,
		Jmp
	};

	struct Instruction
	{
		Opcode opCode;
		int imm8;
		bool hasExecuted;
	};

	std::vector<Instruction> code;

	int eax;
	int rip;
};

