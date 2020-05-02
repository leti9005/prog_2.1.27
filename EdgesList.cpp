#include "EdgesList.h"

	EdgesList::EdgesList() {

		head = nullptr;
		tail = nullptr;
		mSize = 0;
	}

	EdgesList::~EdgesList() {

		while (head != nullptr) {
			Edge* temp = head->next;
			delete head;
			head = temp;
		}
	}

	unsigned int EdgesList::getSize() {
		return mSize;
	}

	Edge* EdgesList::getElement(string temp) { // @Nullable

		Edge* result = head;

		while (result != nullptr) {
			if (result->edge == temp) {
				break;
			}
			result = result->next;
		}

		return result;
	}

	Edge* EdgesList::getElement(size_t index) { // @NonNull

		Edge* result = nullptr;

		result = head;

		for (size_t i = 0; i < index; i++) {
			if (result != nullptr) {
				result = result->next;
			}
		}

		if (result == nullptr) {
			cout << constants.ERROR_CODE << endl;
			exit(EXIT_FAILURE);

		}else {
			return result;
		}
	}

	void EdgesList::pushStart(string edgeName, string system, string country, double height) {

		Edge* edge = new Edge();

		edge->edge = edgeName;
		edge->system = system;
		edge->country = country;
		edge->height = height;

		edge->next = head;
		head = edge;

		tail = (mSize == 0) ? tail = head : tail;

		mSize++;
	}

	void EdgesList::pushEnd(string edgeName, string system, string country, double height) {

		Edge edge;

		edge.edge = edgeName;
		edge.system = system;
		edge.country = country;
		edge.height = height;

		pushEndInner(&edge);
	}

	void EdgesList::remove(string edge) {

		Edge
			* current = getElement(edge), 
			* previous = head;

		if (current == nullptr) {
			cout << constants.WARNING_NO_ELEMENT << endl;
		}else {

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
	}

	void EdgesList::cleanList(bool cleanFile, string fileName) {

		Edge* temp = nullptr;

		while (head != nullptr) {

			temp = head->next;
			remove(head->edge);
			head = temp;
		}

		head = nullptr;
		tail = nullptr;
		mSize = 0;

		if (cleanFile) {
			writeToFile(fileName);
		}
	}

	/*
		На самом деле, сортировка в definePosition, это надстройка.
	*/
	void EdgesList::sort(string fileName, size_t mode, bool ascending) {

		double height;
		Edge edge;
		size_t pos, counter;
		string token;

		fileIn.open(fileName);

		if (!fileIn.is_open()) {
			cout << constants.WARNING_BAD_FILE << endl;
		}else {
			cleanList(false, "");

			while (getline(fileIn, inOutBuff)) {

				pos = 0, counter = 0;

				while ((pos = inOutBuff.find(delimiter)) != string::npos) {

					token = inOutBuff.substr(0, pos);
					counter++;

					switch (counter) {

					case 1:
						edge.edge = token;
						break;

					case 2:
						edge.system = token;
						break;

					case 3:
						edge.country = token;
						break;

					case 4:
						height = ::atof(token.c_str());
						edge.height = height;
						break;

					default:
						cout << constants.ERROR_GENERAL << endl;
						exit(EXIT_FAILURE);
						break;
					}

					inOutBuff.erase(0, pos + delimiter.length());
				}
				definePosition(&edge, mode);
			}

			fileIn.close();
			inOutBuff.clear();

			if (!ascending) {
				reverse();
			}
		}
	}

	void EdgesList::definePosition(Edge* elementArg, size_t mode) {

		Edge
			* temp = head,
			* last = nullptr,
			* edge = new Edge();

		edge->edge = elementArg->edge;
		edge->system = elementArg->system;
		edge->country = elementArg->country;
		edge->height = elementArg->height;

		bool
			isSet = false,
			condition1,
			condition2,
			condition3;

		while (temp != nullptr) {

			// По вершине, по стране, по высоте.
			condition1 = (mode == 1) && (edge->edge.compare(temp->edge) >= 0);
			condition2 = (mode == 2) && (edge->country.compare(temp->country) >= 0);
			condition3 = (mode == 3) && (edge->height >= temp->height);

			if (condition1 || condition2 || condition3) {

				if (last != nullptr) {
					last->next = temp;
				}

				edge->next = temp->next;
				temp->next = edge;

				if (tail == temp) {
					tail = edge;
				}

				last = temp;
				temp = edge->next;
				isSet = true;

			}else {
				last = temp;
				temp = temp->next;
			}
		}

		if (!isSet) {
			edge->next = head;
			head = edge;
			tail = (mSize == 0) ? edge : tail;
		}

		mSize++;
	}

	void EdgesList::reverse() {

		Edge
			* tempHead = head,
			* tempTail = tail,
			* current = head,
			* temp1 = nullptr,
			* temp2 = head;

		if (mSize > 1) {

			if (mSize == 2) {
				tail->next = head;

			}else {

				temp2 = current;
				temp1 = current->next;
				current = current->next->next;
				temp1->next = temp2;

				while (current != nullptr) {

					temp2 = current;
					current = current->next;
					temp2->next = temp1;
					temp1 = temp2;

				}
			}

			head = tempTail;
			tail = tempHead;
			tail->next = nullptr;
		}
	}

	void EdgesList::printCountry(string country) {
		Edge* edge = head;
		EdgesList 
			edges, 
			systems;
		size_t 
			countEdges = 0, 
			countSystems = 0;
		double sum = 0.0;

		while (edge != nullptr) {

			if (edge->country == country) {
				countEdges++;
				countSystems++;
				sum += edge->height;
				bool unigue = true;

				edges.pushEndInner(edge);

				for (size_t i = 0; i < systems.getSize(); i++) {

					if (edge->system == systems.getElement(i)->system) {
						unigue = false;
					}
				}

				if (unigue) {
					systems.pushEndInner(edge);
				}
			}

			edge = edge->next;
		}

		if (countEdges == 0) {
			cout << constants.WARNING_NO_ELEMENT << endl;
		}else {
			cout << '\n' 
				<< country << " imeet "
				<< countEdges << " gornih vershin:\n\n";

			for (size_t i = 0; i < edges.getSize(); i++) {
				cout << edges.getElement(i)->edge << '\n';
			}

			cout << "\ni " << countSystems << " gornih sistem:\n\n";

			for (size_t i = 0; i < systems.getSize(); i++) {
				cout << systems.getElement(i)->system << '\n';
			}

			cout << "\nSummarnaya visota " << sum << '\n';

			cout << '\n';
		}

		cout << flush;
	}

	void EdgesList::printList() {
		Edge* edge = head;

		cout << '\n';
		while (edge != nullptr) {

			edge->print();

			edge = edge->next;
		}
		cout << flush;
	}

	bool EdgesList::writeToFile(string fileName) {
		bool result = true;
		Edge* edge = head;

		while (edge != nullptr) {
			inOutBuff.append(edge->edge);
			inOutBuff.append(delimiter);
			inOutBuff.append(edge->system);
			inOutBuff.append(delimiter);
			inOutBuff.append(edge->country);
			inOutBuff.append(delimiter);
			ostringstream ss;
			ss << edge->height;
			string s(ss.str());
			inOutBuff.append(s);
			inOutBuff.append(delimiter);
			inOutBuff.append("\n");
			edge = edge->next;
		}

		fileOut.open(fileName, ofstream::trunc);

		if (!fileOut.is_open()) {
			cout << constants.WARNING_BAD_FILE << endl;
			result = false;
		}
		else {
			fileOut << inOutBuff;
			fileOut.close();
			inOutBuff.clear();
		}

		return result;
	}
	
	bool EdgesList::readFromFile(string fileName) {

		bool result = true;
		double height;
		Edge* edge;
		size_t 
			pos, 
			counter;
		string token;

		fileIn.open(fileName);

		if (!fileIn.is_open()) {
			cout << constants.WARNING_BAD_FILE << endl;
			result = false;
		}
		else {
			cleanList(false, "");

			while (getline(fileIn, inOutBuff)) {

				pos = 0, counter = 0;
				edge = new Edge();

				while ((pos = inOutBuff.find(delimiter)) != string::npos) {

					token = inOutBuff.substr(0, pos);
					counter++;

					switch (counter) {

					case 1:
						edge->edge = token;
						break;

					case 2:
						edge->system = token;
						break;

					case 3:
						edge->country = token;
						break;

					case 4:
						height = ::atof(token.c_str());
						edge->height = height;
						break;

					default:
						cout << constants.ERROR_GENERAL << endl;
						exit(EXIT_FAILURE);
						break;
					}

					inOutBuff.erase(0, pos + delimiter.length());
				}
				pushEndInner(edge);
			}

			fileIn.close();
			inOutBuff.clear();
		}

		return result;
	}

	void EdgesList::pushEndInner(Edge* elementArg) {

		Edge* edge = new Edge();
		edge->edge = elementArg->edge;
		edge->system = elementArg->system;
		edge->country = elementArg->country;
		edge->height = elementArg->height;

		if (tail != nullptr) {
			tail->next = edge;
		}

		tail = edge;
		tail->next = nullptr; // Надо?

		head = (mSize == 0) ? tail : head;
		mSize++;
	}
