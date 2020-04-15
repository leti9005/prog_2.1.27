/**
    Тут храним константы. Вобще это не совсем константы, должны же быть статичные. Потом допилю.
*/


#pragma once

#include <string>
using namespace std;

struct Constants
{

    const string USER_INTERFACE = 

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

        "Exit - 9 \n";

    const string INPUT_EDGE = "\nInput edge name:";
    const string INPUT_SYSTEM = "\nInput mount system name:";
    const string INPUT_COUNTRY = "\nInput country:";
    const string INPUT_HEIGHT = "\nInput height:";
    const string INPUT_NEW_EDGE = "\nInput new edge name:";
    const string INPUT_NEW_SYSTEM = "\nInput new mount system name:";
    const string INPUT_NEW_COUNTRY = "\nInput new country:";
    const string INPUT_NEW_HEIGHT = "\nInput new height:";

    const string DONE = "\nDone\n";
    const string EXITING = "\nExiting programm\n";

    const string WARNING_NOT_UNIQUE = "\nEdge name must be unique!\n";
    const string WARNING_BAD_INPUT = "\nBad input\n";
    const string WARNING_NO_ELEMENT = "\nNo such element \n";
    const string WARNING_EMPTY_LIST = "\nList is empty \n";
    const string WARNING_NO_RESULT = "\nNo result for this input \n";

    const string ERROR_OUTOFBOUNDS = "\nERROR: Index out of bounds \n";
    const string ERROR_CODE = "\nCODE ERROR\n";
    const string ERROR_GENERAL = "\nERROR. Something wrong.\n";

};

