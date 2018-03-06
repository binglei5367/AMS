#ifndef MENU_H
#define MENU_H

int outputMenu();
void add();
void query();
int getSize(const char* pInput);
void copyInfo(const char aInput[], char aOutput[], int nSize);

class menu
{
public:
    menu();
};

#endif // MENU_H
