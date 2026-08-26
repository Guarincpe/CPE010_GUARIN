#include <iostream>
#include "queueArr.h"

int main()
{
    // creating an object
    queueArr<int> q(5);

    std::cout << "=============================\n";
    std::cout << "      QUEUE ARRAY TEST\n";
    std::cout << "=============================\n";

    // enqueue 10, 20, 30, 40, 50:
    q.enqueue(1);

    std::cout << "\n--- After Enqueue 1 ---\n";
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back : " << q.Back() << std::endl;
    std::cout << "Size : " << q.Size() << std::endl;

    q.enqueue(2);

    std::cout << "\n--- After Enqueue 2 ---\n";
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back : " << q.Back() << std::endl;
    std::cout << "Size : " << q.Size() << std::endl;

    q.enqueue(3);

    q.enqueue(4);

    std::cout << "\n--- After Enqueue 3 and 4 ---\n";
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back : " << q.Back() << std::endl;
    std::cout << "Size : " << q.Size() << std::endl;

    q.enqueue(5);

    std::cout << "\n--- After Enqueue 5 ---\n";
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back : " << q.Back() << std::endl;
    std::cout << "Size : " << q.Size() << std::endl;

    std::cout << "Is the queue full? "
              << (q.Full() ? "Yes" : "No")
              << std::endl;

    std::cout << "\n--- Dequeue Operation ---\n";
    std::cout << "Removed: " << q.dequeue() << std::endl;
    std::cout << "Removed: " << q.dequeue() << std::endl;

    // testing the clear
    std::cout << "\n--- Clearing Queue ---\n";
    q.Clear();

    std::cout << "Is the queue empty? "
              << (q.Empty() ? "Yes" : "No")
              << std::endl;

    return 0;
}