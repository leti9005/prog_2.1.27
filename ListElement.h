/**
    Это у нас ключевой элемент однонаправленного списка.
*/

#pragma once

#include <iostream>
#include <string>

using namespace std;

struct ListElement {
    string edge, system, country;
    float height;
    ListElement* next;

    void print() {
        cout << "\nName - " << edge << "\n " 
            << "Mount system - " << system << "\n " 
            << "Country - " << country << "\n " 
            << "height - " << height << "\n"
            << endl;
    }
};
