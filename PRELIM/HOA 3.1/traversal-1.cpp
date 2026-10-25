#include <iostream>
#include "singly_ll.h"

int main()
{

    // stack
    SingleList<char> *head = nullptr;
    SingleList<char> *second = nullptr;
    SingleList<char> *third = nullptr;
    SingleList<char> *fourth = nullptr;

    // allocates memory in the heap
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;

    // storing value inside the node
    head->data = 'M';
    second->data = 'I';
    third->data = 'K';
    fourth->data = 'A';

    // linking the nodes:
    head->next = second;
    second->next = third;
    third->next = fourth;

    std::cout << "Testing of Traversal: \n";
    ListTraversal(head);

    std::cout << "Testing of sllinsertHead: \n";
    sllinsertHead('J', &head);
    ListTraversal(head);

    std::cout << "Testing of sllGeneralInsert: \n";
    sllGeneralInsert('L', head->next->next);
    ListTraversal(head);

    std::cout << "Testing of sllinsertEnd: \n";
    sllinsertEnd('C', &head);
    ListTraversal(head);

    std::cout << "Testing of deleting the node: \n";
    sllDeleteNode('J', &head);
    ListTraversal(head);
    sllDeleteNode('L', &head);
    ListTraversal(head);
    sllDeleteNode('C', &head);
    ListTraversal(head);

    std::cout << "Deleting all nodes\n";
    sllDeleteList(&head);
    ListTraversal(head);
    return 0;
};
