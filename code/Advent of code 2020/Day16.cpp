#include "stdafx.h"
#include "Day16.h"

Day16::Day16(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	for (size_t i = 0; i < 20; i++)
	{
		Rule r;
		file >> r.name >> r.min1 >> r.max1 >> r.min2 >> r.max2;
		rules.push_back(r);
	}
	
	for (size_t i = 0; i < rules.size(); i++)
	{
		size_t val;
		file >> val;
		myTicket.fields.push_back(val);
	}

	while (file)
	{
		Ticket t;
		t.valid = true;
		for (size_t i = 0; i < rules.size(); i++)
		{
			size_t val;
			file >> val;
			t.fields.push_back(val);
		}
		if (file)
		{
			tickets.push_back(t);
		}
	}

}

void Day16::RunPuzzle1()
{
	size_t totalFailed = 0;
	for (Ticket& ticket : tickets)
	{
		if (!ticket.valid)
		{
			break;
		}
		for (size_t& field : ticket.fields)
		{
			if (!ticket.valid)
			{
				break;
			}
			bool anyValid = false;
			for (Rule& rule : rules)
			{
				if (FitsRule(rule,field))
				{
					anyValid = true;
				}
			}
			if (!anyValid)
			{
				totalFailed += field;
				ticket.valid = false;
				break;
			}
		}
	}

	std::cout << "Scanning error freq: " << totalFailed << std::endl;
}

void Day16::RunPuzzle2()
{
	std::vector<Ticket> ticks = tickets;
	for (int i = ticks.size() - 1; i >= 0; i--)
	{
		if (!ticks[i].valid)
		{
			ticks.erase(ticks.begin() + i);
		}
	}


	std::vector<int> unassignedRules;
	std::vector<std::vector<int>> rulesCanBe;

	for (size_t i = 0; i < rules.size(); i++)
	{
		unassignedRules.push_back(i); 
		rulesCanBe.emplace_back();

		for (size_t j = 0; j < rules.size(); j++)
		{
			rulesCanBe.back().push_back(j);
		}
	}

	while (!unassignedRules.empty())
	{
		for (int& fieldIndex : unassignedRules)
		{
			for (size_t ruleIndex = 0; ruleIndex < rules.size(); ruleIndex++)
			{
				Rule& rule = rules[ruleIndex];
				bool canBe = false;
				int index = -1;
				for (size_t i = 0; i < rulesCanBe[ruleIndex].size(); i++)
				{
					if (rulesCanBe[ruleIndex][i] == fieldIndex)
					{
						canBe = true;
						index = i;
					}
				}
				if (canBe)
				{
					for (Ticket& ticket : ticks)
					{
						size_t field = ticket.fields[fieldIndex];
						if(!FitsRule(rule,field))
						{
							canBe = false;
						}
					}
					if (!canBe)
					{
						rulesCanBe[ruleIndex].erase(rulesCanBe[ruleIndex].begin() + index);
					}
				}
			}
		}

		bool somethingchanged = false;
		do
		{
			somethingchanged = false;
			for (size_t ruleIndex = 0; ruleIndex < rulesCanBe.size(); ruleIndex++)
			{
				if (rulesCanBe[ruleIndex].size() == 1)
				{
					somethingchanged = true;
					size_t field = rulesCanBe[ruleIndex][0];
					rules[ruleIndex].fieldIndex = field;
					for (size_t i = 0; i < unassignedRules.size(); i++)
					{
						if (unassignedRules[i] == field)
						{
							unassignedRules.erase(unassignedRules.begin() + i);
							break;
						}
					}
					for (size_t ruleindex2 = 0; ruleindex2 < rulesCanBe.size(); ruleindex2++)
					{
						for (size_t i = 0; i < rulesCanBe[ruleindex2].size(); i++)
						{
							if (rulesCanBe[ruleindex2][i] == field)
							{
								rulesCanBe[ruleindex2].erase(rulesCanBe[ruleindex2].begin() + i);
								break;
							}
						}
					}
				}
			}
		} while (somethingchanged);

	}

	size_t mult = 1;
	for (Rule& rule : rules)
	{
		if (rule.name.length() > 9 && rule.name.substr(0,9) == "departure")
		{
			mult *= myTicket.fields[rule.fieldIndex];
		}
	}

	std::cout << "Mult of all departurefields: " << mult << std::endl;
}

bool Day16::FitsRule(Rule& aRule, size_t aValue)
{
	bool first = aValue <= aRule.max2 && aValue >= aRule.min2;
	bool second = (aValue <= aRule.max1 && aValue >= aRule.min1);
	return (first || second);
}
