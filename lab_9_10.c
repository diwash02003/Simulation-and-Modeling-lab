/*
    Lab work 9
    WAP to use mixed congruential method to generate a sequence of
    10 five-digit random integers and corresponding random variables.
    Let x0 = 4, a=3 and c=2.

    Lab work 10
    WAP to use Multiplicative congruential method to generate a sequence of
    10 three-digit random integers and corresponding random variables.
    Let x0 = 5, a=3 and c=2.
*/

#include <stdio.h>

// Function
void mixedCongruential(int x0, int a, int c, int m, int n);
void multiplicativeCongruential(int x0, int a, int m, int n);

int main()
{
    int choice;

    printf("Choose the method:\n");
    printf("1. Mixed Congruential Method (10 five-digit numbers)\n");
    printf("2. Multiplicative Congruential Method (10 three-digit numbers)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    if (choice == 1)
    {
        int x0 = 4, a = 3, c = 2, m = 100000, n = 10; // five-digit integers
        mixedCongruential(x0, a, c, m, n);
    }
    else if (choice == 2)
    {
        int x0 = 5, a = 3, m = 1000, n = 10; // three-digit integers
        multiplicativeCongruential(x0, a, m, n);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}

// Mixed Congruential Method
void mixedCongruential(int x0, int a, int c, int m, int n)
{
    int xi = x0;
    printf("Mixed Congruential Method:\n");
    printf("Random Integers: ");
    for (int i = 0; i < n; i++)
    {
        xi = (a * xi + c) % m;
        printf("%05d ", xi);
    }
    printf("\nRandom Variables: ");
    xi = x0; // Reset xi to initial value
    for (int i = 0; i < n; i++)
    {
        xi = (a * xi + c) % m;
        printf("%.5f ", (double)xi / m);
    }
    printf("\n");
}

// Multiplicative Congruential Method
void multiplicativeCongruential(int x0, int a, int m, int n)
{
    int xi = x0;
    printf("Multiplicative Congruential Method:\n");
    printf("Random Integers: ");
    for (int i = 0; i < n; i++)
    {
        xi = (a * xi) % m;
        printf("%03d ", xi);
    }
    printf("\nRandom Variables: ");
    xi = x0; // Reset xi to initial value
    for (int i = 0; i < n; i++)
    {
        xi = (a * xi) % m;
        printf("%.3f ", (double)xi / m);
    }
    printf("\n");
}
