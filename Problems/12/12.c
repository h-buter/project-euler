// https://projecteuler.net/problem=12
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

#define divisorsToFind 500

unsigned long caclTriangleNumber(int number);
int calcTotalDivisors(unsigned long number);

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Highly Divisible Triangular Number");
    bool check = false;
    int i = 1;
    while(!check)
    {
        unsigned long triangleNumber = caclTriangleNumber(i);
        int totalDivisors = calcTotalDivisors(triangleNumber);

        if(!(i % 100))
        {
             printf("The %ith triangle number is %li and has %i divisors\n", i, caclTriangleNumber(i), calcTotalDivisors(caclTriangleNumber(i)));
        }
        
        if(totalDivisors > divisorsToFind)
        {
            check = 1;
        }
        else 
        {
            i++;
        }
    }
    
    printf("The %ith triangle number is %li and has %i divisors\n", i, caclTriangleNumber(i), calcTotalDivisors(caclTriangleNumber(i)));

}

unsigned long caclTriangleNumber(int number)
{
    unsigned long x = 0;
    // for(int i = 0; i <= number; i++)
    // {
    //     x += i;
    // }
    x = 0.5 * number * (number + 1); // use Gauss summation, Runtime: 262.475387866 seconds
    return x;
}

int calcTotalDivisors(unsigned long number)
{
    int divisorCount = 1; //Start with 1 for division by full number it self
    for(int i = 1; i <= number / 2; i++) //Check if number is clearly devisable by i, check until half the number, devisable by half the number results in 2, only a division by the full number it self will result in a full number i.e. 1
    {
        if(!(number % i))
        {
            divisorCount++;
        }
    }
    return divisorCount;
}