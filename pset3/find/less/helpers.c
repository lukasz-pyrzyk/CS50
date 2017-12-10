/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

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
            lindex = m + 1;
        }
        else if (value > current)
        {
            rindex = m - 1;
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
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while(j - 1 >= 0 && values[j] < values[j - 1])
        {
            int current = values[j];
            values[j] = values[j - 1];
            values[j - 1] = current;
            j--;
        }
    }
}
