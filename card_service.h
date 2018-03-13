#include "model.h"

#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H


bool addCard(Card card);
Card* queryCard(const char* pName);
bool initCardList();
void releaseCardList();

class card_service
{
public:
    card_service();
};

#endif // CARD_SERVICE_H
