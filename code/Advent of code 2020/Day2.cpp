#include "stdafx.h"
#include "Day2.h"

Day2::Day2(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	PasswordWithRule pass;
	char dash;
	char colon;
	while (file >> pass.lower >> dash >> pass.upper >> pass.letter >> colon >> pass.password)
	{
		passwords.push_back(pass);
	}
}

void Day2::RunPuzzle1()
{
	std::cout << "Puzzle 1" << std::endl;
	int valid = 0;
	for (PasswordWithRule& pass : passwords)
	{
		int count = 0;
		for (char& c : pass.password)
		{
			if (c == pass.letter)
			{
				count++;
			}
		}
		if (count >= pass.lower && count <= pass.upper)
		{
			valid++;
		}
	}
	std::cout << "There are " << valid << " valid passwords" << std::endl;
}

void Day2::RunPuzzle2()
{
	std::cout << "Puzzle 2" << std::endl;
	int valid = 0;
	for (PasswordWithRule& pass : passwords)
	{
		if ((pass.password[pass.lower-1] == pass.letter) ^ (pass.password[pass.upper-1] == pass.letter))
		{
			valid++;
		}
	}
	std::cout << "There are " << valid << " valid passwords" << std::endl;
}
