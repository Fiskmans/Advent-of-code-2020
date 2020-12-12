#include "stdafx.h"
#include "Day8.h"

Day8::Day8(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	std::string op;
	int number;
	while (file >> op >> number)
	{
		Instruction i;
		i.imm8 = number;
		if (op == "nop")
		{
			i.opCode = Opcode::Nop;
		}
		else if (op == "acc")
		{
			i.opCode = Opcode::Acc;
		}
		else if (op == "jmp")
		{
			i.opCode = Opcode::Jmp;
		}
		i.hasExecuted = false;
		code.push_back(i);
	}

}

void Day8::RunPuzzle1()
{
	bool _;
	std::cout << "acc at end: " << Exec(_) << std::endl;
}

void Day8::RunPuzzle2()
{
	for (size_t i = 0; i < code.size(); i++)
	{
		switch (code[i].opCode)
		{
		case Opcode::Nop:
			code[i].opCode = Opcode::Jmp;
			break;
		case Opcode::Jmp:
			code[i].opCode = Opcode::Nop;
			break;
		case Opcode::Acc:
			continue;
		}

		Reset();
		bool end;
		int res = Exec(end);
		if (end)
		{
			std::cout << "acc at end: " << res << " corrupted instruction: " << i << std::endl;
		}

		switch (code[i].opCode)
		{
		case Opcode::Nop:
			code[i].opCode = Opcode::Jmp;
			break;
		case Opcode::Jmp:
			code[i].opCode = Opcode::Nop;
			break;
		}
	}

	std::cout << "Not done yet" << std::endl;
}

int Day8::Exec(bool& aReachedEnd)
{

	rip = 0;
	eax = 0;

	while (rip < code.size() && !code[rip].hasExecuted)
	{
		code[rip].hasExecuted = true;
		switch (code[rip].opCode)
		{
		case Opcode::Nop:
			rip++;
			break;
		case Opcode::Jmp:
			rip += code[rip].imm8;
			break;
		case Opcode::Acc:
			eax += code[rip].imm8;
			rip++;
			break;
		}
	}
	aReachedEnd = rip >= code.size();

	return eax;
}

void Day8::Reset()
{
	for (auto& i : code)
	{
		i.hasExecuted = false;
	}
}
