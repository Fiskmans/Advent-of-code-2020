#include "stdafx.h"
#include "Day17.h"

Day17::Day17(std::string aInputFile)
{
	std::ifstream file(aInputFile);
	std::cout << std::filesystem::canonical(aInputFile).string() << std::endl;

	size_t width = 0;
	std::string line;
	std::vector<bool> fi;
	while (std::getline(file,line))
	{
		width = line.length();
		for (auto& i : line)
		{
			fi.push_back(i == '#');
		}
	}
	bool* f = new bool[fi.size()];
	bool* f2 = new bool[fi.size()];
	for (size_t i = 0; i < fi.size(); i++)
	{
		f[i] = fi[i];
		f2[i] = fi[i];
	}
	field.Start(f,width,fi.size()/width);
	field2.Start(f2, width, fi.size() / width);
}

void Day17::RunPuzzle1()
{
	for (size_t i = 0; i < 6; i++)
	{
		field.Step();
	}
	std::cout << "Total cubes: " << field.Count() << std::endl;
}

void Day17::RunPuzzle2()
{
	for (size_t i = 0; i < 6; i++)
	{
		field2.Step();
	}
	std::cout << "Total cubes: " << field2.Count() << std::endl;
}

PlayfieldCubic::~PlayfieldCubic()
{
	delete cells;
}

void PlayfieldCubic::Start(bool* aStart, size_t aWidth, size_t aHeight)
{
	width = aWidth;
	height = aHeight;
	depth = 1;

	cells = aStart;
}

void PlayfieldCubic::Step()
{
	struct minivec
	{
		int x;
		int y;
		int z;
	};

	std::vector<minivec> offsets;

	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			for (int z = -1; z < 2; z++)
			{
				if (z != 0 || y != 0 || x != 0)
				{
					offsets.push_back({ x,y,z });
				}
			}
		}
	}


	size_t newWidth = width + 2;
	size_t newHeight = height + 2;
	size_t newDepth = depth + 2;

	size_t ydiff = width;
	size_t zdiff = height * width;

	size_t newydiff = newWidth;
	size_t newzdiff = newWidth * newHeight;

	int* count = new int[newWidth*newHeight*newDepth];


	for (int x = 0; x < newWidth; x++)
	{
		for (int y = 0; y < newHeight; y++)
		{
			for (int z = 0; z < newDepth; z++)
			{
				count[x + y * newydiff + z * newzdiff] = 0;
				for (minivec& vec : offsets)
				{
					int _x = x - 1 + vec.x;
					int _y = y - 1 + vec.y;
					int _z = z - 1 + vec.z;

					if (_x < 0 || _x >= width)
					{
						continue;
					}
					if (_y < 0 || _y >= height)
					{
						continue;
					}
					if (_z < 0 || _z >= depth)
					{
						continue;
					}

					if (cells[_x + _y * ydiff + _z * zdiff])
					{
						count[x + y * newydiff + z * newzdiff]++;
					}
				}
			}
		}
	}

	bool* newField = new bool[newWidth * newHeight * newDepth];

	for (int x = 0; x < newWidth; x++)
	{
		for (int y = 0; y < newHeight; y++)
		{
			for (int z = 0; z < newDepth; z++)
			{
				bool oldState = false;
				do
				{
					int _x = x - 1;
					int _y = y - 1;
					int _z = z - 1;

					if (_x < 0 || _x >= width)
					{
						continue;
					}
					if (_y < 0 || _y >= height)
					{
						continue;
					}
					if (_z < 0 || _z >= depth)
					{
						continue;
					}

					oldState = cells[_x + _y * ydiff + _z * zdiff];
				} while (false);

				int neightbours = count[x + y * newydiff + z * newzdiff];
				bool newState = false;
				switch (oldState)
				{
				case true:
					if (neightbours == 2 || neightbours == 3)
					{
						newState = true;
					}
					else
					{
						newState = false;
					}
					break;
				case false:
					newState = neightbours == 3;
					break;
				default:
					std::cout << "Wohooo uninitedmemory :D" << std::endl;
					break;
				}
				newField[x + y * newydiff + z * newzdiff] = newState;
			}
		}
	}
	delete[] count;

	delete[] cells;
	cells = newField;
	width = newWidth;
	height = newHeight;
	depth = newDepth;

	std::cout << "cubs: " << Count() << std::endl;
}

