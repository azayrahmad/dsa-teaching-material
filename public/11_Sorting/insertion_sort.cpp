#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Geser elemen yang lebih besar dari key ke satu posisi di depannya
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int data[] = {12, 11, 13, 5, 6};
    int n = sizeof(data)/sizeof(data[0]);

    cout << "Data awal: ";
    printArray(data, n);

    insertionSort(data, n);

    cout << "Data terurut (Insertion Sort): ";
    printArray(data, n);

    return 0;
}
