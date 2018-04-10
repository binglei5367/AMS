#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H

#include "model.h"

bool addCard(Card card);
Card* queryCard(const char* pName, int *pIndex);
void initCardList();
void releaseCardList();
bool getCard();

class card_service
{
public:
    card_service();
};

#endif // CARD_SERVICE_H
