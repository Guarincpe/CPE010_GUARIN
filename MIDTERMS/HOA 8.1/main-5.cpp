#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo2.h"

const int arrSize = 100;

void displayArr(int Arr[]);
int main()
{

    // seede the random number generator once for the whole program
    srand(time(0));

    // Array 1: Shell Sort

    int shellArr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        shellArr[i] = rand() % 1000;
    }

    std::cout << "Array 1 - Unsorted:\n";
    displayArr(shellArr);

    shellSort(shellArr, arrSize);
    std::cout << "\nArray 1 - Sorted using Shell Sort:\n";
    displayArr(shellArr);

    // Array 2: Merge Sort

    int mergeArr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        mergeArr[i] = rand() % 1000;
    }

    std::cout << "\n\nArray 2 - Unsorted:\n";
    displayArr(mergeArr);

    merge_sort(mergeArr, 0, arrSize - 1);

    std::cout << "\nArray 2 - Sorted using Merge Sort:\n";
    displayArr(mergeArr);

    // Array 3: Quick Sort

    int quickArr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        quickArr[i] = rand() % 1000;
    }

    std::cout << "\n\nArray 3 - Unsorted:\n";
    displayArr(quickArr);

    quicksort(quickArr, 0, arrSize - 1);

    std::cout << "\nArray 3 - Sorted using Quick Sort:\n";
    displayArr(quickArr);

    return 0;
}

void displayArr(int arr[])
{
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
        if ((i % 10) == 9)
        {
            std::cout << '\n';
        }
    }
}