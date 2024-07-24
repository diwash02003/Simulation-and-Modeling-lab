// Lab Work 3
// WAP to compute PI using Monte Carlo method using c programming language.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to compute Pi using Monte Carlo method
double compute_pi(int num_samples)
{
    int inside_circle = 0;
    double x, y;

    for (int i = 0; i < num_samples; ++i)
    {
        // Generate random points (x, y) where x and y are between -1 and 1
        x = (double)rand() / RAND_MAX * 2.0 - 1.0; // Random number between -1 and 1
        y = (double)rand() / RAND_MAX * 2.0 - 1.0; // Random number between -1 and 1

        // Check if the point is inside the quarter circle
        if (x * x + y * y <= 1.0)
        {
            inside_circle++;
        }
    }

    // Compute Pi
    return (4.0 * inside_circle) / num_samples;
}

int main()
{
    int num_samples;
    double pi_estimate;

    // Seed the random number generator
    srand(time(NULL));

    // Input the number of samples
    printf("Enter the number of samples: ");
    scanf("%d", &num_samples);

    // Compute Pi
    pi_estimate = compute_pi(num_samples);

    // Output the result
    printf("Estimated value of Pi: %.6f\n", pi_estimate);

    return 0;
}
