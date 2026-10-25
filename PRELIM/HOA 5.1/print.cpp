#include "Printer.h"

int main()
{

    Printer printer;

    int choice;

    do
    {

        cout << "\n================================\n";
        cout << "     SHARED PRINTER SIMULATOR\n";
        cout << "================================\n";

        cout << "1. Add Print Job\n";
        cout << "2. View Print Queue\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {

            int id;
            int pages;
            string username;

            cout << "\nEnter Job ID: ";
            cin >> id;

            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Number of Pages: ";
            cin >> pages;

            Job newJob(id, username, pages);

            printer.addJob(newJob);

            break;
        }

        case 2:
        {

            printer.viewQueue();

            break;
        }

        case 3:
        {

            cout << "\nThank you for using Shared Printer Simulator.\n";

            break;
        }

        default:
        {

            cout << "\nInvalid Choice.\n";
        }
        }

    } while (choice != 3);

    return 0;
}