#include "stdafx.h"
#include "Day4.h"

Day4::Day4(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;
	std::string line;
	Passport pass;
	while (std::getline(file,line))
	{
		if (line.empty())
		{
			passports.push_back(pass);
			pass = Passport();
		}
		else
		{
			size_t at = 0;
			while (at != std::string::npos)
			{
				std::string nextPart;
				size_t nextSpace = line.find(' ', at);
				if (nextSpace == std::string::npos)
				{
					nextPart = line.substr(at);
				}
				else
				{
					nextPart = line.substr(at, nextSpace - at);
				}
				{
					size_t colon = nextPart.find(':');
					if (colon != std::string::npos)
					{
						std::string key = nextPart.substr(0, colon);
						std::string value = nextPart.substr(colon + 1);

						if (key == "byr")
							pass.byr = value;
						else if (key == "iyr")
							pass.iyr = value;
						else if (key == "eyr")
							pass.eyr = value;
						else if (key == "hgt")
							pass.hgt = value;
						else if (key == "hcl")
							pass.hcl = value;
						else if (key == "ecl")
							pass.ecl = value;
						else if (key == "pid")
							pass.pid = value;
						else if (key == "cid")
							pass.cid = value;
					}
				}

				at = nextSpace != std::string::npos ? nextSpace + 1 : std::string::npos;
			}
		}
	}
	passports.push_back(pass);
	pass = Passport();
}

void Day4::RunPuzzle1()
{
	int validCount = 0;
	for (Passport& pass : passports)
	{
		if (pass.byr.empty() || 
			pass.iyr.empty() || 
			pass.eyr.empty() || 
			pass.hgt.empty() || 
			pass.hcl.empty() || 
			pass.ecl.empty() || 
			pass.pid.empty())
		{

		}
		else
		{
			validCount++;
		}
	}
	std::cout << "Valid passports: " << validCount << std::endl;
}

void Day4::RunPuzzle2()
{
	int validCount = 0;
	for (Passport& pass : passports)
	{
		if (pass.byr.empty() ||
			pass.iyr.empty() ||
			pass.eyr.empty() ||
			pass.hgt.empty() ||
			pass.hcl.empty() ||
			pass.ecl.empty() ||
			pass.pid.empty())
		{
			continue;
		}

		if (pass.byr.length() != 4)
			continue;

		{
			int byear;
			std::stringstream(pass.byr) >> byear;
			if (byear > 2002 || byear < 1920)
				continue;
		}

		{
			int iyear;
			std::stringstream(pass.iyr) >> iyear;
			if (iyear > 2020 || iyear < 2010)
				continue;
		}

		{
			int eyear;
			std::stringstream(pass.eyr) >> eyear;
			if (eyear > 2030 || eyear < 2020)
				continue;
		}

		{
			int height;
			std::from_chars_result res = std::from_chars(pass.hgt.c_str(), pass.hgt.c_str() + pass.hgt.length(), height, 10);

			std::string type = res.ptr;
			if (type == "cm")
			{
				if (height > 193 ||height < 150)
				{
					continue;
				}
			}
			else if (type == "in")
			{
				if (height > 76 || height < 59)
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}

		{
			if (pass.hcl.length() != 7 || pass.hcl[0] != '#' )
			{
				continue;
			}
			for (size_t i = 1; i < 7; i++)
			{
				char c = pass.hcl[i];
				if (!((c <= '9' && c >= '0') || (c >= 'a' && c <= 'f')))
				{
					continue;
				}
			}
		}

		{
			if (pass.ecl != "amb" && pass.ecl != "blu" && pass.ecl != "brn" && pass.ecl != "gry" && pass.ecl != "hzl" && pass.ecl != "oth" && pass.ecl != "grn")
			{
				continue;
			}
		}

		{
			if (pass.pid.length() != 9)
			{
				continue;
			}
			for (size_t i = 0; i < 9; i++)
			{
				char c = pass.pid[i];
				if (c > '9' || c < '0')
				{
					continue;
				}
			}
		}



		validCount++;
	}
	std::cout << "Valid passports: " << validCount << std::endl;
}
