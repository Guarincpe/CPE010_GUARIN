#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack1;
    std::cout << "====Testing the stack STL=====" << std::endl;
    std::cout << "\n--------- STACK 1 ---------" << std::endl;

    //isEmpty
    std::cout << "is the stack empty? " << stack1.empty() << std::endl;

    //push
    stack1.push(10);
    std::cout << "The top of the stack is:  " << stack1.top() << std::endl;
    stack1.push(9);
    std::cout << "The top of the stack is:  " << stack1.top() << std::endl;
    stack1.push(8);
    std::cout << "The top of the stack is:  " << stack1.top() << std::endl;
    stack1.push(7);
    std::cout << "The top of the stack is:  " << stack1.top() << std::endl;
    stack1.pop();
    std::cout << "The top of the stack is:  " << stack1.top() << std::endl;

    std::cout << "The size of the stack is: " << stack1.size() << std::endl;

    //emplace
    std::stack<int> stack2;
    std::cout << "\n--------- STACK 2 ---------" << std::endl;

    stack2.emplace(10);
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;
    
    stack2.emplace(15);
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;
    
    stack2.emplace(22);
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;

    stack2.emplace(18);
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;
    
    //swapping

    std::cout << "\nBefore swap:" << std::endl;
    std::cout << "The top of the stack 1 is: " << stack1.top() << std::endl;
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;
    
    stack1.swap(stack2);

    std::cout << "\nAfter swap:" << std::endl;
    std::cout << "The top of the stack 1 is: " << stack1.top() << std::endl;
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl;
}