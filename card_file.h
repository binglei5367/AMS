#ifndef CARD_FILE_H
#define CARD_FILE_H

#include "model.h"

bool saveCard(const Card* pCard, const char *pPath);
bool readCard(Card* pCard, const char *pPath);
Card parseCard(char *pBuf);
int getCardCount(const char* pPath);

class card_file
{
public:
    card_file();
};

#endif // CARD_FILE_H
