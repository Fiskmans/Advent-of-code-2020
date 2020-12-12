#include "stdafx.h"
#include "Day7.h"

Day7::Day7(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream stream(line);
		std::string kw1, kw2, okw1, okw2;
		std::string separator;
		std::string number;

		if (stream >> okw1 >> okw2 >> separator >> separator)
		{
			bool more = false;
			Bag bag;

			do
			{
				more = false;
				if (stream >> number >> kw1 >> kw2 >> separator)
				{
					if (separator.back() == ',')
					{
						more = true;
					}
					if (number == "no")
					{
						continue;
					}
					int num;
					std::stringstream(number) >> num;
					bag.contents.push_back({ num, kw1 + kw2 });
				}
			} while (more);

			bagRules[okw1 + okw2] = bag;
		}
	}

}

void Day7::RunPuzzle1()
{
	std::unordered_set<BagIdentifier> valid;

	std::vector<BagIdentifier> queue;
	queue.push_back({ "shinygold" });

	while (!queue.empty())
	{
		BagIdentifier id = queue.back();
		queue.pop_back();

		for (auto [ruleId, bag] : bagRules)
		{
			for (auto& content : bag.contents)
			{
				if (content.ident == id)
				{
					queue.push_back(ruleId);
					valid.insert(ruleId);
				}
			}
		}
	}

	std::cout << "Bags that could contain shiny gold: " << valid.size() << std::endl;
}

void Day7::RunPuzzle2()
{

	std::cout << "Bags in shiny gold: " << TotalBags(bagRules["shinygold"]) << std::endl;
}

size_t Day7::TotalBags(Bag& aBag)
{
	size_t amount = 0;
	for (auto& i : aBag.contents)
	{
		Bag& bag = bagRules[i.ident];
		amount += (TotalBags(bag) + 1) * i.amount;
	}
	return amount;
}
