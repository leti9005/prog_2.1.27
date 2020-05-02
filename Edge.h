#pragma once

#include <iostream>

using namespace std;

struct Edge {

    string 
        edge, 
        system, 
        country;
    double height;
    Edge* next;

    void print();
};
