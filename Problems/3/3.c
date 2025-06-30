// https://projecteuler.net/problem=3
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

const unsigned long number = 600851475143;

// const unsigned long number = 10;
unsigned long primeFactors[1000];
int primeCount = 0;
unsigned long newNumber = number;

bool checkPrimeFactor();

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Largest Prime Factor");
    bool primeFactorReached = 0;
    unsigned long i = 2;
    while(!primeFactorReached)
    {
        if(newNumber %i == 0)
        {
            newNumber = newNumber / i;
            primeFactors[primeCount] = i;
            primeCount++;
            printf("i %li, new: %li\n", i, newNumber);
            if(newNumber == 1)
            {
                primeFactorReached = 1;
            }
        }
        else 
        {
            i++;
        }
    }

    printf("%li has the following prime factors: ", number);
    for(int j = 0; j <= primeCount - 1; j++)
    {
        printf("%li, ", primeFactors[j]);
    }

    printf("\nChecking if the prime factors multiplied are equal to %li:\n", number);
    if(checkPrimeFactor())
    {
        printf("The largest prime factor of %li, is %li\n", number, primeFactors[primeCount - 1]);
        return 0;
    }
    else 
    {
        return 1;
    }  
}

bool checkPrimeFactor()
{
    for(int j = 0; j <= primeCount - 1; j++)
    {
        printf("%li", primeFactors[j]);
        if (j != primeCount - 1)
        {
            printf(" * ");
        }
    }

    unsigned long checkNumber = primeFactors[0];
    for(int j = 1; j <= primeCount - 1; j++)
    {
        checkNumber *= primeFactors[j];
    }

    printf(" = %li", checkNumber);
    if(checkNumber == number)
    {
        printf(" = %li\n", number);
        return 1;
    }
    else 
    {
        printf(" != %li\n", number);
        return 0;
    }
}