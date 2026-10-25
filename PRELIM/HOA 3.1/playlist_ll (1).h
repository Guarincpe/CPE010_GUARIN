#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H
#include <iostream>
#include <string> 

template<typename T>
class CircularList{
    public: 
        T data;
        CircularList<T>*next = nullptr;
        CircularList<T>*prev = nullptr;
};  

template<typename T>
CircularList<T>* CreateNewNode(T newData){
 
    CircularList<T> *newNode = new CircularList<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

template<typename T>
void play_All(CircularList<T>* head){
    if(head == nullptr){
        std::cout<<"The playlist is empty." << std::endl;
        return;
    }
    CircularList<T>* currentNode = head;
    do{
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }while(currentNode != head);
    std::cout << std::endl;
}

template<typename T>
void insert_Head(T newData, CircularList<T>** currentHead){
    CircularList<T>* newNode = CreateNewNode(newData);

    if(*currentHead == nullptr){
    newNode->next = newNode;
    newNode->prev = newNode;
    *currentHead = newNode;
    // empty list into adding the first and only song
    return;
    }else{
        newNode->next = *currentHead; // Song D's next -> Song A
        newNode->prev = (*currentHead)->prev; // Song D's prev -> Song C
        newNode->prev->next = newNode; // Song C's next -> Song D (was previously pointing to Song A)
    (*currentHead)->prev = newNode; //Song A's prev -> Song D (was previously pointing to Song C)
    *currentHead = newNode; // head label -> Song D

    }
}

template<typename T>
void insert_End(T newData, CircularList<T>* currentHead){
    CircularList<T>* newNode = CreateNewNode(newData);
    //List is already circular so head ->prev is last node.
    //No need for a traversal loop due to the shortcut of lastNode = currentHead->prev;
    CircularList<T>* lastNode = currentHead->prev;
    newNode->prev = lastNode;
    newNode->next = currentHead;
    lastNode->next = newNode;
    currentHead->prev = newNode;
}

template<typename T>
void next_Song(CircularList<T>** songPlaying){ 
    *songPlaying = (*songPlaying)->next; 
    // move forward one song
}

template<typename T>
void prev_Song(CircularList<T>** songPlaying){
    *songPlaying = (*songPlaying)->prev;
    // move backward one song
}
// To easily show the state of playlist.
template<typename T>
void display_Current(CircularList<T>* songPlaying){
    if(songPlaying == nullptr){
        std::cout<<"There is currently no song playing." <<std::endl;
        return;
    }
    std::cout<<songPlaying->data;
    std::cout<<std::endl;
}

template<typename T>
void delete_Node(T findData, CircularList<T>** head, CircularList<T>** songPlaying){
    if(*head == nullptr){
        std::cout << "The playlist is empty." <<std::endl;
        return;
    }
    // search the circle for a node matching findData
    CircularList<T>* currNode = *head;
    do{
        if(currNode->data == findData) break;
        currNode = currNode->next;
    }while(currNode != *head);
    // loop ends without break; just going back to head
    if(currNode->data != findData){
        std::cout << "Song not found in the playlist." <<std::endl;
        return;
    }
    // When currNode is pointing to itself 
    if(currNode->next == currNode){
        *head = nullptr;
        *songPlaying = nullptr;
        delete currNode;
        return;
    }
    // If currNode is in the head, but other nodes still exist
    if(currNode == *head){
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
        *head = currNode->next;
        if(*songPlaying == currNode){
            *songPlaying = currNode->next;
            
        }
        delete currNode;
        return;
    // If currNode is in the middle or a different node, head will stay the same
    }else{
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
        if(*songPlaying == currNode){
            *songPlaying = currNode->next;
        }
        delete currNode;
    }
}

template<typename T>
void destroy_List(CircularList<T>** head){
    if(*head == nullptr);

    CircularList<T>* currNode = *head;
    do{
        //save in a temp before deleting since currNode->next would be undefined after deletion.
        CircularList<T>* temp = currNode;
        currNode = currNode->next;
        delete temp;

    } while(currNode != *head);

    *head = nullptr;
}

#endif 