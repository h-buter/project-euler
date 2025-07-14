#include <stdio.h>  
#include <stdbool.h>
#include <math.h>

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