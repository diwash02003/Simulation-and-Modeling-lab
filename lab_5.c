// Lab 5
// Weather Problem:
// raining today ⇒ 40 % rain tomorrow
//               ⇒ 60 % no rain tomorrow
// not raining today ⇒ 20 % rain tomorrow
//                   ⇒ 80 % no rain tomorrow
// What will be probability if today is not raining then not rain the day after tomorrow?
// Write a C program to find the weather of the next day by using Markov Chain Method.

#include <stdio.h>

int main()
{
    // Initial probabilities
    double rain_today = 0.0;
    double no_rain_today = 1.0;

    // Transition probabilities
    double rain_given_rain = 0.4;
    double no_rain_given_rain = 0.6;
    double rain_given_no_rain = 0.2;
    double no_rain_given_no_rain = 0.8;

    // Calculate probabilities for tomorrow
    double rain_tomorrow = no_rain_today * rain_given_no_rain;
    double no_rain_tomorrow = no_rain_today * no_rain_given_no_rain;

    // Calculate probabilities for the day after tomorrow
    double rain_day_after_tomorrow = rain_tomorrow * rain_given_rain + no_rain_tomorrow * rain_given_no_rain;
    double no_rain_day_after_tomorrow = rain_tomorrow * no_rain_given_rain + no_rain_tomorrow * no_rain_given_no_rain;

    printf("Probability of not raining the day after tomorrow given not raining today: %.2f\n", no_rain_day_after_tomorrow);

    return 0;
}
