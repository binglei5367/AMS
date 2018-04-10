#ifndef TOOL_H
#define TOOL_H
#include <time.h>

void timeToString(time_t t, char* pBuf);
int getSize(const char* pInput);
void copyInfo(const char aInput[], char aOutput[], int nSize);
time_t stringToTime(char* pTime);

#endif // TOOL_H
