/**
	Класс списка, оперирующий структурой ListElement. 
	Не считая реализации базовых элементов списка, это плохой паттерн, т.к. God Object, но для курсача сойдёт.
*/

#pragma once

#include "ListElement.h"
#include <iostream>

using namespace std;

class EdgesList
{

public:

	EdgesList() {
		head = nullptr;
		tail = nullptr;
		mSize = 0;
	}

	~EdgesList() {
		while (head != nullptr){
			ListElement* temp = head->next;
			delete head;
			head = temp;
		}
		////delete tail;// И так нульпоинтер, не надо.
	}

	ListElement* getElement(string temp, int mode) { // Может вернуть nullptr, т.к. переваривает инпут юзера.
		ListElement* result = head;

		switch (mode) {

		case 1:

			while (result != nullptr) {
				if (result->edge == temp) {
					break;
				}
				result = result->next;
			}
			break;

		case 2:

			while (result != nullptr) {
				if (result->system == temp) {
					break;
				}
				result = result->next;
			}
			break;

		case 3:

			while (result != nullptr) {
				if (result->country == temp) {
					break;
				}
				result = result->next;
			}
			break;

		default:
			cout << "\n CODE ERROR \n" << endl;
			throw std::exception();
		}

		return result;
	}

	ListElement* getElement(unsigned int index) {  // @NonNull. Не может вернуть nullptr, можно закинуть в private.

		ListElement* result = nullptr;

		if (mSize == 0) {

			cout << "\n List is empty \n" << endl;
			throw std::exception();

		}else if (index > mSize - 1) {

			cout << "\n Error: Index out of bounds. \n" << endl;
			throw std::exception();

		}else {

			result = head;

			for (unsigned int i = 0; i < index; i++) {
				if (result != nullptr) {
					result = result->next;
				}
			}
		}

		if (result == nullptr) {

			cout << "\n CODE ERROR \n" << endl;
			throw std::exception();

		}else {
			return result;
		}
	}

	void pushStart(string edge, string system, string country, float height) { // Добавление в начало, ну тут всё просто.

		ListElement* elementObject = new ListElement();
		elementObject->edge = edge;
		elementObject->system = system;
		elementObject->country = country;
		elementObject->height = height;

		elementObject->next = head;
		head = elementObject;

		if (mSize == 0) {
			tail = head;
		}

		mSize++;
	}

	void pushEnd(string edge, string system, string country, float height) { // Добавление в конец, функция-надстройка

		ListElement* tempObject = new ListElement();
		tempObject->edge = edge;
		tempObject->system = system;
		tempObject->country = country;
		tempObject->height = height;

		pushEnd(tempObject);

		delete tempObject;		// Он создавался что бы просто стать аргументом в функцию,
									//где создаётся свой элемент, так что просто удаляем. Наверняка можно проще, не вникал.
	}

	void pushEnd(ListElement* elementArg) { // Добавление в конец, базовая функция, можно перемещать в private

		ListElement* elementObject = new ListElement();
		elementObject->edge = elementArg->edge;
		elementObject->system = elementArg->system;
		elementObject->country = elementArg->country;
		elementObject->height = elementArg->height;

		if (tail != nullptr) {
			tail->next = elementObject;
		}

		tail = elementObject;

		tail->next = nullptr;

		if (mSize == 0) {
			head = tail;
		}

		mSize++;
	}



	void edit(string temp, string edge, string system, string country, float height) { // Редактироание

		ListElement* element = getElement(temp, 1);

		if (element == nullptr) {
			cout << "\n No such edge \n" << endl;
		}else {
			element->edge = edge;
			element->system = system;
			element->country = country;
			element->height = height;
		}

	}

