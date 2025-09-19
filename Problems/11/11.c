// https://projecteuler.net/problem=11
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

#define PATH "./Problems/11/problemInput.txt"

#define nDigits 2
#define gridX 20
#define gridY 20
#define adjacentNumbers 4

#define horz
#define vert
#define diagLeft
#define diagRight

FILE* getFile();
void storeNumbers(int p[gridX][gridY], int size, FILE* file);
void storeBiggest(int x, int* p);

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Summation of Primes");

    FILE* file = getFile(); // Read in the file

    int array[gridX][gridY] = { 0 };
    storeNumbers(array, gridX, file); //Store the numbers of the file in a array

    printf("\n\n\n");

    int biggest = 0;

    //Horizontal search
    #ifdef horz
    printf("horizontally\n");
        for(int y = 0; y < gridY; y++)
        {
            for(int x = 0; x < gridX - adjacentNumbers; x++)
            {
                unsigned long product = 1;
                for(int i = 0; i < adjacentNumbers; i++)
                {
                    product *= array[x + i][y];
                    // printf("[%i,%i]=%i * ", x + i, y, array[x+i][y]);
                }
                // printf(", p: %li \n", product);
                storeBiggest(product, &biggest);
            }
        }
    #endif

    //Vertical search
    #ifdef vert
    printf("Vertically\n");
    for(int x = 0; x < gridX; x++)
    {
        for(int y = 0; y < gridY - adjacentNumbers; y++)
        {
            unsigned long product = 1;
            for(int i = 0; i < adjacentNumbers; i++)
            {
                product *= array[x][y + i];
                // printf("[%i,%i]=%i * ", x, y + i, array[x][y + i]);
            }
            // printf(", p: %li \n", product);
            storeBiggest(product, &biggest);
        }
    }
    #endif

    //Diagonally to the left search
    #ifdef diagLeft
    printf("Diagonally to the left\n");
    for(int y = 0; y < gridY - adjacentNumbers + 1; y++)
    {
        for(int x = 0; x < gridX - adjacentNumbers + 1; x++)
        {
            unsigned long product = 1;
            for(int i = 0; i < adjacentNumbers; i++)
            {
                product *= array[x + i][y + i];
                // printf("[%i,%i]=%i * ", x + i, y + i, array[x + i][y + i]);
            }
            // printf(", p: %li \n", product);
            storeBiggest(product, &biggest);
        }
    }
    #endif

    //Diagonally to the right search
    #ifdef diagRight
    printf("Diagonally to the right\n");
    for(int y = 0; y < gridY - adjacentNumbers + 1; y++)
    {
        for(int x = gridX - 1; x - adjacentNumbers + 1 >= 0; x--)
        {
            unsigned long product = 1;
            for(int i = 0; i < adjacentNumbers; i++)
            {
                product *= array[x - i][y + i];
                // printf("[%i,%i]=%i * ", x - i, y + i, array[x - i][y + i]);
            }
            // printf(", p: %li \n", product);
            storeBiggest(product, &biggest);
        }
    }
    #endif


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

void storeNumbers(int p[gridX][gridY], int size, FILE* file)
{
    bool done = 0;
    char ch[nDigits] = {0};
    int x = 0;
    int y = 0;
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

            p[x][y] = currentNumber;
            x++;
            if(x >= gridX)
            {
                x = 0;
                y++;
            }
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