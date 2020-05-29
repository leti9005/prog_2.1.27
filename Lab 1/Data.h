#pragma once

#include <iostream>

using namespace std;

struct Data {

    char data[256];
    Data* next;

    void print();
};