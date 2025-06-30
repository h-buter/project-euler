// https://projecteuler.net/problem=2
#include <stdio.h>  
#include "../common.h"

const int max = 4e6;
unsigned long total = 0;
int fibPrev = 1;
int fibCurr = 1;

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Even Fibonacci Numbers");

    while (fibCurr < max) //Loop until fibonacci number is over max.
    {
        // printf("i: %i, fib:%i\n", i, fibCurr);
        
        int fibTemp = fibPrev + fibCurr; //Calculate new fibonacci number
        fibPrev = fibCurr; //Store the previous current 
        fibCurr = fibTemp; //Store the new number as current

        if (fibCurr % 2 == 0) // Check the modulo of 2 to check if even
        {
            total += fibCurr; // Sum the values
        }
    }

    printf("Result: %li\n", total);

    return 0;  
}