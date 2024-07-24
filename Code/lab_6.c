// Lab 6
//  Health Monitoring Problem:
//  Healthy today
//   ⇒ 90% chance of healthy tomorrow
//  ⇒ 10% chance of sick tomorrow
//  Sick today
//  ⇒ 40% chance of healthy tomorrow
//  ⇒ 60% chance of sick tomorrow
//  What will be the probability if the person is sick today that they will be sick the day after tomorrow?

#include <stdio.h>

int main()
{
    // Transition probabilities
    double P_healthy_to_healthy = 0.9;
    double P_healthy_to_sick = 0.1;
    double P_sick_to_healthy = 0.4;
    double P_sick_to_sick = 0.6;

    // Initial state: sick today
    double P_sick_today = 1.0;
    double P_healthy_today = 0.0;

    // Probabilities for tomorrow
    double P_healthy_tomorrow = P_sick_today * P_sick_to_healthy + P_healthy_today * P_healthy_to_healthy;
    double P_sick_tomorrow = P_sick_today * P_sick_to_sick + P_healthy_today * P_healthy_to_sick;

    // Probabilities for the day after tomorrow
    double P_healthy_day_after_tomorrow = P_sick_tomorrow * P_sick_to_healthy + P_healthy_tomorrow * P_healthy_to_healthy;
    double P_sick_day_after_tomorrow = P_sick_tomorrow * P_sick_to_sick + P_healthy_tomorrow * P_healthy_to_sick;

    // Output the result
    printf("Probability of being sick the day after tomorrow if sick today: %.2f%%\n", P_sick_day_after_tomorrow * 100);

    return 0;
}
