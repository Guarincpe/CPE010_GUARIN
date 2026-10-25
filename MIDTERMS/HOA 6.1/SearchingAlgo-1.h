#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

// template <typename T>
// void linearSearchAR(int size, T dataFind, T array[])
// {
// int i = 0;
// while (i < size)
//{
// if (dataFind == array[i]) {
// std::cout << "Searching is successful\n";
// return; }
// i++;
//}
// std::cout << "Searching is unsuccessful\n";

// for (int j = 0; j < size; j++) {
// if (dataFind == array[j]) {
// std::cout << "Searching is successful\n";
// return;
//}
//}
// std::cout << "Searching is unsuccessful\n";
//}

// ------PROBLEM1-----
// template <typename T>
// void linearSearchAR(int size, T dataFind, T array[])
// {
//     int i = 0;
//     int comparisons = 0;

//     while (i < size)
//     {
//         comparisons++;

//         std::cout << "Comparisons made: "
//                   << comparisons << "\n";

//         if (dataFind == array[i])
//         {
//             std::cout << "Search successful\n";
//             std::cout << "Total comparisons: "
//                       << comparisons << "\n";
//             return;
//         }

//         i++;
//     }

//     std::cout << "Search unsuccessful\n";
// }

// ------PROBLEM2-----
// template <typename T>
// void linearSearchAR(int size, T dataFind, T array[])
// {
//     int count = 0;

//     for (int i = 0; i < size; i++)
//     {
//         if (array[i] == dataFind)
//         {
//             count++;
//         }
//     }

//     std::cout << "The same element found: "
//               << count << "\n";
// }

//----PROBLEM3-------
template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind)
{
    int low = 0;
    int high = arrSize - 1;
    int middle;

    while (low <= high)
    {
        middle = low + (high - low) / 2;

        std::cout << "Middle index: " << middle
                  << ", element: " << data[middle]
                  << "\n";

        if (dataFind == data[middle])
        {
            std::cout << "The data was found\n";
            return;
        }

        else if (dataFind < data[middle])
        {
            std::cout << "Searching left half\n\n";
            high = middle - 1;
        }

        else
        {
            std::cout << "Searching right half\n\n";
            low = middle + 1;
        }
    }

    std::cout << "The data was not found\n";
}

// template <typename T>
// void linearSearchLL(Node<T> *nodes, T dataFind)
// {
//     while (nodes != nullptr)
//     {
//         if (nodes->data == dataFind)
//         {
//             std::cout << "The data: " << nodes->data
//                       << " was Found successfully.\n";
//             return;
//         }

//         nodes = nodes->next;
//     }

//     std::cout << "Searching is unsuccessful.\n";
// }

// ------PROBLEM1----
// template <typename T>
// void linearSearchLL(Node<T> *nodes, T dataFind)
// {
//     int comparisons = 0;

//     while (nodes != nullptr)
//     {
//         comparisons++;

//         std::cout << "Comparisons made: "
//                   << comparisons << "\n";

//         if (nodes->data == dataFind)
//         {
//             std::cout << "Search successful\n";
//             std::cout << "Total comparisons: "
//                       << comparisons << "\n";
//             return;
//         }

//         nodes = nodes->next;
//     }

//     std::cout << "Search unsuccessful\n";
// }

// ------PROBLEM2-----
template <typename T>
void linearSearchLL(Node<T> *headNode, T dataFind)
{
    int count = 0;

    while (headNode != nullptr)
    {
        if (headNode->data == dataFind)
        {
            count++;
        }

        headNode = headNode->next;
    }

    std::cout << "The same element found: "
              << count << "\n";
}

// template <typename T>
// void binarySearchArr(T data[], int arrSize, T dataFind)
// {
//     int low = 0, high = arrSize - 1, middle;
//     while (low <= high)
//     {
//         middle = low + (high - low) / 2;
//         if (dataFind == data[middle])
//         {
//             std::cout << "The data was found\n";
//             return;
//         }
//         else if (dataFind < data[middle])
//         {
//             high = middle - 1;
//         }
//         else
//         {
//             low = middle + 1;
//         }
//     }

//     std::cout << "The data was not found\n";
// }

template <typename T>
Node<T> *getMiddle(Node<T> *start, Node<T> *last)
{
    Node<T> *slow = start;
    Node<T> *fast = start;

    while (fast != last && fast->next != last)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T> *start, T dataFind)
{
    Node<T> *last = nullptr;

    while (start != last)
    {
        Node<T> *middle = getMiddle(start, last);

        if (middle->data == dataFind)
        {
            std::cout << "searching is Successfull\n";
            return;
        }
        else if (middle->data > dataFind)
        {
            last = middle;
        }
        else
        {
            start = middle->next;
        }
    }

    std::cout << "Searching is unsuccessful\n";
}

template <typename T>
void binarySearchRec(T arr[], int low, int high, T dataFind)
{
    if (low <= high)
    {
        int middle = (low + high) / 2;

        if (arr[middle] == dataFind)
        {
            std::cout << "Data found at index: "
                      << middle << "\n";
            return;
        }

        else if (dataFind < arr[middle])
        {
            binarySearchRec(arr, low, middle - 1, dataFind);
        }

        else
        {
            binarySearchRec(arr, middle + 1, high, dataFind);
        }
    }

    else
    {
        std::cout << "Data not found\n";
    }
}

#endif