/**
 * Header file for the dalive project.
 * 
 * @author Michalis E. Koutrakis
 * @anchor https://github.com/mkoutra
*/

#ifndef DAYS_ALIVE
#define DAYS_ALIVE

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool leap_year(int);
int month_days(int, int);
int year_days(int);
int day_number(int, int, int);
int total_days(int, int, int);
#endif // DAYS_ALIVE