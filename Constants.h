#pragma once

#include <string>

using namespace std;

struct Constants
{

    const string USER_INTERFACE =

        "\n<==================================================> \n\n"

        "Vivod vershin po alfavitu - 1 \n"
        "Vivod vershin protiv alfavita - 2 \n\n"

        "Vivod stran po alfavitu - 3 \n"
        "Vivod stran protiv alfavita - 4 \n\n"

        "Vivod vershin po vozrastaniju visoti - 5 \n"
        "Vivod vershin po ubivaniju visoti - 6 \n\n"

        "Vivod v sortirovke obratnoy k tekushej - 7 \n\n"
        //"Vivod iz faila bez sortirovki (data.txt) - 8 \n\n"

        //"Dobavit' element v nachalo (bez sortirovki) - 9 \n"
        //"Dobavit' element v seredinu (bez sortirovki) - 10 \n"
        //"Dobavit' element v konec (bez sortirovki) - 11 \n\n"

        "Svodka po strane - 8 \n\n"

        //"Redaktirovat' element - 13 \n"
        //"Udalit' element - 14 \n"
        //"Ochistit' spisok - 15 \n\n"

        "Vihod - 9 \n";

    const string INPUT_EDGE = "\nVvedite vershinu:";
    const string INPUT_SYSTEM = "\nVvedite gornuyu sistemu:";
    const string INPUT_COUNTRY = "\nVvedite stranu:";
    const string INPUT_HEIGHT = "\nVvedite znachenie visoti:";
    const string INPUT_NEW_EDGE = "\nVvedite novoe nazvanie vershini:";
    const string INPUT_NEW_SYSTEM = "\nVvedite novoe nazvanie sistemi:";
    const string INPUT_NEW_COUNTRY = "\nVvedite novuyu stranu:";
    const string INPUT_NEW_HEIGHT = "\nVvedite novoe znachenie visoti:";

    const string DONE = "\nGotovo.\n";
    const string EXITING = "\nKonets programmi\n";

    const string WARNING_NOT_UNIQUE = "\nNazvanie vershin ne dolgno povtoryatsya!\n";
    const string WARNING_BAD_INPUT = "\nNepravilnij vvod\n";
    const string WARNING_NO_ELEMENT = "\nTakoy element otsutstvuet \n";
    const string WARNING_NO_RESULT = "\nTakoy vvod ne obrabativaetsja \n";
    const string WARNING_BAD_FILE = "\nNe udalos' otkrit' fail. Propusk vseh operacij s failom \n";

    const string ERROR_CODE = "\nOSHIBKA KODA\n";
    const string ERROR_GENERAL = "\nNEOPREDELENNYA OSHIBKA.\n";

};

