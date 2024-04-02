/**
 * Main function for the "dalive" project.
 * 
 * @author Michail E. Koutrakis
*/
#include <stdio.h>
#include "dalive.h"

int main(void) {
    Date start_date = {-1, -1, -1};
    Date end_date = {-1, -1, -1};
    int days_alive = -1;

    /* Read date from user */
    get_date_from_user(&start_date);

    if (!is_valid_date(start_date)) {
        fprintf(stderr, "Invalid date given by user.\n");
        return 1;
    }
    
    // Get today's date
    get_todays_date(&end_date);

    // Calculate days
    days_alive = total_days(start_date, end_date);

    if (days_alive == -1) {
        fprintf(stderr, "Error occurred.\n");
        return 1;
    }

    printf("%d days passed since date of birth.\n", days_alive);
    return 0;
}