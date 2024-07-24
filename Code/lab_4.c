/* In a single pump service station, vehicles arrive for fueling with 
an average of 5 minutes between arrivals. If an hour is taken as unit of time,
 cars arrive according to Poison’s process with an average of λ= 12 cars/hr. 
 Write a C program to generate Poisson distribution for x = 0,1,2, …. 15.
 */

#include <stdio.h>
#include <math.h>

double factorial(int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    // Arrival rate (lambda)
    double lambda = 12.0;

    // Loop through x values (0 to 15)
    for (int x = 0; x <= 15; x++)
    {
        // Calculate probability using Poisson distribution formula
        double probability = (pow(lambda, x) * exp(-lambda)) / factorial(x);

        // Print result
        printf("P(x = %d) = %.4f\n", x, probability);
    }

    return 0;
}