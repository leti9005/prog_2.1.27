
/**

=====================================================================================================================================

    Не надо вникать в этот файл и особенно в жуткий свитч!
    Это юзер-интерфейс, который касается конкретного задания, у других вариантов будет иначе.
    А ещё он сделан в спешке и без понимания чего хочет препод. Говнокод наугад.
    Что-то полезное можно найти в ListElement.h и EdgesList.h

    ========================================================================================================================

*/


/*
    Неясно, надо ли делать бэкап листа в файл, т.е. сохранять список при работе. Пока без бэкапа.
*/


#include "ListElement.h"
#include "EdgesList.h"
#include <typeinfo>


using namespace std;

void showUserInterface() {
    cout <<
        "\nSpravochnik po gornim vershinam. \n"

        "Interface: \n"

        "Input: \n"

        "Add edge - 1 \n"
        "Edit edge - 2 \n"
        "Delete edge - 3 \n"
        "Delete all - 4 \n"

        "Output:\n"

        "Print whole list - 5 \n"
        "Show particular edge data - 6 \n"
        "Show Particular mount system summary - 7 \n"
        "Show particular country summary - 8 \n"

        "Exit - 9 \n"
        << endl;
}

int main() {
    try{

        /*
            Демо-контент START =================================================
        */

        const string demoCountries[] = { 
            "DEMO_Country_0", 
            "DEMO_Country_1", 
            "DEMO_Country_2", 
            "DEMO_Country_3"
        };

        const string demoSystems[] = {
            "DEMO_System_0",
            "DEMO_System_1",
            "DEMO_System_2",
            "DEMO_System_3",
            "DEMO_System_4",
            "DEMO_System_5"
        };

        const string demoEdges[] = {
            "DEMO_Edge_0", 
            "DEMO_Edge_1", 
            "DEMO_Edge_2", 
            "DEMO_Edge_3", 
            "DEMO_Edge_4", 
            "DEMO_Edge_5", 
            "DEMO_Edge_6", 
            "DEMO_Edge_7", 
            "DEMO_Edge_8", 
            "DEMO_Edge_9"
        };

        const float demoHeights[] = {
            5555.5f, // 0
            6737.7f, // 1
            6143.2f, // 2
            2244.1f, // 3
            3313.3f, // 4
            100.6f, // 5
            7134.f, // 6
            6022.f, // 7
            253.f, // 8
            8484.f, // 9
        };

        /*
            Демо-контент END ================================================
        */

        EdgesList edges;
        int input = -1;
        string edge, system, country, temp;
        float height;
        bool flag = false;

        /*
            Наполняем список демо-контентом
        */

        edges.pushEnd(demoEdges[6], demoSystems[5], demoCountries[3], demoHeights[6]);
        edges.pushEnd(demoEdges[7], demoSystems[5], demoCountries[3], demoHeights[7]);
        edges.pushEnd(demoEdges[8], demoSystems[4], demoCountries[2], demoHeights[8]);
        edges.pushEnd(demoEdges[9], demoSystems[3], demoCountries[2], demoHeights[9]);

        edges.pushStart(demoEdges[5], demoSystems[2], demoCountries[1], demoHeights[5]);
        edges.pushStart(demoEdges[4], demoSystems[1], demoCountries[3], demoHeights[4]);
        edges.pushStart(demoEdges[3], demoSystems[1], demoCountries[1], demoHeights[3]);
        edges.pushStart(demoEdges[2], demoSystems[1], demoCountries[0], demoHeights[2]);
        edges.pushStart(demoEdges[1], demoSystems[0], demoCountries[0], demoHeights[1]);
        edges.pushStart(demoEdges[0], demoSystems[0], demoCountries[0], demoHeights[0]);

        while (input !=9) { 

            showUserInterface();           // Выводим интерфейс
            if (!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cin >> input;


            switch (input) { 

                case 1: //добавление

                    cout << "Input edge name" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, edge);
                    if (edge.empty()) {
                        cout << "Bad input" << endl;

                    }else {
                        for (int i = 0; i < edges.getSize(); i++) {
                            if (edges.getElement(i)->edge == edge) {
                                cout << "\nEdge name must be unique!\n" << endl;
                                flag = true;
                                break;
                            }
                        }

                        if (!flag) {
                            cout << "Input mount system name" << endl;
                            getline(cin, system);
                            if (system.empty()) {
                                cout << "Bad input" << endl;
                            }else {
                                cout << "Input country" << endl;
                                getline(cin, country);
                                if (country.empty()) {
                                    cout << "Bad input" << endl;
                                }else {
                                    cout << "Input height" << endl;
                                    cin >> height;

                                    if (!cin) {
                                        cout << "Bad input" << endl;
                                    }else {
                                        edges.pushEnd(edge, system, country, height);

                                        cout << "Done:" << endl;

                                        edges.printList();
                                    }
                                }
                            }
                        }
                    }

                    break;

                case 2: //редактирование

                    cout << "Input edge name" << endl;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cin >> temp;


                    if (edges.printEdge(temp)) {

                        cout << "Input new edge name" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, edge);
                        if (edge.empty()) {
                            cout << "Bad input" << endl;
                        }else {
                            for (int i = 0; i < edges.getSize(); i++) {
                                if (edges.getElement(i)->edge == edge) {
                                    cout << "\nEdge name must be unique!\n" << endl;
                                    flag = true;
                                    break;
                                }
                            }

                            if (!flag) {
                                cout << "Input new mount system name" << endl;
                                getline(cin, system);
                                if (system.empty()) {
                                    cout << "Bad input" << endl;
                                }else {
                                    cout << "Input new country" << endl;
                                    getline(cin, country);
                                    if (country.empty()) {
                                        cout << "Bad input" << endl;
                                    }else {
                                        cout << "Input new height" << endl;
                                        cin >> height;

                                        if (!cin) {
                                            cout << "Bad input" << endl;
                                        }else {
                                            edges.edit(temp, edge, system, country, height);
                                            cout << "Done:" << endl;
                                            edges.printList();
                                        }
                                    }
                                }
                            }
                        }
                    }

                    break;

                case 3: //удаление

                    cout << "Input edge name" << endl;
                    cin.ignore();
                    getline(cin, temp);

                    edges.remove(temp);
                    cout << "Done:" << endl;
                    edges.printList();

                    break;

                case 4: //удаление всех элементов (сам список жив)

                    edges.removeAll();
                    cout << "Done." << endl;
                    edges.printList();

                    break;

                case 5: //показать список

                    edges.printList();

                    break;

                case 6: //детально вершину

                    cout <<
                        "\nEdge data: \n"
                        "Input edge name:" << endl;

                    cin.ignore();
                    getline(cin, temp);
                    edges.printEdge(temp);

                    break;

                case 7: //детально систему

                    cout << "\nInput mount system name" << endl;
                    cin.ignore();
                    getline(cin, temp);
                    edges.printSystem(temp);

                    break;

                case 8: //детально страну

                    cout << "\nInput country" << endl;
                    cin.ignore();
                    getline(cin, temp);
                    edges.printCountry(temp);

                    break;

                case 9: //exit

                    cout << "Exiting programm" << endl;
                    return EXIT_SUCCESS;
                    break;

                default:

                    cout << "Bad input" << endl;
                    break;
            }
        }

        return EXIT_SUCCESS;

    } catch (const std::exception&){  

        cout << "Programm error. Something gone wrong." << endl;
        return EXIT_FAILURE;
    }
}
