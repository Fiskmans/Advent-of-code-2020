#include "stdafx.h"
#include "Day10.h"

Day10::Day10(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	int val;
	joltConverters.push_back(0);
	while (file >> val)
	{
		joltConverters.push_back(val);
	}
	std::sort(joltConverters.begin(), joltConverters.end());
	joltConverters.push_back(joltConverters.back()+3);



	for (size_t i = 1; i < joltConverters.size(); i++)
	{
		int delta = joltConverters[i] - joltConverters[i - 1];
		gaps.push_back(delta);
	}
}

void Day10::RunPuzzle1()
{
	int oneStep = 0;
	int threeStep = 0;
	for (size_t i = 0; i < gaps.size(); i++)
	{
		switch (gaps[i])
		{
		case 1:
			oneStep++;
			break;
		case 3:
			threeStep++;
			break;
		default:
			break;
		}
	}

	std::cout << "Jolt rating: " << oneStep * threeStep << std::endl;
}


void Day10::RunPuzzle2()
{
	static Day10* local = this;
	class Node
	{
	public:
		Node(int aval)
			: myval(aval)
		{

		}
		int myval;

		std::vector<std::shared_ptr<Node>> myExits;

		bool myIsEvauluated = false;
		size_t myWaysToTeachEnd = 0;
		
		size_t Evaluate()
		{
			if (myIsEvauluated)
			{
				return myWaysToTeachEnd;
			}
			for (auto& i : myExits)
			{
				myWaysToTeachEnd += i->Evaluate();
			}
			myIsEvauluated = true;
			return myWaysToTeachEnd;
		}
	};


	std::vector<std::shared_ptr<Node>> nodes;
	nodes.resize(gaps.size());
	for (size_t i = 0; i < gaps.size(); i++)
	{
		nodes[i] = std::make_shared<Node>(i);
	}
	for (size_t i = 0; i < gaps.size(); i++)
	{
		int dist = 0;
		for (size_t a = i; a < gaps.size()-1; a++)
		{
			dist += gaps[a];
			if (dist < 4)
			{
				nodes[i]->myExits.push_back(nodes[a+1]);
			}
			else
			{
				break;
			}
		}
	}
	nodes.back()->myWaysToTeachEnd = 1;

	size_t ways = nodes[0]->Evaluate();



	std::cout << "Adaptor combinations: " << ways << std::endl;
}