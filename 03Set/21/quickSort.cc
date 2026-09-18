#include "main.ih"

//quicksort algorith for sorting an array of strings
void quicksort(string (&array)[], size_t left, size_t right)
{
    if (right - left < 1)           //if less then two elements left to sort
        return;
    
                                    //get the pivot index
    size_t pivot = partition(array, left, right);

    quicksort(array, left, pivot);  //recursively run quicksort for both sides
    quicksort(array, pivot + 1, right);
}
