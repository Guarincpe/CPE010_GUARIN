#include <iostream>
#include <string>
#include "playlist_ll.h"

using namespace std;

int main()
{

    CircularList<string> *head = nullptr;
    CircularList<string> *current = nullptr;

    int choice;
    int n;
    string song;

    do
    {

        cout << "\n========== MUSIC PLAYLIST ==========\n";
        cout << "1. Create Playlist\n";
        cout << "2. Add Song\n";
        cout << "3. Remove Song\n";
        cout << "4. Play All Songs\n";
        cout << "5. Next Song\n";
        cout << "6. Previous Song\n";
        cout << "7. Current Song\n";
        cout << "8. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {

        case 1:

            if (head != nullptr)
            {
                cout << "Playlist already created.\n";
                break;
            }

            cout << "How many songs? ";
            cin >> n;
            cin.ignore();

            for (int i = 1; i <= n; i++)
            {

                cout << "Enter song " << i << ": ";
                getline(cin, song);

                insert_End(song, &head);
            }

            current = head;

            cout << "Playlist created!\n";
            break;

        case 2:

            cout << "Enter song name: ";
            getline(cin, song);

            insert_End(song, &head);

            if (current == nullptr)
                current = head;

            cout << "Song added!\n";

            break;

        case 3:

            if (head == nullptr)
            {
                cout << "Playlist is empty.\n";
                break;
            }

            cout << "Enter song to remove: ";
            getline(cin, song);

            delete_Node(song, &head, &current);

            break;

        case 4:

            play_All(head);

            break;

        case 5:

            if (current == nullptr)
            {
                cout << "Playlist is empty.\n";
                break;
            }

            next_Song(&current);
            display_Current(current);

            break;

        case 6:

            if (current == nullptr)
            {
                cout << "Playlist is empty.\n";
                break;
            }

            prev_Song(&current);
            display_Current(current);

            break;

        case 7:

            display_Current(current);

            break;

        case 8:

            destroy_List(&head);

            cout << "Goodbye!\n";

            break;

        default:

            cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}