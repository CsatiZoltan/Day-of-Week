/* Calculate the day of the week for any Gregorian calendar date.
   The algorithm behind it is Zeller's congruence.

   Input: year, month, day
   Output: day of the week (1=Monday, 7=Sunday)
*/


int gregorian(int year, int month, int day)
{
    /* Zeller's method needs the months in the order
       March=3, ..., December=12, January=13, February=14.
       For January and February we must decrease the year by 1*/
    if (month == 1) /* January */
    {
        month = 13;
        year--;
    }
    else if (month == 2) /* February */
    {
        month = 14;
        year--;
    }

    /* Zeller's formula */
    int dayOfWeek;
    dayOfWeek = (day + 13*(month+1)/5 + year + year/4 - year/100 + year/400) %7;
    /* Corvert it to ISO day-of-week */
    dayOfWeek = (dayOfWeek+5) % 7 + 1;
    return dayOfWeek;
}
