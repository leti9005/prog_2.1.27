#include "DemoHelper.h"

using namespace std;

Constants constants;
const string fileName = "data.txt";
DemoHelper* helper;
EdgesList* edges;
//bool flag = false, caseStart, caseMiddle; // Кейсы для читерства со свитчем.

void showUserInterface();
bool is_file_exist(string fileName);
int main();