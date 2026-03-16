#include <iostream>
#include <string>

using namespace std;

/**
 * Program Contoh Struct: Data Mahasiswa
 * Topik: Mencari Mahasiswa dengan IPK Tertinggi
 */

struct Mahasiswa {
    string nim;
    string nama;
    float ipk;
    int semester;
};

int main() {
    const int JUMLAH = 3;
    Mahasiswa daftar[JUMLAH];

    cout << "=== Input Data Mahasiswa ===" << endl;
    for (int i = 0; i < JUMLAH; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "NIM      : "; cin >> daftar[i].nim;
        cout << "Nama     : "; cin >> daftar[i].nama; // Menggunakan cin >> (Satu kata)
        cout << "IPK      : "; cin >> daftar[i].ipk;
        cout << "Semester : "; cin >> daftar[i].semester;
    }

    // Mencari IPK tertinggi
    int indexTerbaik = 0;
    for (int i = 1; i < JUMLAH; i++) {
        if (daftar[i].ipk > daftar[indexTerbaik].ipk) {
            indexTerbaik = i;
        }
    }

    cout << "\n=== Mahasiswa dengan IPK Tertinggi ===" << endl;
    cout << "NIM      : " << daftar[indexTerbaik].nim << endl;
    cout << "Nama     : " << daftar[indexTerbaik].nama << endl;
    cout << "IPK      : " << daftar[indexTerbaik].ipk << endl;
    cout << "Semester : " << daftar[indexTerbaik].semester << endl;

    return 0;
}
