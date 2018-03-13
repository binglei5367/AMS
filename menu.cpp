#include <iostream>
#include <time.h>
#include <stdio.h>
#include "menu.h"
#include "model.h"
#include "card_service.h"
#include "tool.c"


using namespace std;

menu::menu()
{

}

int outputMenu()
{
    cout << "-------菜单-------" << endl;
    cout << "1.添加卡" << endl;
    cout << "2.查询卡" << endl;
    cout << "3.上机" << endl;
    cout << "4.下机" << endl;
    cout << "5.充值" << endl;
    cout << "6.退费" << endl;
    cout << "7.查询统计" << endl;
    cout << "8.注销卡" << endl;
    cout << "0.退出" << endl;
    cout << "请选择菜单项编号:(0~8):";

    int nSelection = -1;
    scanf("%d", &nSelection);
    while (nSelection > 8 || nSelection < 0){
        cout << "输入菜单序号必须为0～8!" << endl;
        cout << "重新输入：";
        scanf("%d", &nSelection);
    }
    switch (nSelection) {
    case 1:     //添加卡
        add();
        break;
    case 2:     //查询卡
        query();
        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 0:
        exit();
        break;
    default:
        break;
    }
    return nSelection;
}

/**********添加卡***********/
void add()
{
    cout << "-------添加卡-------" <<endl;
    Card card;
    char aName[32];
    char aPwd[20];

    do{
        cout << "输入卡号(长度为1～18个字符): ";
        cin >> aName;
    }while(getSize(aName) >= 18);
    //strcpy(aName, card.aName);
    copyInfo(aName, card.aName, 18);

    do{
        cout << "输入密码(长度为1～8个字符): ";
        cin >> aPwd;
    }while(getSize(aPwd) >= 8);
    //strcpy(aPwd, card.aPwd);
    copyInfo(aPwd, card.aPwd, 8);

    cout << "输入开卡金额(数字): ";
    cin >> card.fBalance;


    card.fTotalUse = card.fBalance;
    card.nDel = 0;
    card.nStatus = 0;
    card.nUseCount = 0;
    card.tEnd = card.tLastTime = card.tStart = time(NULL);

    struct tm* startTime;
    struct tm* endTime;
    startTime = localtime(&card.tStart);
    endTime = localtime(&card.tEnd);
    endTime->tm_year = startTime->tm_year + 1;
    card.tEnd = mktime(endTime);

    printf("卡号\t\t\t密码\t\t状态\t开卡金额\n");
    printf("%-18s\t%-8s\t%d\t%0.1f\n", card.aName, card.aPwd, card.nStatus, card.fBalance);

    printf("添加到链表..\n");

    if(addCard(card)){
        printf("添加成功!\n");
    }else{
        printf("添加失败,请检查!\n");
    }
}

/**********查询卡***********/
void query()
{
    cout << "-------查询卡-------" <<endl;
    char aName[18];
    Card* pCard = NULL;
    cout << "输入卡号(长度为1～18个字符): ";
    cin >> aName;

    pCard = queryCard(aName);
    if(pCard != NULL)
    {
        Card card = *pCard;
        char aLastTime[20] = {'\0'};
        timeToString(card.tLastTime, aLastTime);
        printf("卡号\t\t\t"
               "状态\t"
               "余额\t"
               "累计使用\t"
               "使用次数\t"
               "上次使用时间\n");
        printf("%-18s\t"
               "%d\t"
               "%0.1f\t"
               "%0.1f\t\t"
               "%-8d\t"
               "%-20s\n",
               card.aName, card.nStatus, card.fBalance, card.fTotalUse, card.nUseCount, aLastTime);
    }else{
        printf("未找到!\n");
    }
}


void exit()
{
    releaseCardList();
    cout << "释放内存.." << endl;
}











