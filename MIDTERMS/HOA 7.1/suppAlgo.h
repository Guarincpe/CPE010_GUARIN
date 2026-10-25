#ifndef SUPPALGO_H
#define SUPPALGO_H

#include <cstddef>

template <typename T>
int findSmallest(T arr[], int start, int size)
{
    int smallest = start;

    for (int i = start + 1; i < size; i++)
    {
        if (arr[i] < arr[smallest])
        {
            smallest = i;
        }
    }

    return smallest;
}

template <typename T>
void selectionSort(T arr[], size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallestIndex = findSmallest(arr, i, size);

        T holder = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = holder;
    }
}

#endif