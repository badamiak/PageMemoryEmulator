#include "StdAfx.h"
#include "PageFile.h"

using namespace std;
PageFile::PageFile(int numberOfpages, int frameSize)
{
	page = new Unit* [numberOfpages];
	/*page = new Unit[numberOfpages];*/
for( int i=0 ; i<numberOfpages ; i++)
	{
		page[i] = new Unit(frameSize);
	}
}

char PageFile::show(int frame)
{
	return *page[frame]->datablock;
	//TODO: sprawdzic czy aby napewno jest ladowany znak konca linii
}


Unit PageFile::moveToRam(int frame)
{
	return *page[frame];
}

PageFile::~PageFile(void)
{
}
