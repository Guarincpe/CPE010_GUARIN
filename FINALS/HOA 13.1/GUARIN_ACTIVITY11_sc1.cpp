#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

void uniqueValArr(int arr[], int size){
    for (int i = 0; i < size; i++) arr[i] = i;
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

bool isUnique(int arr[], int size){
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (arr[i] == arr[j]) return false;
        }
    }
    return true;
}

void runTest(int size){
    int* array = new int[size];
    uniqueValArr(array, size);

    auto begin = std::chrono::steady_clock::now();
    bool unique = isUnique(array, size);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Time taken to search array size " << size << " = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " microseconds\n";
    std::cout << (unique ? "Array has unique elements\n" : "Array has duplicates\n");

    delete[] array;
}

int main(){
    srand(time(0));
    const int sizes[3] = {100, 1000, 100000};
    for (int i = 0; i < 3; i++){
        runTest(sizes[i]);
    }
    return 0;
}