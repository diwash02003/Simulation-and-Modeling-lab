// Lab work 7
// WAP to implement Stock Market Problem:
// Market up today  
// 	⇒ 50% chance of market up tomorrow
// 	⇒ 50% chance of market down tomorrow
// Market down today  
// ⇒ 30% chance of market up tomorrow
// ⇒ 70% chance of market down tomorrow
// What will be the probability if the market is down today that the market will be down the day after tomorrow?

#include <stdio.h>

int main()
{
    // Probabilities
    double prob_up_given_up = 0.5;
    double prob_down_given_up = 0.5;
    double prob_up_given_down = 0.3;
    double prob_down_given_down = 0.7;

    // Initial condition: Market is down today
    double prob_down_today = 1.0;

    // Calculate the probability of the market being down tomorrow
    double prob_down_tomorrow = prob_down_today * prob_down_given_down;

    // Calculate the probability of the market being up tomorrow
    double prob_up_tomorrow = prob_down_today * prob_up_given_down;

    // Calculate the probability of the market being down the day after tomorrow
    double prob_down_day_after_tomorrow = (prob_down_tomorrow * prob_down_given_down) +
                                          (prob_up_tomorrow * prob_down_given_up);

    // Output the result
    printf("The probability that the market will be down the day after tomorrow given that it is down today is: %.2f%%\n", prob_down_day_after_tomorrow * 100);

    return 0;
}
