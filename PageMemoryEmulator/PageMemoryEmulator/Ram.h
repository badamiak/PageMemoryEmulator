#pragma once
#include "unit.h"
#include "PageFile.h"
#include <string>
using namespace std; 
class Ram
{
public:
	Unit ** memory;
	Ram(int numberOfFrames, int frameSize);
	char show(int frame, int position);
	char show(int frame);
	void load(Unit * from, int frame);
	~Ram(void);
};

