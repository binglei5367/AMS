#include <time.h>


void timeToString(time_t t, char* pBuf)
{
    struct tm* timeInfo;
    timeInfo = localtime(&t);
    strftime(pBuf, 20, "%Y-%m-%d %H:%M", timeInfo);
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

