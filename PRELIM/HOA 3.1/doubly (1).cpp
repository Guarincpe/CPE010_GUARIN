#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main (){
    //creating a lisy ' C P E'

    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head -> next = second;
    second -> prev = head;

    second -> next = third;
    third -> prev = second;

    //traversal
    std::cout <<"Testing the DLL Traversal"<<std:: endl;
    dllTraverse(head);

    //testing the insertion at the head
    std::cout << "\nTesting the insertion at the head node"<<std:: endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    //testing the insertion at the end
    std::cout << "\nTesting the insertion at the end" <<std:: endl;
    dllInsertEnd('0', head);
    dllTraverse(head);


    //General Insert
    std::cout << "\nTesting the general insertion" <<std:: endl;
    dllGeneralInsert('Z', second);
    dllTraverse(head);
    
    //Deleting a NOde
    std::cout <<"\nTesting the deletion of a node" <<std:: endl;
    dllDeleteNode('Z', &head);
    dllDeleteNode('X', &head);
    dllDeleteNode('0', &head);
    dllTraverse(head);
}