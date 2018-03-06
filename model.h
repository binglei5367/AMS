#include <time.h>
#ifndef MODEL_H
#define MODEL_H

typedef struct Card
{
    char aName[18];
    char aPwd[8];
    int nStatus;        //卡状态(0-未上机; 1-正在上机; 2-已注销; 3-失效)
    time_t tStart;
    time_t tEnd;
    float fTotalUse;
    time_t tLastTime;
    int nUseCount;
    float fBalance;
    int nDel;           //删除标识(0-未删除; 1-删除)
}Card;

#endif // MODEL_H
