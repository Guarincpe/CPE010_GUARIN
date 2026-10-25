#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main()
{
    // create an array with unsorted list with 100 maximum size
    int unsortedArr[maxSize];

    // use time(0) as seed for random values
    srand(time(0));

    // populate the array with random values
    for (int i = 0; i < maxSize; i++)
    {
        unsortedArr[i] = rand() % 100;
    }

    // display the randomly generated array
    std::cout << "unsortedArr: \n";
    displayArr(unsortedArr);

    // bubble sort
    // std::cout << "\nbubble sort: \n";
    // bubbleSort(unsortedArr, maxSize);
    // displayArr(unsortedArr);

    // selection sort
    // std::cout << "\nselection sort : \n ";
    // selectionSort(unsortedArr, maxSize);
    // displayArr(unsortedArr);

    // insertion sort
    std::cout << "\nInsertion Sort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    return 0;
}

void displayArr(int arr[])
{
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}