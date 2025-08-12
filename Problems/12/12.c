// https://projecteuler.net/problem=12
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>
#include <time.h> 


#define overDivisorsToFind 500

unsigned long caclTriangleNumber(int number);
int calcTotalDivisors(unsigned long number);

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Highly Divisible Triangular Number");
    bool check = false;
    int i = 1;
    clock_t t;
    t = clock();
    while(!check)
    {
        unsigned long triangleNumber = caclTriangleNumber(i);
        int totalDivisors = calcTotalDivisors(triangleNumber);

        // if(!(i % 100))
        // {
        //      printf("The %ith triangle number is %li and has %i divisors\n", i, caclTriangleNumber(i), calcTotalDivisors(caclTriangleNumber(i)));
        // }
        
        if(totalDivisors > overDivisorsToFind)
        {
            check = 1;
        }
        else 
        {
            i++;
        }
    }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC * 1000; // in miliseconds 
    printf("The %ith triangle number is %li and has %i divisors\n", i, caclTriangleNumber(i), calcTotalDivisors(caclTriangleNumber(i)));
    printf("Took:  %.3f ms\n", time_taken);

}

unsigned long caclTriangleNumber(int number)
{
    unsigned long x = 0;
    // for(int i = 0; i <= number; i++)
    // {
    //     x += i;
    // }
    x = 0.5 * number * (number + 1); // use Gauss summation
    return x;
}

int calcTotalDivisors(unsigned long number)
{
    int divisorCount = 2; //Start with 2, any number is always cleanly divisible by 1 and it self, so start with 2
    if (number <= 3)
    {
        divisorCount--;
    }
    // printf("%li / 2 = %li", number, number/2);
    // printf(", %li: 1, ", number);

    // if(!(number & 1)) // all even numbers are divisible by 2
    // {
    //     divisorCount++;
    // }
    // if

    for(int i = 3; i <= (number / 2 + 2); i++) //Check if number is clearly devisable by i, check until half the number, devisable by half the number results in 2, only a division by the full number it self will result in a full number i.e. 1
    {
        if(!(number % i))
        {
            // printf("%i, ", i);
            divisorCount++;
        }
    }

    // printf("has %i divisors\n", divisorCount);
    return divisorCount;
}