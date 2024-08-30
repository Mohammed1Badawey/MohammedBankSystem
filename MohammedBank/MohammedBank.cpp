#include <iostream>
#include "FileManager.h"
#include "Screens.h"

using namespace std;



int main()
{
    Admin* admin = Admin::getInstance();
    Screens::runApp();
    return 0;

}
