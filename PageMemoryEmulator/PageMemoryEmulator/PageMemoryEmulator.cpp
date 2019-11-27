// PageMemoryEmulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Manager.h"
#include <stdio.h>
#include <iostream>

using namespace std;
int fsize(char * file)
{
	FILE * f;
	f = fopen(file, "rt");
	fpos_t temp;
	fseek(f,0,SEEK_END);
	fgetpos(f,&temp);
	fclose(f);
	return (int)temp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int logicAddres,frames,allocUnitSize;
	int fileSize = fsize("dane.txt");
	

	cout << "Rozmiar pliku: " << fileSize;
	cout << endl << "podaj ilosc ramek pamieci RAM: ";cin >> frames;
	cout << endl << "podaj rozmiar jednostki alokacji: "; cin >> allocUnitSize;
	
	
	FILE * f;
	f = fopen("dane.txt","rb");
	Manager main(fileSize,frames,allocUnitSize);
	main.load(f); /*Wczytywanie danych do stron*/
	fclose(f);

	main.writeStatus();
	for(;;)
	{
	cout << endl << "Wywolaj adres : ";
	cin >> logicAddres;
	if(logicAddres>fileSize)
		{
			cout << endl << "Adres nie istnieje" << endl;
		}
		else
		{
			main.call(logicAddres);
			main.writeStatus();
		}
	
	}
	system("pause");
	return 0;
}

