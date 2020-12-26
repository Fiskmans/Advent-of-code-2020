#include "stdafx.h"
#include "Day18.h"

Day18::Day18(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	std::string tok;
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream row(line);
		AllTokens.emplace_back();

		while (row >> tok)
		{
			Token t;
			t.number = 0;

			if(tok == "(")
			{
				t.type = TokenType::LParen;
			}
			else if (tok == ")")
			{
				t.type = TokenType::RParen;
			}
			else if (tok == "+")
			{
				t.type = TokenType::Plus;
			}
			else if (tok == "*")
			{
				t.type = TokenType::Mult;
			}
			else
			{
				std::from_chars(tok.c_str(), tok.c_str() + tok.length(), t.number);
				t.type = TokenType::Number;
			}

			AllTokens.back().push_back(t);
		}
	}

}

void Day18::RunPuzzle1()
{
	std::cout << "Not done yet" << std::endl;
}

void Day18::RunPuzzle2()
{
	std::cout << "Not done yet" << std::endl;
}
