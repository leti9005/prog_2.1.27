/**
	Класс списка.
*/

#pragma once

#include <fstream>
#include <sstream>
#include "Constants.h"
#include "Edge.h"

using namespace std;

class EdgesList
{

public:

	EdgesList();
	~EdgesList();

	unsigned int getSize();
	Edge* getElement(string temp);
	Edge* getElement(size_t index);
	void pushStart(string edgeName, string system, string country, double height);
	//void pushMiddle(string edgeName, string system, string country, double height);
	void pushEnd(string edgeName, string system, string country, double height);
	//void edit(string temp, string edgeName, string system, string country, double height);
	void remove(string edge);
	void cleanList(bool cleanFile, string fileName);
	//bool printEdge(string edgeName);
	void sort(string fileName, size_t mode, bool ascending);
	void definePosition(Edge* elementArg, size_t mode);
	void reverse();
	void printCountry(string country);
	void printList();
	bool writeToFile(string fileName);
	bool readFromFile(string fileName);

private:

	string delimiter = "(<=@@=>)";

	Constants constants;
	ifstream fileIn;
	ofstream fileOut;
	string inOutBuff; // Будем считать это разновидностью буфера.
	Edge* head, * tail;
	size_t mSize;

	void pushEndInner(Edge* elementArg);
};