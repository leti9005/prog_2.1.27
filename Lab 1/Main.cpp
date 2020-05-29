#pragma once

#include "Main.h"

int main() {

    list = new DataList();

    cout << constants.Maket1;

    list->readFromFile(fileName);
    cout << constants.Maket2;
    list->printList();

    list->replace('!');

    cout << constants.Maket3;
    list->printList();

    list->writeToFile(fileName);

    cout << flush;

    delete list; // удаляем уже пустой список

    return EXIT_SUCCESS;
}