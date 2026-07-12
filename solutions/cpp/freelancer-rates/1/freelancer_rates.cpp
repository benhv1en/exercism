// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>

// daily_rate calculates the daily rate given an hourly rate
#define NUMBER_OF_DAILY_WORKING_HOURS 8.0
#define NUMBERS_OF_MONTHLY_WORKING_DAYS 22.0
double daily_rate(double hourly_rate) {
    return NUMBER_OF_DAILY_WORKING_HOURS * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount * (1.0 - discount / 100.0);
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
#include <cmath>
int monthly_rate(double hourly_rate, double discount) {
    return ceil(apply_discount(NUMBERS_OF_MONTHLY_WORKING_DAYS * daily_rate(hourly_rate), discount));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
   return budget / apply_discount(daily_rate(hourly_rate), discount);
}
