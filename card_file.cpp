#include "card_file.h"
#include "stdio.h"
#include "tool.h"
#include "model.h"
#include "stdlib.h"
#include "global.h"
#include <time.h>
#include <cstring>

int nIndex = 0;

bool saveCard(const Card* pCard, const char* pPath)
{
    FILE* fp = NULL;
    char aLastTime[20] = {'\0'};
    char aStartTime[20] = {'\0'};
    char aEndTime[20] = {'\0'};

    if((fp = fopen(pPath, "a")) == NULL){
        if((fp = fopen(pPath, "w")) == NULL){
            return false;
        }
    }

    timeToString(pCard->tLastTime, aLastTime);
    timeToString(pCard->tStart, aStartTime);
    timeToString(pCard->tEnd, aEndTime);

//    char aName[18];
//    char aPwd[8];
//    int nStatus;        //卡状态(0-未上机; 1-正在上机; 2-已注销; 3-失效)
//    time_t tStart;
//    time_t tEnd;
//    float fTotalUse;
//    time_t tLastTime;
//    int nUseCount;
//    float fBalance;
//    int nDel;           //删除标识(0-未删除; 1-删除)

    fprintf(fp, "%s##%s##%d##%s##%s%.1f##%s##%d##%.1f##%d\n",
            pCard->aName,
            pCard->aPwd,
            pCard->nStatus,
            aStartTime,
            aEndTime,
            pCard->fTotalUse,
            aLastTime,
            pCard->nUseCount,
            pCard->fBalance,
            pCard->nDel);
    fclose(fp);
    return true;

}

bool readCard(Card* pCard, const char* pPath)
{
    //以只读方式打开文件
    FILE* fp = NULL;
    if((fp = fopen(pPath, "r")) == NULL){
        printf("文件打开失败！\n");
        return false;
    }

    //遍历文件
    char aBuf[CARDCHARNUM] = {0};
    while(!feof(fp)){
        memset(aBuf, 0, CARDCHARNUM);//清空数组
        if(fgets(aBuf, CARDCHARNUM, fp) != NULL){
//            printf("遍历数据文件data.txt\n");
            if(strlen(aBuf) > 0){
//                printf("读取一条账户信息\n");
                pCard[nIndex] = parseCard(aBuf);
                nIndex++;
            }
        }
    }
    fclose(fp);
    return true;
}

Card parseCard(char *pBuf)
{
    Card card;
    const char *delims = "##";
    char flag[10][20] = {0};
    int index = 0;
    char *buf = NULL;
    char *str = NULL;

    buf = pBuf;

    while((str = strtok(buf, delims)) != NULL){
        strcpy(flag[index], str);
        buf = NULL;
        index++;
    }

    //    char aName[18];
    //    char aPwd[8];
    //    int nStatus;        //卡状态(0-未上机; 1-正在上机; 2-已注销; 3-失效)
    //    time_t tStart;
    //    time_t tEnd;
    //    float fTotalUse;
    //    time_t tLastTime;
    //    int nUseCount;
    //    float fBalance;
    //    int nDel;           //删除标识(0-未删除; 1-删除)

    strcpy(card.aName, flag[0]);
    strcpy(card.aPwd, flag[1]);
    card.nStatus = atoi(flag[2]);
    card.tStart = stringToTime(flag[3]);
    card.tEnd = stringToTime(flag[4]);
    card.fTotalUse = atof(flag[5]);
    card.tLastTime = stringToTime(flag[6]);
    card.nUseCount = atoi(flag[7]);
    card.fBalance = atof(flag[8]);
    card.nDel = atoi(flag[9]);

//    printf("解析了一条卡信息\n");
    return card;
}

int getCardCount(const char* pPath)
{
    FILE* fp = NULL;
    int nIndex = 0;
    char aBuf[CARDCHARNUM] = {0};
    if((fp = fopen(pPath, "r")) == NULL){
        return 0;
    }
    while(!feof(fp)){
        memset(aBuf, 0, CARDCHARNUM);
        if(fgets(aBuf, CARDCHARNUM, fp) != NULL){
            if(strlen(aBuf) > 0){
                nIndex++;
            }
        }
    }
    fclose(fp);
    return nIndex;
}

card_file::card_file()
{

}
