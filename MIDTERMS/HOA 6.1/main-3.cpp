#include <iostream>
// include <cstdlib> // for generating random integers
// include <time.h>  //will be used for our seeding function
#include "SearchingAlgo.h"
#include "node.h"
const int max_size = 10;

int main()
{
    int myList[max_size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    binarySearchRec(myList, 0, max_size - 1, 8);

    return 0;
}

// int dataset[max_size];
// srand(time(0));
// for(int i = 0; i <max_size; i++){
// dataset[i] = rand();
// std::cout<<dataset[i] << " ";
//}
// std::cout<<std::endl;

// std::cout<<"What number to find: ";
// int choice;
// std::cin >> choice;

// linearSearchAR(max_size, choice, dataset);

// Creating a node for your name
// Node<char> *char1 = new_node('M');
// Node<char> *char2 = new_node('I');
// Node<char> *char3 = new_node('K');
// Node<char> *char4 = new_node('A');
// Node<char> *char5 = new_node('E');
// Node<char> *char6 = new_node('L');
// Node<char> *char7 = new_node('A');

// char1->next = char2;
// char2->next = char3;
// char3->next = char4;
// char4->next = char5;
// char5->next = char6;
// char6->next = char7;

// linearSearchLL(char1, 'K');

// // generate a sorted array: (use for loop)
// int newArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// for (int i = 0; i < max_size; i++)
// {
//     newArr[i] = i;
// }

// binarySearchArr(newArr, max_size, 100);

// Node<char> *char1 = new_node('M');
// Node<char> *char2 = new_node('I');
// Node<char> *char3 = new_node('K');
// Node<char> *char4 = new_node('A');
// Node<char> *char5 = new_node('E');
// Node<char> *char6 = new_node('L');
// Node<char> *char7 = new_node('A');

// // Connect the nodes
// char1->next = char2;
// char2->next = char3;
// char3->next = char4;
// char4->next = char5;
// char5->next = char6;
// char6->next = char7;

// binarySearchLL(char1, 18);