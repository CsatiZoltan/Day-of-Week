/* Run for the date of today */

#include <stdio.h>
#include <time.h>

int gregorian(int year, int month, int day);

int main(void)
{
    /* Test the algorithm with the current date */
    int dayToday, monthToday, yearToday;
    struct tm *currentTime;
    time_t timer;
    time(&timer);
    currentTime = localtime(&timer);
    dayToday = currentTime->tm_mday;
    monthToday = currentTime->tm_mon + 1;
    yearToday = currentTime->tm_year + 1900;
    int realDay = currentTime->tm_wday;

    /* Compare it with the calculated date */
    if (realDay == 0)
        realDay = 7;
    int computedDay = gregorian(yearToday ,monthToday, dayToday);
    if (computedDay == realDay)
        printf("The calculated and the extracted day agrees.\n");
    else
        printf("The algorithm fails for the current day.\n");

    return 0;
}

