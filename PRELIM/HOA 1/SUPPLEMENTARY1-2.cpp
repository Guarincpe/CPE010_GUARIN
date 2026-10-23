#include <iostream>

void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int num1, num2;
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "\nBefore Swapping\n";
    std::cout << "First Number: " << num1 << std::endl;
    std::cout << "Second Number: " << num2 << std::endl;

    swapNumbers(num1, num2);
    std::cout << "\nAfter Swapping\n";
    std::cout << "First Number: " << num1 << std::endl;
    std::cout << "Second Number: " << num2 << std::endl;

    return 0;
}