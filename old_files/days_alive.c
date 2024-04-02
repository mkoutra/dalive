#include "days_alive.h"

// Returns total days passed from the date given until today.
int total_days(int day, int month, int year) {
    // Today's day, month, year.
    int t_day, t_month, t_year;
    // Days lived in the birth year, current year and between them.
    int b_year_days = 0, cur_year_days = 0, between_days = 0;
    
    time_t t;
    struct tm today;

    // Get current date
    t = time(NULL);
    today = *localtime(&t);
    t_day = today.tm_mday;
    t_month = today.tm_mon + 1;
    t_year = today.tm_year + 1900;

    // Days lived in the birth year.
    b_year_days = year_days(year) - day_number(day, month, year);

    // Not born in the curernt year.
    if (year < t_year) { 
        // Days lived in the current year.
        cur_year_days = day_number(t_day, t_month, t_year);

        // Days liven in the years between birth and current.    
        for (int i = year + 1; i < t_year; ++i) {
            between_days += year_days(i);
        }
    }

    return b_year_days + cur_year_days + between_days;
}

// Checks if the year given is a leap year.
bool leap_year(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 !=0) return true;
    if (year % 400 !=0) return false;
    else return true;
}

// Returns the days of the year given.
int year_days(int year) {
    return 365 + (leap_year(year) == true);
}

// Returns the number of days in `month` of year `year`.
int month_days(int month, int year) {
    switch(month) {
        case 2:
            return 28 + (leap_year(year) == true);
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

/*
 * Returns the day number of the date given.
 * Example: 15/02/1970 is day #46 of the year 1970.
*/
int day_number(int day, int month, int year) {
    int sum = day;

    for (int i = 1; i < month; ++i) {
        sum += month_days(i, year);
    }

    return sum;
}