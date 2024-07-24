// chisquare test
#include <stdio.h>
#include <math.h>

#define MAX_CATEGORIES 10

// Function to compute Chi-square test statistic
double chi_square_test(int observed[], double expected[], int num_categories)
{
    double chi_square = 0.0;
    int i;

    for (i = 0; i < num_categories; ++i)
    {
        chi_square += pow(observed[i] - expected[i], 2) / expected[i];
    }

    return chi_square;
}

int main()
{
    int observed[MAX_CATEGORIES];
    double expected[MAX_CATEGORIES];
    int num_categories, i;

    // Input number of categories
    printf("Enter the number of categories (up to %d): ", MAX_CATEGORIES);
    scanf("%d", &num_categories);

    // Input observed frequencies
    printf("Enter observed frequencies for %d categories:\n", num_categories);
    for (i = 0; i < num_categories; ++i)
    {
        printf("Category %d: ", i + 1);
        scanf("%d", &observed[i]);
    }

    // Input expected probabilities or frequencies
    printf("Enter expected probabilities (or frequencies) for %d categories:\n", num_categories);
    for (i = 0; i < num_categories; ++i)
    {
        printf("Category %d: ", i + 1);
        scanf("%lf", &expected[i]);
    }

    // Calculate Chi-square test statistic
    double chi_square = chi_square_test(observed, expected, num_categories);

    // Output result
    printf("\nChi-square test statistic: %f\n", chi_square);

    return 0;
}
