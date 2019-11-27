#pragma once
class Unit
{
public:
	char * datablock;
	Unit();
	//void setDataBlockSize(int dataBlockSize);
	Unit(int datablockSize);
	char show(int datablockPosition);
	char show();
	~Unit(void);
};