	void remove(string edge) { // Удаление

		ListElement* current = getElement(edge, 1);
		ListElement* previous = head;

		if (mSize == 1) {
			head = nullptr;
			tail = nullptr;
		}else {
			if (current == head) {

				head = current->next;

			}else {

				while (previous != nullptr) {
					if (previous->next == current) {
						break;
					}
					previous = previous->next;
				}

				if (previous == nullptr) {
					cout << "\n CODE ERROR \n" << endl;
					throw std::exception();
				}

				if (current == tail) {

					tail = previous;
					tail->next = nullptr;

				}else {
					previous->next = current->next;
				}
			}
		}

		delete current;
		mSize--;
	}

	void removeAll() {
		ListElement* temp = nullptr;
		while (head != nullptr) {
			temp = head->next;
			remove(head->edge);
			head = temp;
		}
		tail = nullptr; // Вроде не надо, но на всякий случай.
	}

	bool printEdge(string edge) { // Вывод по объекту

		bool result = false;
		ListElement* element = getElement(edge, 1);

		if (element == nullptr) {
			cout << "\n No such edge \n" << endl;
		}else {
			//printElement(element);
			element->print();
			result = true;
		}

		return result;

	}

	void printSystem(string system) {

		ListElement* element = head;
		EdgesList edges, countries; // Небольшая рекурсия, почему бы и нет.
		unsigned int countEdges = 0, countCountries = 0;

		while (element != nullptr) {
			if (element->system == system) {
				countEdges++;
				countCountries++;
				edges.pushEnd(element);
				bool unigue = true;

				for (unsigned int i = 0; i < countries.getSize(); i++) {
				
					if (element->country == countries.getElement(i)->country) {
						unigue = false;
					}
				}

				if (unigue) {
					countries.pushEnd(element);
				}
			}

			element = element->next;
		}

		if (countEdges == 0) {
			cout << "\n No such element \n" << endl;
		}else {

			cout << system
				<< " has " << countEdges
				<< " edges\n";

			for (unsigned int i = 0; i < edges.getSize(); i++) {
				cout << edges.getElement(i)->edge << "\n";
			}

			cout << "And situated in " << countCountries
				<< " countries:\n";

			for (unsigned int i = 0; i < countries.getSize(); i++) {
				cout << countries.getElement(i)->country << "\n";
			}

			cout << endl;
		}
	}

	void printCountry(string country) { // Суммарный вывод по стране
		ListElement* element = head;
		EdgesList edges, systems; // Ещё немного рекурсии
		unsigned int countEdges = 0, countSystems = 0;

		while (element != nullptr) {
			if (element->country == country) {
				countEdges++;
				countSystems++;
				edges.pushEnd(element);
				bool unigue = true;

				for (unsigned int i = 0; i < systems.getSize(); i++) {
					if (element->system == systems.getElement(i)->system) {
						unigue = false;
					}
				}

				if (unigue) {
					systems.pushEnd(element);
				}

			}

			element = element->next;
		}

		if (countEdges == 0) {
			cout << "\n No such element \n" << endl;
		}else {

			cout << country
				<< " has " << countEdges
				<< " edges\n";

			for (unsigned int i = 0; i < edges.getSize(); i++) {
				cout << edges.getElement(i)->edge << "\n";
			}

			cout << "And " << countSystems
				<< " mount systems:\n";

			for (unsigned int i = 0; i < systems.getSize(); i++) {
				cout << systems.getElement(i)->system << "\n";
			}
			cout << endl;
		}
	}

	void printList() { // Вывод всего листа
		cout << '\n';

		ListElement* element = head; 

		while (element != nullptr){
			cout << element->edge << ", " 
				<< element->system << ", " 
				<< element->country << ", " 
				<< element->height << '\n';
			element = element->next;
		}

		cout << '\n' << endl;
	}

	unsigned int getSize() { // геттер
		return mSize;
	}

private:
	/*
		Сюда так же можно закинуть пару функций из public (пометил). Но пострадает читаемость кода, т.к. программа маленькая.
	*/
	ListElement* head, * tail; // Адреса начала и конца списка - это у нас ключевые элементы списка
	unsigned int mSize; // Кол-во элементов в списке, ну так просто для удобства в петлях

};
