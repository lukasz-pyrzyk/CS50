/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"
#define COUNT 65536

/**
 * Returns true if value is in array of n values, else false.
 * Using binary search
 */
bool search(int value, int values[], int n)
{
    if (n < 1) return false;

    int lindex = 0;
    int rindex = n - 1;

    while (lindex <= rindex)
    {
        int m = lindex + (rindex - lindex)/2;
        int current = values[m];
        if (value < current)
        {
            rindex = m - 1;
        }
        else if (value > current)
        {
            lindex = m + 1;
        }
        else 
        {
            return true;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values using Insertion Sort
 */
void sort(int values[], int n)
{
    int sorted[COUNT];

    // clear array
    for (int i = 0; i < COUNT; i++)
    {
        sorted[i] = 0;
    }

    // write values into temp array, if there is a duplicate. Value of the temp array is a number of duplicates
    for (int i = 0; i < n; i++)
    {
        int number = values[i];
        sorted[number]++;
    }

    // rewrite temp array into correct array. If there is a duplicate, write value few times
    int index = 0;
    for (int i = 0; i < COUNT; i++)
    {
        int times = sorted[i];
        for (int j = 0; j < times; j++)
        {
            values[index++] = i;
        }
    }
}