size_t PlayfieldCubic::Count()
{
	size_t sum = 0;
	for (size_t i = 0; i < width*height*depth; i++)
	{
		if (cells[i])
		{
			sum++;
		}
	}
	return sum;
}


PlayfieldHyperCubic::~PlayfieldHyperCubic()
{
	delete cells;
}

void PlayfieldHyperCubic::Start(bool* aStart, size_t aWidth, size_t aHeight)
{
	width = aWidth;
	height = aHeight;
	depth = 1;
	hyper = 1;

	cells = aStart;
}

void PlayfieldHyperCubic::Step()
{
	struct minivec
	{
		int x;
		int y;
		int z;
		int w;
	};

	std::vector<minivec> offsets;

	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			for (int z = -1; z < 2; z++)
			{
				for (int w = -1; w < 2; w++)
				{
					if (z != 0 || y != 0 || x != 0 || w != 0)
					{
						offsets.push_back({ x,y,z,w });
					}
				}
			}
		}
	}


	size_t newWidth = width + 2;
	size_t newHeight = height + 2;
	size_t newDepth = depth + 2;
	size_t newHyper = hyper + 2;

	size_t ydiff = width;
	size_t zdiff = height * width;
	size_t wdiff = hyper * height * width;

	size_t newydiff = newWidth;
	size_t newzdiff = newWidth * newHeight;
	size_t newwdiff = newHyper * newWidth * newHeight;

	int* count = new int[newWidth * newHeight * newDepth * newHyper];


	for (int x = 0; x < newWidth; x++)
	{
		for (int y = 0; y < newHeight; y++)
		{
			for (int z = 0; z < newDepth; z++)
			{
				for (int w = 0; w < newHyper; w++)
				{
					count[x + y * newydiff + z * newzdiff + w * newwdiff] = 0;
					for (minivec& vec : offsets)
					{
						int _x = x - 1 + vec.x;
						int _y = y - 1 + vec.y;
						int _z = z - 1 + vec.z;
						int _w = w - 1 + vec.w;

						if (_x < 0 || _x >= width)
						{
							continue;
						}
						if (_y < 0 || _y >= height)
						{
							continue;
						}
						if (_z < 0 || _z >= depth)
						{
							continue;
						}
						if (_w < 0 || _w >= depth)
						{
							continue;
						}

						if (cells[_x + _y * ydiff + _z * zdiff + _w * wdiff])
						{
							count[x + y * newydiff + z * newzdiff + w * newwdiff]++;
						}
					}
				}
			}
		}
	}

	bool* newField = new bool[newWidth * newHeight * newDepth * newHyper];

	for (int x = 0; x < newWidth; x++)
	{
		for (int y = 0; y < newHeight; y++)
		{
			for (int z = 0; z < newDepth; z++)
			{
				for (int w = 0; w < newDepth; w++)
				{
					bool oldState = false;
					do
					{
						int _x = x - 1;
						int _y = y - 1;
						int _z = z - 1;
						int _w = w - 1;

						if (_x < 0 || _x >= width)
						{
							continue;
						}
						if (_y < 0 || _y >= height)
						{
							continue;
						}
						if (_z < 0 || _z >= depth)
						{
							continue;
						}
						if (_w < 0 || _w >= hyper)
						{
							continue;
						}

						oldState = cells[_x + _y * ydiff + _z * zdiff + _w * wdiff];
					} while (false);

					int neightbours = count[x + y * newydiff + z * newzdiff + w * newwdiff];
					bool newState = false;
					switch (oldState)
					{
					case true:
						if (neightbours == 2 || neightbours == 3)
						{
							newState = true;
						}
						else
						{
							newState = false;
						}
						break;
					case false:
						newState = neightbours == 3;
						break;
					default:
						std::cout << "Wohooo uninitedmemory :D" << std::endl;
						break;
					}
					newField[x + y * newydiff + z * newzdiff + w * newwdiff] = newState;
				}
			}
		}
	}
	delete[] count;

	delete[] cells;
	cells = newField;
	width = newWidth;
	height = newHeight;
	depth = newDepth;
	hyper = newHyper;

	std::cout << "cubs: " << Count() << std::endl;
}

size_t PlayfieldHyperCubic::Count()
{
	size_t sum = 0;
	for (size_t i = 0; i < width * height * depth * hyper; i++)
	{
		if (cells[i])
		{
			sum++;
		}
	}
	return sum;
}