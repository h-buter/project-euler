// https://projecteuler.net/problem=11
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

#define PATH "./Problems/11/problemInput.txt"

#define nDigits 2
#define numberSize 20 * 20
#define adjacentNumbers 4

FILE* getFile();
void storeNumbers(int* p, int size, FILE* file);
void storeBiggest(int x, int* p);

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Summation of Primes");

    FILE* file = getFile(); // Read in the file

    int array[numberSize] = { 0 };
    storeNumbers(array, numberSize, file); //Store the numbers of the file in a array

    // printf("\n\n\n\n\n\n");

    // for(int x = 0; x < numberSize; x++)
    // {
    //     printf("%i ", array[x]);
    // }

    int biggest = 0;


    //Horizontal search
    for(int i = 0; i < numberSize - adjacentNumbers; i++)
    {
        int x = array[i];
        for(int j = 0; j < adjacentNumbers - 1; j++)
        {
            x *= array[i + 1 + j];
        }

        storeBiggest(x, &biggest);

    }

    //Vertical search
    for(int i = 0; i < numberSize - adjacentNumbers; i++)
    {
        int x = array[i];
        for(int j = 0; j < adjacentNumbers - 1; j++)
        {
            x *= array[i + 1 + j];
        }

        storeBiggest(x, &biggest);

    }


    printf("\n");
}


FILE* getFile()
{
    FILE *p;
    // Opening file in reading mode
    p = fopen(PATH, "r");

    if (NULL == p) // Check if file exists
    {
        printf("file can't be opened \n");
    }
    return p;
}

void storeNumbers(int* p, int size, FILE* file)
{
    bool done = 0;
    char ch[nDigits] = {0};
    int count = 0;
    while(!done)
    {
        for(int i = 0; i < nDigits; i++)
        {
            ch[i] = fgetc(file);
            if(ch[i] == EOF)
            {
                done = 1;
            }
        }
        if(!done)
        {
            fgetc(file); //Read space or end of line
            int currentNumber = (ch[0] - '0') * 10 + (ch[1] - '0');
            printf ("%i ", currentNumber);

            p[count] = currentNumber;
            count++;
        }
    }
}

void storeBiggest(int x, int* p)
{
    // printf("comparing %i, %i\n", x, *p);
    if(x > *p)
    {
        printf("New largest: %i\n", x);
        *p = x;
    }
}