#ifndef PRINTER_H
#define PRINTER_H

#include "Job.h"

class Node
{
public:
    Job data;
    Node *next;

    Node(Job job) : data(job)
    {
        next = NULL;
    }
};

class Printer
{

private:
    Node *front;
    Node *rear;

public:
    Printer()
    {
        front = NULL;
        rear = NULL;
    }

    // Add job into queue
    void addJob(Job job)
    {

        Node *newNode = new Node(job);

        if (front == NULL)
        {
            front = rear = newNode;
        }

        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "\nPrint Job Added Successfully!\n";
    }

    // Display queue
    void viewQueue()
    {

        if (front == NULL)
        {
            cout << "\nPrinter Queue is Empty.\n";
            return;
        }

        Node *current = front;

        int count = 0;

        cout << "\n========== PRINT QUEUE ==========\n";

        while (current != NULL)
        {

            cout << "\nPosition [" << count << "]\n";
            cout << "--------------------------\n";

            current->data.display();

            cout << "--------------------------\n";

            current = current->next;

            count++;
        }

        cout << "================================\n";
    }
};

#endif