#pragma once
#include "Unit.h"
#include <string>
using namespace std;
class PageFile
{
public:
	Unit ** page;
	PageFile(int numberOfPages, int frameSize);
	char show(int frame);
	Unit moveToRam(int frame);
	~PageFile(void);
};

