// https://projecteuler.net/problem=13
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>
#include <math.h>  

#define PATH "./Problems/13/problemInput.txt"

#define numberSize 5000
#define digitsIndividualNumbers 50

FILE* getFile();
// unsigned long countCharactersInFile(FILE* file);
void storeNumbers(int p[][digitsIndividualNumbers], int size, FILE* file);

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Largest Product in a Series");
    
    FILE* file = getFile(); // Read in the file

    // unsigned long totalNumbers = countCharactersInFile(file);
    // printf("\nFile contains %li numbers\n", totalNumbers);

    int array[numberSize/digitsIndividualNumbers][digitsIndividualNumbers];// = { 0 };
    storeNumbers(array, numberSize, file); //Store the numbers of the file in a array

    printf("End of store numbers\n");
    for (int j = 0; j < 1; j++)
    {
        unsigned long rowSum = 0;
        for (int i = 0; i < digitsIndividualNumbers; i++)
        {
            printf("a[%i] * 10^%i = %i * 10^%i = %li \n", i, digitsIndividualNumbers-i, array[j][i], digitsIndividualNumbers-i, (array[j][i] * (unsigned long)pow(10, digitsIndividualNumbers-i)));
            rowSum += array[j][i] * pow(10, digitsIndividualNumbers-i);
        }
        printf("row sum of row %i = %li", j, rowSum);
        printf("\n");
    }
    
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


void storeNumbers(int p[][digitsIndividualNumbers], int size, FILE* file)
{
    char ch;
    int i = 0;
    int j = 0;
    bool endReached = false;
    while (!endReached)
    {
        ch = fgetc(file);
        // printf("%c", ch);

        if(ch != EOF) // Check if end of file is reached
        {
            if (ch != '\n') // Do not count end of line characters
            {
                p[j][i]= ch - '0'; // Convert char to int by removing ASCII 0 from it
                i++; //increment columns
            }
            else 
            {
                i = 0;
                j++; //increment row
            }
        }
        else 
        {
            endReached = true;
        }
    } 
}

// unsigned long countCharactersInFile(FILE* file)
// {
//     char ch;
//     bool endOfFile = false;
//     unsigned long characterCount = 0;
//     while (!endOfFile)
//     {
//         ch = fgetc(file);
//         if(ch != EOF) // Check if end of file is reached
//         {
//             // printf("%c", ch);
//             if (ch != '\n' && ch != EOF) // Do not count end of line characters
//             {
//                 characterCount++;
//             }
//         }
//         else 
//         {
//             endOfFile = true;
//         }
//     } 
//     return characterCount;
// }