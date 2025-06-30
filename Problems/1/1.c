//https://projecteuler.net/problem=1
#include <stdio.h>  
#include "../common.h"

const int max = 1000;
int total = 0;
int multiples[] = {3,5};


int main() 
{  
    printProblemNumber(__FILE_NAME__, "Multiples of 3 or 5");
    for (int i = 1; i <= max-1; i++) // Loop over all values minus 1 because of "under x"
    {
        for (unsigned long j = 0; j < sizeof(multiples) / sizeof(multiples[0]); j++) // Loop over all multiple checks with a second for loop for the amount of multiples
        {
            if (i % multiples[j] == 0) // Check the modulo of the multiples
            {
                // printf("i: %i, j: %li, multiples: %i\n", i, j, multiples[j]);
                total += i; // Sum the values
                break; // Break the multiples for loop other wise doubles, for example mod of 3 and 5 are both true for 15, so skip checking the other modulo's when one is true
            }
        }
    }

    printf("Result: %i\n", total);

    return 0;  
}