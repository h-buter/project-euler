// https://projecteuler.net/problem=9
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>
#include <math.h>

const int maxNumber = 1000; //If one digit is equal to 1000 the rest should be 0 then the product will be 0
const int constant = 1000;

int foundA, foundB, foundC = 0;

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Special Pythagorean Triplet");

    for(int a = 1; a <= maxNumber; a++)
    {
        for(int b = a + 1; b <= maxNumber; b++)
        {
            for(int c = b + 1; c <= maxNumber; c++)
            {
                unsigned long sum = a + b + c;
                if(sum == constant) //Checking if the sum a + b + c is equal to 1000 to check the last part
                {
                    unsigned long sumOfSquareAB = pow(a, 2) + pow(b, 2);
                    int squareC = pow(c, 2);
                    if(sumOfSquareAB == squareC) //Also a^2 + b^2 should be equal to c^2
                    {
                        foundA = a;
                        foundB = b;
                        foundC = c;
                        a = b = c = maxNumber; //Numbers have been found stop by jumping to end
                    }
                }
            }
        } 
    }


    int product = foundA * foundB * foundC; //Calculate the solution to the problem by calculating the product of the three found numbers
    if(0 == product)
    {
        printf("No solution has been found");
    }
    else
    {
        printf("The solution to a+b+c=1000: a = %i, b = %i, c = %i, to product of abc is the solution to the problem: %i*%i*%i=%i\n", foundA, foundB, foundC, foundA, foundB, foundC, product);
    }

    return 0;
}
