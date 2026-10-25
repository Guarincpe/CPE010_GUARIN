#include <iostream>
#include <string>
#include "stackList.h"

using namespace std;

int main()
{
    string expression;
    char answer;

    do
    {
        cout << "\n==============================" << endl;
        cout << "   BALANCED SYMBOL CHECKER" << endl;
        cout << "==============================" << endl;

        cout << "Input an expression: ";
        getline(cin, expression);

        bool result = isBalanced(expression);

        if (result)
        {
            cout << "\nThe expression is BALANCED." << endl;
        }
        else
        {
            cout << "\nThe expression is NOT BALANCED." << endl;
        }

        cout << "\nTry another expression? (Y/N): ";
        cin >> answer;
        cin.ignore(1000, '\n');

    } while (answer == 'Y' || answer == 'y');

    cout << "\nThank you for using the program!" << endl;

    return 0;
}