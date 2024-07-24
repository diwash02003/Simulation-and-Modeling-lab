// Gap test:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate random numbers using the Multiplicative Congruential Method
void generateRandomNumbers(int X[], int n, int m, int a, int X0)
{
    int i;
    X[0] = X0;
    for (i = 1; i < n; i++)
    {
        X[i] = (a * X[i - 1]) % m;
    }
}

// Function to perform the Gap Test
void gapTest(int X[], int N, int lowerBound, int upperBound)
{
    int i, gap = 0;
    int gapFrequency[N];
    int totalGaps = 0;

    // Initialize gap frequencies to 0
    for (i = 0; i < N; i++)
    {
        gapFrequency[i] = 0;
    }

    // Count the gaps
    for (i = 0; i < N; i++)
    {
        if (X[i] >= lowerBound && X[i] <= upperBound)
        {
            if (gap > 0)
            {
                gapFrequency[gap]++;
                totalGaps++;
                gap = 0;
            }
        }
        else
        {
            gap++;
        }
    }

    // Calculate cumulative distribution
    double SN[N];
    int cumulativeGaps = 0;
    for (i = 0; i < N; i++)
    {
        cumulativeGaps += gapFrequency[i];
        SN[i] = (double)cumulativeGaps / totalGaps;
    }

    // Calculate theoretical CDF and find maximum deviation
    double D = 0.0;
    for (i = 0; i < N; i++)
    {
        if (gapFrequency[i] > 0)
        {
            double F = 1.0 - pow(0.9, i + 1);
            double deviation = fabs(F - SN[i]);
            if (deviation > D)
            {
                D = deviation;
            }
        }
    }

    // Print results
    printf("Maximum deviation (D): %f\n", D);

    // Critical value for D_alpha from KS table (example for alpha = 0.05 and sample size > 35)
    double D_alpha = 1.36 / sqrt(totalGaps);

    // Compare calculated D with critical value
    if (D < D_alpha)
    {
        printf("Null hypothesis is not rejected (D < D_alpha).\n");
    }
    else
    {
        printf("Null hypothesis is rejected (D >= D_alpha).\n");
    }
}

int main()
{
    int N, a, m, X0, lowerBound, upperBound;

    // Accept user inputs for N, a, m, X0, lowerBound, and upperBound
    printf("Enter the total number of random numbers (N): ");
    scanf("%d", &N);
    printf("Enter the multiplier (a): ");
    scanf("%d", &a);
    printf("Enter the modulus (m): ");
    scanf("%d", &m);
    printf("Enter the initial value (X0): ");
    scanf("%d", &X0);
    printf("Enter the lower bound of the range: ");
    scanf("%d", &lowerBound);
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upperBound);

    int X[N]; // Array to store random numbers

    // Generate random numbers
    generateRandomNumbers(X, N, m, a, X0);

    // Print generated random numbers
    printf("Generated random numbers:\n");
    for (int j = 0; j < N; j++)
    {
        printf("%03d ", X[j]);
    }
    printf("\n");

    // Perform the Gap Test
    gapTest(X, N, lowerBound, upperBound);

    return 0;
}
