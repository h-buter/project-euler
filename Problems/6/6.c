// https://projecteuler.net/problem=6
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

unsigned long sumOfSquares(int length);
unsigned long squareOfSum(int length);

int sumLength = 100;

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Sum Square Difference");
    
    unsigned long squareOfSumV =  squareOfSum(sumLength);
    unsigned long sumOfSquaresV = sumOfSquares(sumLength);

    unsigned long diff = abs((int)(squareOfSumV - sumOfSquaresV)); //Calculate the difference

    printf("The difference between the sum of the squares of the first %i natural numbers (%li) and the square of the sum (%li) is: %li\n", sumLength, squareOfSumV, sumOfSquaresV, diff);

}

unsigned long sumOfSquares(int length) //Return the sum of the squares, for example: 1^2 + 2^2 + ...
{
    unsigned long sum = 0;
    for(int i = 1; i <= length; i++)
    {
        sum = sum + pow(i, 2);
    }
    return sum;
}

unsigned long squareOfSum(int length) //Returns the square of the sum, for example (1 + 2 + ...)^2
{
    unsigned long sum = 0;
    sum = 0.5 * (length + 1) * length; // use Gauss summation
    sum = pow(sum, 2);
    return sum;
}