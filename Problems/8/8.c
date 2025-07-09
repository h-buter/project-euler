// https://projecteuler.net/problem=8
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

#define PATH "./Problems/8/problemInput.txt"

#define numberSize 1000
#define adjacentDigits 13

FILE* getFile();
void storeNumbers(int* p, int size, FILE* file);
unsigned long  checkLargestProduct(int* p, int productSize, int size);

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Largest Product in a Series");
    
    FILE* file = getFile(); // Read in the file

    int array[numberSize] = { 0 };
    storeNumbers(array, numberSize, file); //Store the numbers of the file in a array

    unsigned long  product = checkLargestProduct(array, adjacentDigits, numberSize); // Check the largest product of x adjacent digits in the array

    printf("product %li: ", product);

    
    fclose(file); // Closing the file
    return 0;
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
    char ch;
    int i = 0;
    while (i < size)
    {
        ch = fgetc(file);
        // printf("%c", ch);

        if(ch != EOF) // Check if end of file is reached
        {
            if (ch != '\n') // Do not count end of line characters
            {
                p[i] = ch - '0'; // Convert char to int by removing ASCII 0 from it
                i++;
            }
        }
    } 
}


unsigned long checkLargestProduct(int* p, int productSize, int size) // Calculate all the x adjacent digits in a given array and return the largest product
{
    unsigned long  currentProduct = 0;
    unsigned long  currentLargestProduct = 0;
    for(int i = 0; i < size - productSize; i++) // Loop over the whole array
    {
        printf("Currently multiplying digit %i trough %i: ", i, i + productSize);
        currentProduct = p[i];
        for(int j = i + 1; j < i + productSize; j++) // Calculate the product of the current x digits
        {
            printf("%i", p[j]);
            currentProduct = currentProduct * p[j];
        }
        printf(", product: %li\n", currentProduct);
        if (currentProduct > currentLargestProduct) // Check if the current product is larger then the current largest product
        {
            currentLargestProduct = currentProduct;
        }
    }
    return currentLargestProduct;
}
