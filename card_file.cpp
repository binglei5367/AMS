#include "card_file.h"
#include "stdio.h"
#include "tool.c"
#include "model.h"
#include <time.h>

bool saveCard(const Card* pCard, const char* pPath)
{
    FILE* fp = NULL;
    char aLastTime[20] = {'\0'};
    char aStartTime[20] = {'\0'};
    char aEndTime[20] = {'\0'};

    if((fp = fopen(pPath, 'a')) == NULL){
        if((fp = fopen(pPath, 'w')) == NULL){
            return false;
        }
    }

    timeToString(pCard->tLastTime, aLastTime);
    timeToString(pCard->tStart, aStartTime);
    timeToString(pCard->tEnd, aEndTime);

//    char aName[18];
//    char aPwd[8];
//    int nStatus;        //卡状态(0-未上机; 1-正在上机; 2-已注销; 3-失效)
//    int nDel;           //删除标识(0-未删除; 1-删除)
//    int nUseCount;
//    time_t tStart;
//    time_t tEnd;
//    time_t tLastTime;
//    float fTotalUse;
//    float fBalance;

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

card_file::card_file()
{

}
