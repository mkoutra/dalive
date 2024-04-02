/**
 * Function definitions for the "dalive" project.
 * 
 * @author Michail E. Koutrakis
*/
#include <stdio.h>
#include <time.h>
#include "dalive.h"


/**
 * Asks user for a date and stores it in the struct pointed to by d.
 * Returns 0 on success, otherwise -1.
*/
int get_date_from_user(Date* d) {
    char buffer[BUFFER_SIZE];

    printf("Enter date of birth [dd/mm/yyyy] >> ");
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error while getting input from user.\n");
        return -1;
    }

    if (sscanf(buffer, "%d%*[-/_. ]%d%*[-_/. ]%d", &d->day, &d->month, &d->year) != 3) {
        fprintf(stderr, "Unexpected date format.\n");
        return -1;
    }
    
    return 0;
}


/**
 * Stores today's date in the Date structure pointed to by `d`.
*/
void get_todays_date(Date* d) {
    time_t t;
    struct tm today;

    // Get current date
    t = time(NULL);
    today = *localtime(&t);

    d->day = today.tm_mday;
    d->month = today.tm_mon + 1;
    d->year = today.tm_year + 1900;
}


/**
 * Returns total days passed between start_date and end_date.
 * In case of error, it returns -1.
 */
int total_days(Date start_date, Date end_date) {
    /* Days lived in start year, end year and between them. */
    int days_in_start_year = 0;
    int days_in_end_year = 0;
    int days_in_between = 0;

    if (!is_valid_date(start_date) || !is_valid_date(end_date)) {
        fprintf(stderr, "Invalid date given.\n");
        return -1;
    }
    
    if (date_cmp(start_date, end_date) > 0) {
        fprintf(stderr, "Error: start_date must be before end_date.\n");
        return -1;
    }
    
    /* Exact same date */
    if (date_cmp(start_date, end_date) == 0) {
        return 1;
    }

    /* Both dates refer to the same year */
    if (start_date.year == end_date.year) {
        return day_position(end_date) - day_position(start_date) + 1;
    }

    /* Days lived in the start and end year */
    days_in_start_year = days_in_year(start_date.year) - day_position(start_date);
    days_in_end_year = day_position(end_date);

    // Days liven in the years between start and end year.    
    for (int i = start_date.year + 1; i < end_date.year; ++i) {
        days_in_between += days_in_year(i);
    }

    return days_in_start_year + days_in_end_year + days_in_between;
}


/**
 * Returns true if the given year is a leap year.
*/
bool is_leap(const int year) {
    if (year < 1) return false;

    if (year % 4 != 0) return false;
    if (year % 100 !=0) return true;
    if (year % 400 !=0) return false;
    else return true;
}


/**
 * Returns the days contained in the given year.
 * In case of error, returns -1.
*/
int days_in_year(const int year) {
    if (year < 1) {
        fprintf(stderr, "Invalid year in days_in_year()\n");
        return -1;
    }
    return is_leap(year) ? 366 : 365;
}


/**
 * Returns the number of days in a given month of a given year.
 * In case of error, it returns -1; 
*/
int days_in_month(const int month, const int year) {
    if (month < 1 || month > 12) {
        fprintf(stderr, "Invalid month given.\n");
        return -1;
    }

    if (year < 1) {
        fprintf(stderr, "Invalid year.\n");
        return -1;
    }

    switch(month) {
        case 2:
            return is_leap(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}


/**
 * Returns true if the date given is valid,
 * otherwise returns false.
*/
bool is_valid_date(const Date date) {
    if ((date.year < 1) ||
        (date.month < 1 || date.month > 12) ||
        (date.day < 1 || date.day > 31) ||
        (date.day > days_in_month(date.month, date.year))) {
        
        return false;
    }

    return true;
}


/**
 * Compares two integers n1 and n2.
 * Returns:
 *  - 1 if n1 > n2
 *  - -1 if n1 < n2
 *  - 0 if n1 == n2
*/
int int_comp(const int n1, const int n2) {
    if (n1 == n2) return 0;
    return (n1 > n2) ? 1 : -1;
}


/**
 * Compares two given dates d1 and d2.
 * Returns:
 *  - 1 if d1 is after d2
 *  - -1 if d1 is before d2
 *  - 0 if d1 and d2 are the same.
*/
int date_cmp(const Date d1, const Date d2) {
    if (!is_valid_date(d1) || !is_valid_date(d2)) {
        fprintf(stderr, "Invalid dates.\n");
        return -1;
    }
    
    if (d1.year != d2.year) {
        return int_comp(d1.year, d2.year);
    }
    else {  // Same year
        if (d1.month != d2.month) {
            return int_comp(d1.month, d2.month);
        }
        else {  // Same month
            if (d1.day != d2.day) {
                return int_comp(d1.day, d2.day);
            }
            else return 0; // Same date
        }
    }
}


/*
 * Returns the position of the day in the year of the given date.
 * In case of error, returns -1.
 *
 * Example: 15/02/1970 is day 46th day of year 1970.
*/
int day_position(const Date date) {
    if (!is_valid_date(date)) {
        fprintf(stderr, "Invalid date.\n");
        return -1;
    }
    
    int pos = date.day;  // Position in current month

    // Add days from previous months (if they exist)
    for (int i = 1; i < date.month; ++i) {
        pos += days_in_month(i, date.year);
    }

    return pos;
}
