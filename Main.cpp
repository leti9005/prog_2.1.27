#pragma once

#include "Main.h"

void showUserInterface() {
    cout << constants.USER_INTERFACE << endl;
}

bool is_file_exist(string fileName){
    ifstream infile(fileName);
    return infile.good();
}

int main() {

    int input = -1;
    double height;
    string 
        edge, 
        system, 
        country, 
        temp;

    helper = new DemoHelper();
    edges = new EdgesList();

    if (!is_file_exist(fileName)){
        edges = helper->addDemoStuff(edges);
        edges->writeToFile(fileName);
    }else {
        edges->readFromFile(fileName);
    }

    while (input !=1991) { 
        //caseStart = false, caseMiddle = false; // Обнуляем флаги для свитча внизу.
        showUserInterface();           // Выводим интерфейс.

        if (!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin >> input;

        switch (input) { 

        case 1: //вершины по алфавиту

            edges->sort(fileName, 1, true);
            edges->printList();

            break;

        case 2: //вершины в обратном алфавитном

            edges->sort(fileName, 1, false);
            edges->printList();

            break;

        case 3: //страны по алфавиту

            edges->sort(fileName, 2, true);
            edges->printList();

            break;

        case 4: //страны в обратном алфавитном

            edges->sort(fileName, 2, false);
            edges->printList();

            break;

        case 5: //по возрастанию высоты

            edges->sort(fileName, 3, true);
            edges->printList();

            break;

        case 6: //по убыванию высоты

            edges->sort(fileName, 3, false);
            edges->printList();

            break;

        case 7: //обратить текущую последовательность

            edges->reverse();
            edges->printList();

            break;

        case 8: //сводка по стране

            cout << constants.INPUT_COUNTRY << endl;
            cin.ignore();
            getline(cin, temp);
            edges->printCountry(temp);

            break;

        case 9: //exit

            cout << constants.EXITING << endl;
            delete edges;
            delete helper;
            return EXIT_SUCCESS;
            break;
                    
        default:
            cout << constants.WARNING_NO_RESULT << endl;
            break;
        }
    }

    delete edges;
    delete helper;
    return EXIT_SUCCESS;
}