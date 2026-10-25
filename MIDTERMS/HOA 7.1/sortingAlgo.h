#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <cstddef>
#include <iostream>

template <typename T>
void bubbleSort(T arr[], size_t arrSize)
{
    // step1: for i = 0 to N-1 repeat inner loop
    for (int i = 0; i < arrSize - 1; i++)
    {
        // step 2 inner loop that for k = i+1 to N-1 repeat step 3
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            // step 3 swap if the arr [j] > arr[j+1]
            if (arr[j] > arr[j + 1])
            {
                // swap
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
// array, current position, size of array
int routineSmallest(T arr[], int K, const int arrSize)
{
    int position = K;
    T smallestElem = arr[K];

    for (int j = K + 1; j < arrSize; j++)
    {
        if (arr[j] < smallestElem)
        {
            smallestElem = arr[j];
            position = j;
        }
    }

    return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize)
{
    int POS;

    for (int i = 0; i < arrSize - 1; i++)
    {
        POS = routineSmallest(arr, i, arrSize);

        // swapping
        T temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

template <typename T>
void insertionSort(T arr[], size_t arrSize)
{
    int K = 1, J;
    T temp;

    while (K < arrSize)
    {
        temp = arr[K];
        J = K - 1;

        while (J >= 0 && temp <= arr[J])
        {
            arr[J + 1] = arr[J];
            J--;
        }

        arr[J + 1] = temp;
        K++;
    }
}
#endif