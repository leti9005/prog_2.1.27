/**
	Класс списка.
*/

#pragma once

#include <fstream>
#include <sstream>
#include "Constants.h"
#include "Data.h"

using namespace std;

class DataList
{

public:

	DataList();
	~DataList();

	unsigned int getSize();
	Data* getElement(char value[]);
	void remove(char value[]);
	void cleanList();
	void printList();
	void removeByValue(int value);
	void writeToFile(string fileName);
	void readFromFile(string fileName);

private:

	Constants constants;
	ifstream fsIn;
	ofstream fsOut;
	string buff;
	Data* head, * tail;
	size_t mSize;

	void pushEnd(Data* arg);
};