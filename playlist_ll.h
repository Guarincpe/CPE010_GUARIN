#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class CircularList
{
public:
    T data;
    CircularList<T> *next;
    CircularList<T> *prev;
};

// Create a new node
template <typename T>
CircularList<T> *CreateNewNode(T newData)
{

    CircularList<T> *newNode = new CircularList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

// Display all songs once
template <typename T>
void play_All(CircularList<T> *head)
{

    if (head == nullptr)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    CircularList<T> *curr = head;

    cout << "\nPlaylist:\n";

    do
    {

        cout << curr->data << endl;
        curr = curr->next;

    } while (curr != head);
}

// Insert at beginning
template <typename T>
void insert_Head(T newData, CircularList<T> **head)
{

    CircularList<T> *newNode = CreateNewNode(newData);

    if (*head == nullptr)
    {

        newNode->next = newNode;
        newNode->prev = newNode;

        *head = newNode;
        return;
    }

    CircularList<T> *last = (*head)->prev;

    newNode->next = *head;
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;

    *head = newNode;
}

// Insert at end
template <typename T>
void insert_End(T newData, CircularList<T> **head)
{

    if (*head == nullptr)
    {

        insert_Head(newData, head);
        return;
    }

    CircularList<T> *newNode = CreateNewNode(newData);

    CircularList<T> *last = (*head)->prev;

    newNode->next = *head;
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;
}

// Next song
template <typename T>
void next_Song(CircularList<T> **current)
{

    if (*current == nullptr)
        return;

    *current = (*current)->next;
}

// Previous song
template <typename T>
void prev_Song(CircularList<T> **current)
{

    if (*current == nullptr)
        return;

    *current = (*current)->prev;
}

// Display current song
template <typename T>
void display_Current(CircularList<T> *current)
{

    if (current == nullptr)
    {

        cout << "No song playing." << endl;
        return;
    }

    cout << "Now Playing: " << current->data << endl;
}

// Delete a song
template <typename T>
void delete_Node(T song,
                 CircularList<T> **head,
                 CircularList<T> **current)
{

    if (*head == nullptr)
    {

        cout << "Playlist is empty." << endl;
        return;
    }

    CircularList<T> *curr = *head;

    do
    {

        if (curr->data == song)
            break;

        curr = curr->next;

    } while (curr != *head);

    if (curr->data != song)
    {

        cout << "Song not found." << endl;
        return;
    }

    // only one song
    if (curr->next == curr)
    {

        delete curr;

        *head = nullptr;
        *current = nullptr;

        return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    if (curr == *head)
        *head = curr->next;

    if (*current == curr)
        *current = curr->next;

    delete curr;

    cout << "Song removed." << endl;
}

// Delete the whole playlist
template <typename T>
void destroy_List(CircularList<T> **head)
{

    if (*head == nullptr)
        return;

    CircularList<T> *curr = (*head)->next;

    while (curr != *head)
    {

        CircularList<T> *temp = curr;
        curr = curr->next;

        delete temp;
    }

    delete *head;
    *head = nullptr;
}

#endif