// https://projecteuler.net/problem=5
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

const int divisionMax = 30;

const int printStep = 10E8;

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Smallest Multiple");

    long int i = 0;
    for(int x = 1; x <= divisionMax; x++)
    {
        bool found = false;
        if(i != 0)
        {
            i--;
        }
        while(!found)
        {
            
            i++;
            // if (!(i % printStep))
            // {
            //     // printf("Currently at: %li\n", i);
            // }
            for (int j = 1; j <= x; j++)
            {
                if (i % j == 0) //If there is no remainder when divided by j
                {
                    if(j == x) //When divisionMax is reached and i is still devisable by it then the lowest number has been found
                    {
                        found = true;
                    }
                }
                else // Do not bother checking the other until divisionMax when a lower number is not dividable
                {
                    j = x;
                }
            }
        }


        printf("Smallest number that is dividable by the numbers 1 trough %i, is: %li\n", x, i);

    }
   
}