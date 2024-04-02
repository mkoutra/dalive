#include "days_alive.h"

int main(void) {
    // Day, month, year given by user.
    int u_day, u_month, u_year;
    int days_alive;

    // Read date of birth from user
    printf("Date of birth [dd/mm/yyyy] >> ");
    scanf("%d/%d/%d", &u_day, &u_month, &u_year); getchar();

    days_alive = total_days(u_day, u_month, u_year);

    printf(" %d days passed since birth date.\n", days_alive);
    return 0;
}