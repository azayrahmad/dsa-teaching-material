#include <iostream>
using namespace std;

/**
 * Fungsi Binary Search
 * Mencari data pada array yang TERURUT dengan cara bagi dua.
 * Mengembalikan index jika ditemukan, -1 jika tidak ditemukan.
 */
int binarySearch(int data[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == key) {
            return mid; // Ditemukan
        }

        if (key < data[mid]) {
            right = mid - 1; // Cari di bagian kiri
        } else {
            left = mid + 1; // Cari di bagian kanan
        }
    }

    return -1; // Tidak ditemukan
}

int main() {
    // SYARAT: Data harus terurut
    int data[] = {10, 20, 30, 40, 50};
    int n = sizeof(data) / sizeof(data[0]);
    int key;

    cout << "Isi Array (Terurut): ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;

    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    int hasil = binarySearch(data, n, key);

    if (hasil != -1) {
        cout << "Data ditemukan pada index: " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    return 0;
}
