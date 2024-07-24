// Lab work 8
// Let m = 100, a = 19, c = 0, and X0 = 63, and generate a sequence random integer.
// WAP to find first 7 random number generate using any suitable method?

#include <stdio.h>

int main()
{
    int m = 100;
    int a = 19;
    int c = 0;
    int X0 = 63;
    int i;
    printf("First 7 random numbers are:\n");
    for (i = 0; i < 7; i++)
    {
        X0 = (a * X0 + c) % m;
        printf("%d ", X0);
    }
    printf("\n");

    return 0;
}