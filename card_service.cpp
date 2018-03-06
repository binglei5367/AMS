#include <iostream>
#include <string.h>
#include "card_service.h"
#include "global.h"
#include "model.h"

Card aCard[50];
int nCount = 0;

int addCard(Card card)
{
    if(nCount > 49)
    {
        printf("Overflow!\n");
        return 0;
    }
    aCard[nCount] = card;
    nCount++;
    return nCount;
}

Card* queryCard(const char* pName)
{
    for(int i = 0; i < nCount; i++)
    {
        if(strcmp(pName, aCard[i].aName) == 0)
            return &aCard[i];
    }
    return NULL;
}

card_service::card_service()
{

}
