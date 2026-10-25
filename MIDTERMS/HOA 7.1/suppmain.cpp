#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "suppAlgo.h"

const int maxSize = 100;

void displayArray(int arr[])
{
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"};

    int votes[maxSize];

    int totalVotes[5] = {0};

    srand(time(0));

    // create random votes
    for (int i = 0; i < maxSize; i++)
    {
        votes[i] = (rand() % 5) + 1;
    }

    std::cout << "Original Votes:\n";
    displayArray(votes);

    // arrange votes
    selectionSort(votes, maxSize);
    std::cout << "\nSorted Votes:\n";
    displayArray(votes);

    // count each candidate vote
    for (int i = 0; i < maxSize; i++)
    {
        int candidateNumber = votes[i];

        totalVotes[candidateNumber - 1]++;
    }

    std::cout << "\nCandidate Results:\n";

    int highestVote = totalVotes[0];
    int winningCandidate = 0;

    for (int i = 0; i < 5; i++)
    {
        std::cout << candidates[i]
                  << ": "
                  << totalVotes[i]
                  << " votes"
                  << std::endl;

        if (totalVotes[i] > highestVote)
        {
            highestVote = totalVotes[i];
            winningCandidate = i;
        }
    }

    std::cout << "\nWinner:\n";
    std::cout << candidates[winningCandidate]
              << " with "
              << highestVote
              << " votes."
              << std::endl;

    return 0;
}