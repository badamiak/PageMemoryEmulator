#include "StdAfx.h"
#include "Unit.h"


Unit::Unit(int datablockSize)
{
	datablock = new char[datablockSize+1];
	datablock[datablockSize] = NULL;
}

Unit::Unit()
{
}

/*void Unit::setDataBlockSize(int dataBlockSize)
{
	delete [] datablock;
	datablock = new char[dataBlockSize];
}*/

char Unit::show(int datablockPosition)
{
	return datablock[datablockPosition];
}

char Unit::show()
{
	return *datablock;
}

Unit::~Unit(void)
{
}
