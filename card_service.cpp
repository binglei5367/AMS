#include <iostream>
#include <string.h>
#include "card_service.h"
#include "global.h"
#include "model.h"

Card aCard[50];
int nCount = 0;
lpCardNode cardList = NULL;
lpCardNode head = NULL;

void initCardList()
{
    head = (lpCardNode)malloc(sizeof(cardList));
    if(head != NULL){
        head->next = NULL;
        cardList = head;
    }
}

void releaseCardList()
{
    lpCardNode cur = NULL;
    if(cardList != NULL){
        while(cardList->next != NULL){
            cur = cardList;
            cardList = cardList->next;
            free(cur);
        }
    }
}

bool addCard(Card card)
{
//    if(nCount > 49)
//    {
//        printf("Overflow!\n");
//        return 0;
//    }
//    aCard[nCount] = card;

    if(cardList == NULL){
        initCardList();
        if(cardList == NULL){
            printf("链表初始化失败!\n");
            return false;
        }
    }

    lpCardNode cur = NULL;
    cur = (lpCardNode)malloc(sizeof(CardNode));
    if(cur != NULL){
        cur->data = card;
        cur->next = NULL;
        printf("结点分配内存空间成功!\n");
    }else{
        printf("结点分配内存空间失败!\n");
        return false;
    }

    while(cardList->next != NULL){
        cardList = cardList->next;
    }
    cardList->next = cur;
    cardList = head;

    nCount++;
    printf("结点数: %d\n", nCount);
    return true;
}

Card* queryCard(const char* pName, int* pIndex)
{
//    for(int i = 0; i < nCount; i++)
//    {
//        if(strcmp(pName, aCard[i].aName) == 0)
//            return &aCard[i];
//    }
//    return NULL;

    lpCardNode p = cardList;
    Card* pCard = NULL;
    pCard = (Card*)malloc(sizeof(Card));
    *pIndex = 0;

    while(p != NULL){
        if(strstr(p->data.aName, pName) != NULL){
            pCard[*pIndex] = p->data;
            (*pIndex)++;
            pCard = (Card*)realloc(pCard, ((*pIndex) + 1) * sizeof(Card));
            p = p->next;
//            return &p->data;
        }else{
            p = p->next;
        }
    }
    return pCard;

}

card_service::card_service()
{

}











