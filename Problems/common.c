#include <stdio.h>  
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>


void printProblemNumber(char fileName[], char* problemName)
{
    bool found = false;
    int i = 0;
    while(!found)
    {
        if(fileName[i] == '.')
        {
            found = true;
            i--;
        }
        else 
        {
            i++;
        }
    }
    
    int problemNumber = 0;
    for(int j = 0; j <= i; j++)
    {
        problemNumber = problemNumber + (pow(10, (i - j)) *  (fileName[j] - '0'));
        // printf("i = %i, j = %i, fileName[%i] = %c, problemNumber = %i \n", i, j, j, fileName[j], problemNumber);
    }

    printf("Problem number %i: %s\n", problemNumber, problemName);
}


unsigned long calcTotalDivisors(unsigned long n)
{
    int Sn = sqrt(n);
    // printf("sqrt(%li) = %i. And %li has the following divisors: ", n, Sn, n);
    // int* arr = (int*)malloc((Sn - 1) * sizeof(int));
    // for (int j = 0; j <= Sn - 2; j++)
    // {
    //     printf("%i, ", arr[j]);
    // }
    // printf("\n");

    int count = 0;
    for (int i = 1; i <= Sn; i++)
    {
        if(!(n % i))
        {
            // arr[count] = i;
            if(i != Sn)
            {
                // arr[Sn - 2 - count] = (int)(n/i);
                count += 2;
            }
            else 
            {
                count ++;
            }

            
            // printf("i = %i and n/i = %i; ", i, (int)(n/i));

        }
    }

    // printf("\nDivisors: ");
    // for (int j = 0; j <= Sn - 2; j++)
    // {
    //     printf("%i, ", arr[j]);
    // }

    // printf("\n");
    // free(arr);
    
    return count;

}