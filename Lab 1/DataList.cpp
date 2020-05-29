#include "DataList.h"

DataList::DataList() {

	head = nullptr;
	tail = nullptr;
	mSize = 0;
}

DataList::~DataList() {

	while (head != nullptr) {
		Data* temp = head->next;
		delete head;
		head = temp;
	}
}

unsigned int DataList::getSize() {
	return mSize;
}

Data* DataList::getElement(char value[]) { // @Nullable

	Data* result = head;

	while (result != nullptr) {
		if (result->data == value) {
			break;
		}
		result = result->next;
	}

	return result;
}

void DataList::remove(char value[]) {

	Data
		* current = getElement(value),
		* previous = head;

	if (mSize == 1) {
		head = nullptr;
		tail = nullptr;

	}
	else {

		if (current == head) {
			head = current->next;

		}
		else {

			while (previous != nullptr) {

				if (previous->next == current) {
					break;
				}

				previous = previous->next;
			}

			if (current == tail) {
				tail = previous;
				tail->next = nullptr;

			}
			else {
				previous->next = current->next;
			}
		}
	}

	delete current;
	mSize--;
}

void DataList::cleanList() {

	Data* temp = nullptr;

	while (head != nullptr) {

		temp = head->next;
		remove(head->data);
		head = temp;
	}

	head = nullptr;
	tail = nullptr;
	mSize = 0;

}

///*
//	«амен€ет восклицательные знаки точками.
//*/
void DataList::replace(char c) {
	Data* temp = head;

	while (temp != nullptr) {
		for (int i = 0; i <= strlen(temp->data); i++)
		{
			if (temp->data[i] == c)
			{
				temp->data[i] = '.';
			}
		}
		temp = temp->next;
	}
}

void DataList::printList() {
	Data* temp = head;

	cout << '\n';
	while (temp != nullptr) {

		temp->print();

		temp = temp->next;
	}
	cout << flush;
}

void DataList::writeToFile(string fileName) {

	Data* temp = head;

	while (temp != nullptr) {
		buff.append(temp->data);
		buff.append("\n");
		temp = temp->next;
	}

	fsOut.open(fileName, ofstream::trunc);

	if (!fsOut.is_open()) {
		cout << constants.WARNING_BAD_FILE << endl;

	}
	else {
		fsOut << buff;
		buff.clear();
		fsOut.close();
	}
}

void DataList::readFromFile(string fileName) {

	Data* temp;

	fsIn.open(fileName);

	if (!fsIn.is_open()) {
		cout << constants.WARNING_BAD_FILE << endl;
	}
	else {

		cleanList();

		while (getline(fsIn, buff)) {

			temp = new Data();
			strcpy_s(temp->data, buff.c_str());
			buff.erase();
			pushEnd(temp);

		}

		buff.clear();
		fsIn.close();
	}
}

void DataList::pushEnd(Data* arg) {

	Data* element = new Data();
	strcpy_s(element->data, arg->data);

	if (tail != nullptr) {
		tail->next = element;
	}

	tail = element;
	tail->next = nullptr;

	head = (mSize == 0) ? tail : head;
	mSize++;
}