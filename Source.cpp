
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
#include "DemoHelper.h"
#include "Constants.h"
#include <typeinfo>


using namespace std;

Constants constants;

void showUserInterface() {
    cout << constants.USER_INTERFACE << endl;
}

int main() {
    try{
        DemoHelper *helper = new DemoHelper();
        EdgesList* edges = new EdgesList();

        edges = helper->addDemoStuff(edges);

        int input = -1;
        string edge, system, country, temp;
        float height;
        bool flag = false;

        while (input !=9) { 

            showUserInterface();           // Выводим интерфейс
            if (!cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cin >> input;


            switch (input) { 

                case 1: //добавление

                    cout << constants.INPUT_EDGE << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, edge);
                    if (edge.empty()) {
                        cout << constants.WARNING_BAD_INPUT << endl;

                    }else {
                        for (int i = 0; i < edges->getSize(); i++) {
                            if (edges->getElement(i)->edge == edge) {
                                cout << constants.WARNING_NOT_UNIQUE << endl;
                                flag = true;
                                break;
                            }
                        }

                        if (!flag) {
                            cout << constants.INPUT_SYSTEM << endl;
                            getline(cin, system);
                            if (system.empty()) {
                                cout << constants.WARNING_BAD_INPUT << endl;
                            }else {
                                cout << constants.INPUT_COUNTRY << endl;
                                getline(cin, country);
                                if (country.empty()) {
                                    cout << constants.WARNING_BAD_INPUT << endl;
                                }else {
                                    cout << constants.INPUT_HEIGHT << endl;
                                    cin >> height;

                                    if (!cin) {
                                        cout << constants.WARNING_BAD_INPUT << endl;
                                    }else {
                                        edges->pushEnd(edge, system, country, height);

                                        cout << constants.DONE << endl;

                                        edges->printList();
                                    }
                                }
                            }
                        }
                    }

                    break;

                case 2: //редактирование

                    cout << constants.INPUT_EDGE << endl;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cin >> temp;


                    if (edges->printEdge(temp)) {

                        cout << constants.INPUT_NEW_EDGE << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, edge);
                        if (edge.empty()) {
                            cout << constants.WARNING_BAD_INPUT << endl;
                        }else {
                            for (int i = 0; i < edges->getSize(); i++) {
                                if (edges->getElement(i)->edge == edge) {
                                    cout << constants.WARNING_NOT_UNIQUE << endl;
                                    flag = true;
                                    break;
                                }
                            }

                            if (!flag) {
                                cout << constants.INPUT_NEW_SYSTEM << endl;
                                getline(cin, system);
                                if (system.empty()) {
                                    cout << constants.WARNING_BAD_INPUT << endl;
                                }else {
                                    cout << constants.INPUT_NEW_COUNTRY << endl;
                                    getline(cin, country);
                                    if (country.empty()) {
                                        cout << constants.WARNING_BAD_INPUT << endl;
                                    }else {
                                        cout << constants.INPUT_NEW_HEIGHT << endl;
                                        cin >> height;

                                        if (!cin) {
                                            cout << constants.WARNING_BAD_INPUT << endl;
                                        }else {
                                            edges->edit(temp, edge, system, country, height);
                                            cout << constants.DONE << endl;
                                            edges->printList();
                                        }
                                    }
                                }
                            }
                        }
                    }

                    break;

                case 3: //удаление

                    cout << constants.INPUT_EDGE << endl;
                    cin.ignore();
                    getline(cin, temp);

                    edges->remove(temp);
                    cout << constants.DONE << endl;
                    edges->printList();

                    break;

                case 4: //удаление всех элементов (сам список жив)

                    edges->removeAll();
                    cout << constants.DONE << endl;
                    edges->printList();

                    break;

                case 5: //показать список

                    edges->printList();

                    break;

                case 6: //детально вершину

                    cout <<
                        "\nEdge data: \n" <<
                        constants.INPUT_EDGE << endl;

                    cin.ignore();
                    getline(cin, temp);
                    edges->printEdge(temp);

                    break;

                case 7: //детально систему

                    cout << constants.INPUT_SYSTEM << endl;
                    cin.ignore();
                    getline(cin, temp);
                    edges->printSystem(temp);

                    break;

                case 8: //детально страну

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

    } catch (const std::exception&){  

        cout << constants.ERROR_GENERAL << endl;

        return EXIT_FAILURE;
    }
}
