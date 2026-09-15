#include "main.ih"

//returns a pivot in which everything before the pivot in the array is less
//than the pivot and everything after is more than it
size_t partition(string (&array)[maxEntries], size_t left, size_t right)
{
    size_t pivot = left;                //pivot starts at leftmost element
    ++left;                             //check next element

    while (left != right)               //compare until left element equals right
    {
                                        //if array left belongs after pivot it is
                                        //swapped to be there
        if (caseInsensitiveLess(array[pivot], array[left]))
        {
            --right;
            swap(array[left], array[right]);
        }                   
        else                            //If it belongs before the pivot it is
                                        //swapped to be there
        {
            swap(array[left], array[pivot]);
            pivot = left;               //pivot's new position is where left was
            ++left;
        }
    }
    return pivot;
}
