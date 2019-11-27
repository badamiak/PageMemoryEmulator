#include "StdAfx.h"
#include <array>
#include "Ram.h"

using namespace std;
Ram::Ram(int numberOfFrames, int frameSize)
{
	memory = new Unit* [numberOfFrames];
	/*page = new Unit[numberOfpages];*/
for( int i=0 ; i<numberOfFrames ; i++)
	{
		memory[i] = new Unit(frameSize);
	}
}

char Ram::show(int frame, int position)
{
	return memory[frame]->show(position);
}

char Ram::show(int frame)
{
	return *memory[frame]->datablock;
}

void Ram::load(Unit * from, int position)
{
	this->memory[position] = from;
}

Ram::~Ram(void)
{
}
