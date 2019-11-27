#pragma once
class FIFO
{
public:
	FIFO(int lastElement);
	int elementToChange;
	int lastElement;
	void next();
	int current();

	~FIFO(void);
};

