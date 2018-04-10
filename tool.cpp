#include <time.h>
#include "tool.h"
#include <stdio.h>


void timeToString(time_t t, char* pBuf)
{
    struct tm* timeInfo;
    timeInfo = localtime(&t);
    strftime(pBuf, 20, "%Y-%m-%d %H:%M", timeInfo);
}

time_t stringToTime(char* pTime)
{
    struct tm tm1;
    time_t time1;

    sscanf(pTime, "%d-%d-%d %d:%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday, &tm1.tm_hour, &tm1.tm_min);
    time1 = mktime(&tm1);

    return time1;
}

int getSize(const char* pInput)
{
    int nSize = 0;
    while(*(pInput + nSize) != '\0')
    {
        nSize++;
    }
    return nSize;
}

void copyInfo(const char aInput[], char aOutput[], int nSize)
{
    for (int i = 0; i < nSize; i++){
        aOutput[i] = aInput[i];
        if(aOutput[i] == '\0')break;
    }
}
