#include <iostream>
using namespace std;

/**
 * Fungsi Sequential Search
 * Mencari data dari awal sampai akhir satu per satu.
 * Mengembalikan index jika ditemukan, -1 jika tidak ditemukan.
 */
int sequentialSearch(int data[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (data[i] == key) {
            return i; // Ditemukan, kembalikan index
        }
    }
    return -1; // Tidak ditemukan
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int n = sizeof(data) / sizeof(data[0]);
    int key;

    cout << "Isi Array: ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;

    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    int hasil = sequentialSearch(data, n, key);

    if (hasil != -1) {
        cout << "Data ditemukan pada index: " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    return 0;
}
