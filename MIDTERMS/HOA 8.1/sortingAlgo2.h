#ifndef SORT_ALGO_H
#define SORT_ALGO_H

// ==================
// A.1. SHELL SORT
// ==================
template <typename T>
void shellSort(T array[], int size)
{
    // for interval i <- size/2^n down to 1
    for (int interval = size / 2; interval > 0; interval = interval / 2)
    {

        // for each interval "i" in array
        for (int i = interval; i < size; i++)
        {

            // sort all the elements at interval "i"
            // (this is an insertion-sort style shift using the current interval)
            T temp = array[i];
            int j = i;

            while (j >= interval && array[j - interval] > temp)
            {
                array[j] = array[j - interval];
                j = j - interval;
            }
            array[j] = temp;
        }
    }
}

// ==================
// A.2. MERGE SORT
// ==================

// merge (Arr, left, middle, right) => merges the two sorted halves

template <typename T>
void merge(T arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    T leftArr[100];
    T rightArr[100];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// merge sort(Arr, left, right)
template <typename T>
void merge_sort(T arr[], int left, int right)
{
    int N = right - left + 1;

    // If N=1, Arr is already sorted
    if (N == 1)
    {
        return;
    }

    // If N>1,
    if (N > 1)
    {
        // Find middle = (left + right)/2
        int middle = (left + right) / 2;

        // Call merge_sort(Arr,left,middle) => sort first half recursively
        merge_sort(arr, left, middle);

        // Call merge_sort(Arr,middle+1,right) => sort second half recursively
        merge_sort(arr, middle + 1, right);

        // Call merge(Arr, left, middle, right) to merge sorted arrays in above steps
        merge(arr, left, middle, right);
    }
    // Exit
}

// ==================
// A.3. QUICK SORT
// ==================

// partition(A, low, high)
template <typename T>
int partition(T A[], int low, int high)
{
    T pivotValue = A[high]; // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (A[j] < pivotValue)
        {
            i++;
            T temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    T temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    return i + 1;
}

// quicksort(A, low, high)
template <typename T>
void quicksort(T A[], int low, int high)
{
    // if(low < high)
    if (low < high)
    {
        // pivot = partition(A,low,high);
        int pivot = partition(A, low, high);

        // quicksort(A,low,pivot-1)
        quicksort(A, low, pivot - 1);

        // quicksort(A,pivot+1,high)
        quicksort(A, pivot + 1, high);
    }
}

#endif