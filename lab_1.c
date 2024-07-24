// Lab work 1
// Customers arrive in a bank according to a Poisson's process with mean inter arrival time of 10 minutes. Customers spend an average of 5 minutes on the single available counter, and leave. Write a program in C to find:
// I.	Probability that a customer will not have to wait at the counter.
// II.	 Expected number of customers in the bank.
// III.	Time can a customer expect to spend in the bank.

#include <stdio.h>
#include <math.h>

int main()
{
    double arrival_rate = 1.0 / 10; // customers per minute (10 min mean inter arrival time)
    double service_time = 5.0;      // minutes

    double rho = arrival_rate * service_time;

    // Probability of no waiting
    double p_no_wait = 1 - exp(-rho);

    // Expected number of customers
    double L = rho / (1 - rho);

    // Expected time in bank
    double W = service_time / (1 - rho);

    printf("Probability of no waiting: %.4f\n", p_no_wait);
    printf("Expected number of customers: %.4f\n", L);
    printf("Expected time in bank: %.4f minutes\n", W);

    return 0;
}