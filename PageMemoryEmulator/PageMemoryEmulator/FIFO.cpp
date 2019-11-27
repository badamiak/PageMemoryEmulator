#include "StdAfx.h"
#include "FIFO.h"


FIFO::FIFO(int lastElement)
{
	this->lastElement = lastElement;
	elementToChange = 0;
}

void FIFO::next()
{
	if(elementToChange == lastElement)
		elementToChange = 0;
	else
		elementToChange++;
}

int FIFO::current()
{
	return elementToChange;
}

FIFO::~FIFO(void)
{
}
