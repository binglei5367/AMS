#include <iostream>
#include <string.h>
#include "card_service.h"
#include "card_file.h"
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

//********************链表存储实现***********************
//    if(cardList == NULL){
//        initCardList();
//        if(cardList == NULL){
//            printf("链表初始化失败!\n");
//            return false;
//        }
//    }

//    lpCardNode cur = NULL;
//    cur = (lpCardNode)malloc(sizeof(CardNode));
//    if(cur != NULL){
//        cur->data = card;
//        cur->next = NULL;
//        printf("结点分配内存空间成功!\n");
//    }else{
//        printf("结点分配内存空间失败!\n");
//        return false;
//    }

//    while(cardList->next != NULL){
//        cardList = cardList->next;
//    }
//    cardList->next = cur;
//    cardList = head;

//    nCount++;
//    printf("结点数: %d\n", nCount);
//    return true;
//****************************************************
//    char path[20] = {"data\\card.txt"};





    if(saveCard(&card, CARDPATH)){
        return true;
    }else{
        return false;
    }


}

Card* queryCard(const char* pName, int* pIndex)
{
//    for(int i = 0; i < nCount; i++)
//    {
//        if(strcmp(pName, aCard[i].aName) == 0)
//            return &aCard[i];
//    }
//    return NULL;

    if(!getCard()){
        return NULL;
    }
    printf("card got\n");
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


bool getCard()
{
    int nCount = 0;

//    releaseCardList();
//    if(cardList == NULL){
//        initCardList();
//    }else{
//        printf("链表初始化失败！\n");
//        return false;
//    }
    initCardList();
//    printf("链表初始化完成\n");

    lpCardNode p = cardList;
    Card* pCard = NULL;
    nCount = getCardCount(CARDPATH);
//    printf("获取数量信息\n");
//    pCard = (Card*)malloc(sizeof(Card)*nCount);
    pCard = (Card*)malloc(sizeof(Card));
    printf("分配内存空间\n");

    if(!readCard(pCard, CARDPATH)){
        free(pCard);
        printf("获取卡户信息失败!\n");
        return false;
    }

    printf("读取到%d条卡户信息\n", nCount);
//    for(int i = 0; i < nCount; i++){
//        pCard[i] = p->data;
//        pCard = (Card*)realloc(pCard, (i + 1) * sizeof(Card));
//        printf("为一条用户信息分配内存空间\n");
//        p = p->next;
//        printf("读取一条解析的卡户信息\n");
//    }
    int i = 0;
    while(p != NULL){
        pCard[i] = p->data;
        pCard = (Card*)realloc(pCard, (i + 1) * sizeof(Card));
        printf("为一条用户信息分配内存空间\n");
        p = p->next;
        printf("读取一条解析的卡户信息\n");
    }
    printf("1\n"); //***bug remain

    free(pCard);
    return TRUE;

}




card_service::card_service()
{

}











