// https://projecteuler.net/problem=7
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

bool checkPrime(unsigned long x);

int maxPrime = 10001;

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "10 001st Prime");

    unsigned long i = 1; //Current number to be checked if it is a prime
    int primeCount = 0; //Count the primes that have been found
    while(!(primeCount >= maxPrime)) //Loop until the needed prime has been found
    {
        i++;
        if(checkPrime(i))
        {
            printf("%li is prime\n", i);
            primeCount++;
        }
    }

    
    printf("The %ist prime is: %li\n", maxPrime, i);

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