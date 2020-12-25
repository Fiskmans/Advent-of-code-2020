#pragma once

#include "Puzzle.h"


class PlayfieldCubic
{
public:
	~PlayfieldCubic();

	void Start(bool* aStart, size_t aWidth, size_t aHeight);
	
	void Step();

	size_t Count();

	size_t width;
	size_t height;
	size_t depth;

	bool* cells;
};

class PlayfieldHyperCubic
{
public:
	~PlayfieldHyperCubic();

	void Start(bool* aStart, size_t aWidth, size_t aHeight);

	void Step();

	size_t Count();

	size_t width;
	size_t height;
	size_t depth;
	size_t hyper;

	bool* cells;
};

class Day17 : public Puzzle
{
public:
	Day17(std::string aInputFile);

	// Inherited via Puzzle
	virtual void RunPuzzle1() override;
	virtual void RunPuzzle2() override;

	PlayfieldCubic field;
	PlayfieldHyperCubic field2;
};

