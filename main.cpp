#include <iostream>
#include "menu.h"

using namespace std;
int main()
{
    cout << "欢迎进入计费管理系统" << endl;
    int nSelection = 0;
    do{
        nSelection = outputMenu();
    }while(nSelection != 0);

    return 0;
}
