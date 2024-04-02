/**
 * Header file for the dalive project.
 * 
 * @author Michail E. Koutrakis
*/

#ifndef DALIVE_H
#define DALIVE_H

#include <stdbool.h>

#define BUFFER_SIZE 20

typedef struct date {
    int day;
    int month;
    int year;
} Date;


/**
 * Asks user for a date and stores it the the struct pointed to by d.
 * Returns 0 on success, otherwise -1.
*/
int get_date_from_user(Date* d);


/**
 * Stores today's date in the Date structure pointed to by `d`.
*/
void get_todays_date(Date* d);


/**
 * Returns total days passed between start_date and end_date.
 */
int total_days(Date start_date, Date end_date);


/**
 * Returns true if the given year is a leap year.
*/
bool is_leap(const int year);


/**
 * Returns the days contained in the given year.
 * In case of error, returns -1.
*/
int days_in_year(const int year);


/**
 * Returns the number of days in a given month of a given year.
 * In case of error, it returns -1; 
*/
int days_in_month(const int month, const int year);


/**
 * Returns true if the date given is valid,
 * otherwise returns false.
*/
bool is_valid_date(const Date date);


/**
 * Compares two integers n1 and n2.
 * Returns:
 *  - 1 if n1 > n2
 *  - -1 if n1 < n2
 *  - 0 if n1 == n2
*/
int int_comp(const int n1, const int n2);


/**
 * Compares two given dates d1 and d2.
 * Returns:
 *  - 1 if d1 is after d2
 *  - -1 if d1 is before d2
 *  - 0 if d1 and d2 are the same.
*/
int date_cmp(const Date d1, const Date d2);


/*
 * Returns the position of the day in the year of the given date.
 * In case of error, returns -1.
 *
 * Example: 15/02/1970 is day 46th day of year 1970.
*/
int day_position(const Date date);


#endif // DALIVE_H