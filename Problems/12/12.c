// https://projecteuler.net/problem=12
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>
#include <time.h> 


#define overDivisorsToFind 500
// #define printTriangles

unsigned long calcTriangleNumber(int number);

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Highly Divisible Triangular Number");
    bool check = false;
    int i = 1;
    clock_t t;
    t = clock();
    while(!check)
    {
        unsigned long triangleNumber = calcTriangleNumber(i);
        unsigned long  totalDivisors = calcTotalDivisors(triangleNumber);

        // if(!(i % 100))
        // {
        //      printf("The %ith triangle number is %li and has %lii divisors\n", i, calcTriangleNumber(i), calcTotalDivisors(calcTriangleNumber(i)));
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
    printf("The %ith triangle number is %li and has %li divisors\n", i, calcTriangleNumber(i), calcTotalDivisors(calcTriangleNumber(i)));
    printf("Took:  %.3f ms\n", time_taken);

}

unsigned long calcTriangleNumber(int number)
{
    unsigned long x = 0;
    x = 0.5 * number * (number + 1); // use Gauss summation
    return x;
}