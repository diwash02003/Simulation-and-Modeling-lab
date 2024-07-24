// kstest
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 10
#define ALPHA 0.05
#define CRITICAL_VALUE 1.36

// Function to compare doubles (for qsort)
int compare_doubles(const void *a, const void *b)
{
    double diff = *(double *)a - *(double *)b;
    if (diff < 0)
        return -1;
    if (diff > 0)
        return 1;
    return 0;
}

// Function to compute Empirical Distribution Function (EDF)
double empirical_distribution_function(double x, double *data, int n)
{
    int i;
    int count = 0;
    for (i = 0; i < n; ++i)
    {
        if (data[i] <= x)
            count++;
    }
    return (double)count / n;
}

// Function to perform Kolmogorov-Smirnov test
void ks_test(double *data, int n)
{
    int i;
    double ks_statistic = 0.0;

    // Sort the data
    qsort(data, n, sizeof(double), compare_doubles);

    // Calculate KS statistic
    for (i = 0; i < n; ++i)
    {
        double edf_value = empirical_distribution_function(data[i], data, n);
        double diff1 = fabs(edf_value - ((double)(i + 1) / n));
        double diff2 = fabs(edf_value - ((double)i / n));
        double max_diff = fmax(diff1, diff2);
        if (max_diff > ks_statistic)
            ks_statistic = max_diff;
    }

    // Compute critical value for significance level alpha=0.05
    double critical_value = CRITICAL_VALUE / sqrt(n);

    // Output results
    printf("Kolmogorov-Smirnov Statistic: %f\n", ks_statistic);
    printf("Critical value at alpha=0.05 is %f\n", critical_value);
    if (ks_statistic <= critical_value)
        printf("Fail to reject the null hypothesis. The sample comes from the specified distribution.\n");
    else
        printf("Reject the null hypothesis. The sample does not come from the specified distribution.\n");
}

int main()
{
    double data[MAX_DATA_POINTS];
    int n, i;

    // Prompt user for number of data points
    printf("Enter the number of data points (up to %d): ", MAX_DATA_POINTS);
    scanf("%d", &n);

    // Check if input is within bounds
    if (n <= 0 || n > MAX_DATA_POINTS)
    {
        printf("Invalid input. Number of data points must be between 1 and %d.\n", MAX_DATA_POINTS);
        return 1; // Exit with error
    }

    // Prompt user to enter data points
    printf("Enter %d data points:\n", n);
    for (i = 0; i < n; ++i)
    {
        printf("Data point %d: ", i + 1);
        scanf("%lf", &data[i]);
    }

    // Perform KS test
    ks_test(data, n);

    return 0;
}
