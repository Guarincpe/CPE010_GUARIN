#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;
};


//creating node
template <typename T>
DoubleList<T>* CreateNewNode(T newData){
    //dynamically  allocate a new memory for the node
    DoubleList<T>* newNode = new DoubleList<T>;
    //store the data in the node
    newNode->data = newData;
    //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;
    //return the address of the newly created node
    return newNode;
};


template <typename T>
void dllTraverse(DoubleList<T>* currentNode){

    DoubleList<T>* tail;

    //check if the list is empty
    if (currentNode ==nullptr){
        std::cout << "The list is empty" <<std::endl;
        return; 
    }
    //move forward
    while (currentNode != nullptr){
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    //add a next line
    std::cout << std::endl;
    
    //move backward
    while (tail != nullptr){
        std::cout<<tail->data<<" ";
        tail = tail->prev;
    }
}


template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead){
    //creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    //new node should point to the current head
    newNode->next = *currentHead;

    //current head should point back to the new Node
    (*currentHead)->prev = newNode;

    //update the pointer head
    *currentHead = newNode;
}


template <typename T>
void dllInsertEnd (T newData, DoubleList<T> * currentHead){
    //create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);
    
    //traverse until we reach the last node
    while (currentHead->next != nullptr){
        currentHead = currentHead -> next;
    }
    //connect the last node to the new node
    currentHead -> next = newNode;

    //connect the new node back to the last node
    newNode->prev = currentHead;
    
}

template <typename T> 
void dllGeneralInsert (T newData, DoubleList<T> * prevNode){
    if (prevNode == nullptr){
        std::cout << "Previous node cannot be null"<< std:: endl;
        return;
    }

    DoubleList<T>* newNode = CreateNewNode(newData);

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
}

template <typename T>
void dllDeleteNode (T findData, DoubleList<T> ** currentHead){
    //check if the list is empty
    if (*currentHead == nullptr){

        return;
    }

    DoubleList<T>* currentNode = *currentHead;

    //traverse the list to find the node to delete
    while (currentNode != nullptr && currentNode->data != findData){
        currentNode = currentNode->next;
    }

    //if the node was not found
    if (currentNode == nullptr){
        std::cout << "Data" << findData << " not found." << std::endl;
        return;
    }

    //if the node to delete is the head
    if (*currentHead == currentNode){
        *currentHead = currentNode->next;
    }

    //adjust next node's prev poiner if not deleting tail
    if (currentNode->next != nullptr){
        currentNode->next->prev = currentNode->prev;
    }

    //adjust prev node's next pointer if not deleting head
    if (currentNode->prev != nullptr){
        currentNode->prev->next = currentNode->next;
    }

    //delete the node
    delete currentNode;
}   


#endif

