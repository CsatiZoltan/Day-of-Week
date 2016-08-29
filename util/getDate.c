#include "getDate.h"

struct tm* getDate(int dayToday, int monthToday, int yearToday)
{
    struct tm *currentTime;
    time_t timer;
    time(&timer);
    currentTime = localtime(&timer);
    dayToday = currentTime->tm_mday;
    monthToday = currentTime->tm_mon + 1;
    yearToday = currentTime->tm_year + 1900;
    return currentTime;
}
