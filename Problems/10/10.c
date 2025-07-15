// https://projecteuler.net/problem=10
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

bool checkPrime(unsigned long x);

int maxPrimeSum = 2 * 10E5;

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Summation of Primes");
    // printf("%i\n", maxPrimeSum);

    unsigned long i = 1; //Current number to be checked if it is a prime
    int primeCount = 1; //Count the primes that have been found
    unsigned long primeSum = 2; // Other than 2 there is no even number that is a prime
    while(i < maxPrimeSum) //Loop until the sum has been found
    {
        i = i + 2;
        if(checkPrime(i))
        {
            primeSum += i;
            primeCount++;
            if(primeCount % (unsigned long)10000 == 0)
            {
                printf("Prime sum is now: %li, precent of the way %.2f%%, currently checking %li\n", primeSum, ((double)(100.0 / (double)maxPrimeSum * (double)i)), i);
            }
        }
    }

    printf("The sum of all primes below %i is: %li\n", maxPrimeSum, primeSum);
}

bool checkPrime(unsigned long x)
{
    for(unsigned long i = 2; i < x; i++)
    {
        if(x % i == 0) //Check if the number is cleanly divisible by any number but it self and 1
        {
            return false;
        }
    }
    return true;
}
