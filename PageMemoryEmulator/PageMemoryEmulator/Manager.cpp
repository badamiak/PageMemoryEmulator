#include "StdAfx.h"
#include "Manager.h"


using namespace std;
Manager::Manager(int fileSize, int frames, int allocUnitSize)
{
	this->frames = frames;
	this->pages = (fileSize/allocUnitSize)+1;
	this->allocUnitSize = allocUnitSize;
	pageList = new record[pages]; //po stronach
	ramList = new record[frames]; //po ramkach

	/*hardcoded test*/
	for(int i=0; i< pages; i++)
	{
		pageList[i].memory=0;
		pageList[i].page=0;
		pageList[i].pagefault = true;
	}
	for(int i=0; i< frames; i++)
	{
		ramList[i].memory=0;
		ramList[i].page=0;
		ramList[i].pagefault = true;
	}


	r = new Ram(frames,allocUnitSize);
	pf = new PageFile(pages,allocUnitSize);
	fifo = new FIFO(frames-1);
	lastFrameModified = NULL;
	lastAddresCalled = NULL;
	errorCounter = NULL;
}

void Manager::call(int logicAddres)
{
	if(!pageList[logicAddres/allocUnitSize].pagefault) //logicAddres/pages jako wynik podaje stroê w której znajduje siê adres logiczny 
	{
		lastAddresCalled=logicAddres;
		lastFrameModified=logicAddres/allocUnitSize;
	}
	else
	{
		errorCounter++;

		
		pageList[ramList[fifo->current()].page].pagefault=1; //ustawienie flagi PF na stronie do usuniêcia
		r->load(pf->page[logicAddres/allocUnitSize],fifo->current()); //³adowanie nowej strony do pamiêci
	
		pageList[logicAddres/allocUnitSize].pagefault=false; //ustawienie flagi PF w przeniesionej stronie
		pageList[logicAddres/allocUnitSize].memory=fifo->current();
	
		ramList[fifo->current()].page=logicAddres/allocUnitSize;

		lastAddresCalled=logicAddres;
		lastFrameModified=logicAddres/allocUnitSize;
		fifo->next();
		

	}
}

void Manager::load(FILE * f)
{
	for(int i=0; i < pages ; i++)
	{
		fread(pf->page[i]->datablock,sizeof(char),allocUnitSize,f);
	}
}

/*<dzia³a i nie pytaæ jak>*/
void Manager::writeStatus()
{
	cout << endl << "-------------------------------------"
		 << endl << "-------------------------------------"
		 << endl << "PAGEFILE:";
  for(int i=0; i<pages ; i++)
  {
	  //TODO: poprawic wyswietlanie
	  cout << endl << "page "; if(i<10) cout << "0"; cout << i << " :" << pf->page[i]->datablock;
  }

	cout << endl << "-------------------------------------"
		 << endl << "RAM:";
  for(int i=0; i<frames ; i++)
  {
	  cout << endl << "frame "; if(i<10) cout << "0"; cout << i << " " << r->memory[i]->datablock;
  }
	cout << endl << "-------------------------------------"
		 << endl << "PageFaults: " << errorCounter
		 << endl << "Last addres used: " << lastAddresCalled << " Data Frame: " << pf->page[lastFrameModified]->datablock /*r->memory[lastAddresCalled]->datablock*/
		 << endl << "-------------------------------------"
		 << endl << "-------------------------------------" 
		 << endl;
	;
}
/*<\dzia³a i nie pytaæjak>*/

Manager::~Manager(void)
{
}
