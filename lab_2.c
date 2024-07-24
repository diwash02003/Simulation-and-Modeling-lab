// 2. Lab work 2
// At the ticket counter of football stadium, people come in queue and purchase tickets. Arrival rate of customers is 1/min. It takes at the average 20 seconds to purchase the ticket.
// WAP in C to calculate total time spent by a sports fan to be seated in his seat,
//  if it takes 1.5 minutes to reach the correct seat after purchasing the ticket. if a fan comes exactly before 2 minutes before the game starts, can sports fan expect to be seated for the kick-off?

#include <stdio.h>

int main()
{
    // Time parameters (in minutes)
    double arrival_rate = 1.0;       // customers per minute
    double service_time = 20.0 / 60; // minutes (average ticket purchase time)
    double walk_to_seat_time = 1.5;
    double time_before_game = 2.0;

    // Calculate total time spent by the fan
    double total_time = 1.0 / arrival_rate + service_time + walk_to_seat_time;

    // Check if seated before kick-off (considering buffer time)
    int seated_on_time = total_time <= time_before_game;
    // Print results
    printf("Total time spent by the sports fan: %.2f minutes\n", total_time);

    if (seated_on_time)
    {
        printf("The sports fan can expect to be seated for the kick-off.\n");
    }
    else
    {
        printf("The sports fan might miss the kick-off.\n");
    }

    return 0;
}