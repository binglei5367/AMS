#include "model.h"

#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H


int addCard(Card card);
Card* queryCard(const char* pName);

class card_service
{
public:
    card_service();
};

#endif // CARD_SERVICE_H
