#include <iostream>
#include <string.h>
#include "card_service.h"
#include "global.h"
#include "model.h"

Card aCard[50];
int nCount = 0;
lpCardNode cardList = NULL;
lpCardNode head = NULL;

bool initCardList()
{
    head = (lpCardNode)malloc(sizeof(cardList));
    if(head != NULL){
        head->next = NULL;
        cardList = head;
        return true;
    }
    return false;
}

void releaseCardList()
{
    lpCardNode cur = NULL;
    if(cardList != NULL){
        while(cardList->next != NULL){
            cur = cardList->next;
            free(cur);
            cur = NULL;
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
        if(initCardList()){
            printf("链表初始化成功!\n");
        }else{
            printf("链表初始化失败!\n");
            return false;
        }
    }

    lpCardNode cur = NULL;
    cur = (lpCardNode)malloc(sizeof(CardNode));
    if(cur != NULL){
        cur->data = card;
        cur->next = NULL;
    }else{
        printf("分配内存空间失败!\n");
        return false;
    }

    while(cardList->next != NULL){
        cardList = cardList->next;
    }
    cardList->next = cur;

    nCount++;
    printf("结点数: %d\n", nCount);
    return true;
}

Card* queryCard(const char* pName)
{
//    for(int i = 0; i < nCount; i++)
//    {
//        if(strcmp(pName, aCard[i].aName) == 0)
//            return &aCard[i];
//    }
//    return NULL;

    lpCardNode p = cardList;

}

card_service::card_service()
{

}











