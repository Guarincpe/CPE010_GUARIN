#include <iostream>

// global declarations
#define maxCap 10

int stackArr[maxCap];
int top = -1, newData;

// prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void display(); 

int main() {
    // main driver
    int choice;

    while (true) {
        std::cout << "\n=====================" << std::endl;
        std::cout << "   Stack operations  " << std::endl;
        std::cout << "=====================" << std::endl;
        std::cout << " 1. Push" << std::endl;
        std::cout << " 2. Pop" << std::endl;
        std::cout << " 3. Top" << std::endl;
        std::cout << " 4. isEmpty" << std::endl;
        std::cout << " 5. isFull" << std::endl;
        std::cout << " 6. Display" << std::endl; // New menu option added
        std::cout << "=====================" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        
        std::cout << "---------------------" << std::endl;

        switch(choice) {
            case 1: 
                push();
                break;
            case 2: 
                pop();
                break;
            case 3: 
                Top();
                break;
            case 4: 
                std::cout << "is stack empty? " << (isEmpty() ? "True" : "False") << std::endl;
                break;
            case 5: 
                std::cout << "is the stack full? " << (isFull() ? "True" : "False") << std::endl;
                break;
            case 6: 
                display(); // New case added
                break;
            default: 
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }
    
    return 0;
}

// function definition

bool isEmpty() {
    // how do we verify if the stack is empty
    if (top == -1) return true;
    return false;
}

bool isFull() {
    // how do we verify if stack is full?
    if (top == maxCap - 1) return true;
    return false;
}

void push() {
    // error checking
    if (isFull()) {
        std::cout << "Stack overflow" << std::endl;
        return;
    }
    
    // pushing to the stack
    std::cout << "Enter a new Value: ";
    std::cin >> newData;
    
    // how do we insert the data into the stack?
    stackArr[++top] = newData;
    std::cout << newData << " pushed to stack." << std::endl;
}

void pop() {
    // error checking
    if (isEmpty()) {
        std::cout << "Stack underflow" << std::endl;
        return;
    }

    // Display the value that we are going to pop:
    std::cout << "Popping: " << stackArr[top] << std::endl;
    
    // Decrement the top value from the stack
    top--;
}

void Top() {
    // error catching:
    if (isEmpty()) {
        std::cout << "The stack is empty" << std::endl;
        return;
    }
    
    // check the top value
    std::cout << "top element: " << stackArr[top] << std::endl;
}

// display function
void display() {
    if (isEmpty()) {
        std::cout << "The stack is empty, nothing to display." << std::endl;
        return;
    }
    
    std::cout << "Stack elements (Top to Bottom):" << std::endl;
    for (int i = top; i >= 0; i--) {
        std::cout << " [ " << stackArr[i] << " ] ";
        if (i == top) {
            std::cout << "<- Top";
        }
        std::cout << std::endl;
    }
}