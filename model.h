#include <time.h>
#ifndef MODEL_H
#define MODEL_H


typedef struct Card
{
    char aName[18];
    char aPwd[8];
    int nStatus;        //卡状态(0-未上机; 1-正在上机; 2-已注销; 3-失效)
    int nDel;           //删除标识(0-未删除; 1-删除)
    int nUseCount;
    time_t tStart;
    time_t tEnd;
    time_t tLastTime;
    float fTotalUse;
    float fBalance;
}Card;

typedef struct CardNode
{
    Card data;
    struct CardNode* next;
}CardNode, *lpCardNode;


#endif // MODEL_H
