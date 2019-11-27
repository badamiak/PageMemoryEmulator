#pragma once
#include "PageFile.h"
#include "Ram.h"
#include "FIFO.h"
#include <iostream>
#include <stdio.h>

class Manager
{
public:
	int errorCounter,frames,pages,allocUnitSize,lastAddresCalled,lastFrameModified;
	struct record
	{
		int page, memory; //page strona, memory komórka pamiêci w której znajduje siê dana strona
		bool pagefault;  
	}; 

	record * pageList;
	record * ramList;
	Ram * r;
	PageFile * pf;
	
	FIFO * fifo;
	Manager(int fileSize, int frames, int allocUnitSize);
	void call(int logicAddres);
	void load(FILE * f);
	void writeStatus();
	~Manager(void);
};

