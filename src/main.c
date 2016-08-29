/* Run for the date of today */

#include <stdio.h>
#include "../util/getDate.h"

int gregorian(int year, int month, int day);

int main(void)
{
    /* Test the algorithm with the current date */
    struct tm* currentTime; int dayToday = 0, monthToday = 0, yearToday = 0;
    currentTime = getDate(dayToday, monthToday, yearToday);
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

