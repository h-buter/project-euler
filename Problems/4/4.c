// https://projecteuler.net/problem=4
#include <stdio.h>  
#include "../common.h"
#include <stdbool.h>

const int startNumber = 1000;
const int endNumber = 9999;
int palindrome = 0;
int objectA = 0;
int objectB = 0;

bool checkPalindrome(int product);
int getNumberLength(int product);
void extractDigits(int product, int arr[]);

int main() 
{  
    printProblemNumber(__FILE_NAME__,   "Largest Palindrome Product");

    int product = 0;
    for(int i = startNumber; i <= endNumber; i++) //Nested for loop to try all two 3 digit products
    {
        for(int j = startNumber; j <= endNumber; j++)
        {
            product = i * j;
            if(checkPalindrome(product))
            {
                
                if (product >= palindrome) //Check if the current palindrome is larger than de previous stored palindrome
                {
                    printf("Current largest palindrome: %i\n", product);
                    palindrome = product;
                    objectA = i;
                    objectB = j;
                }
            }
        }
    }

    printf("Largest palindrome: %i, is the product of: %i * %i \n", palindrome, objectA, objectB);
}

int getNumberLength(int product)
{
    int count = 0;

    while(product != 0) // Divide the number by 10 until the number reaches 0 and count each division. For example: 100 / 10 / 10 = 0, 2 divisions, 999 / 10 = 99, 99 / 10 = 9, 9/10 = 0, so 3 divisions. This works because of integer rounding.
    {
        count++;
        product = product / 10;
    }
    return count;
}

void extractDigits(int product, int arr[])
{
    int length = getNumberLength(product);
    for (int i = 0; i < length; i++)
    {
        arr[length - 1 - i] = product % 10; //Stores the remainder of the division by 10 in the right most place in the array. For example 99 / 10 = 9.9, so remainder is 9, store this as the first digit.
        product = product / 10; //Divide the product by 10 to get the number minus i digit
    }
}

bool checkPalindrome(int product)
{
    int length = getNumberLength(product);
    if(length <= 1) //Single digit number is always a palindrome
    {
        return true;
    }

    int arr[length] = {};
    extractDigits(product, arr);

    int count = 0;
    for (int i = 0; i < length / 2; i++)
    {
        if(arr[i] == arr[length - 1 - i]) // Check if digit L+i is equal to R-1
        {
            count++; //Count similar digits
            if(count == length / 2) //If the amount of similar digits is equal to half (second half is the same comparison as first half) the length than it is a palindrome
            {
                return true; //Found palindrome
            }
        }
        else {
            return false;
        }
    }
    return false;
}