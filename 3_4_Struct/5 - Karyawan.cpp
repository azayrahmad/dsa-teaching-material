#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/**
 * Mini Project: Sistem Data Karyawan
 * Fitur: Input, Cari Gaji Tertinggi, Hitung Rata-rata Gaji
 */

enum Jabatan { STAF, MANAGER, DIREKTUR };

struct Karyawan {
    int id;
    string nama;
    double gaji;
    Jabatan jabatan;
};

string getNamaJabatan(Jabatan j) {
    switch (j) {
        case STAF: return "Staf";
        case MANAGER: return "Manager";
        case DIREKTUR: return "Direktur";
        default: return "Tidak Diketahui";
    }
}

int main() {
    const int JUMLAH = 3;
    Karyawan daftar[JUMLAH];
    double totalGaji = 0;

    cout << "=== Input Data Karyawan ===" << endl;
    for (int i = 0; i < JUMLAH; i++) {
        cout << "\nKaryawan ke-" << i + 1 << endl;
        cout << "ID (Angka)   : "; cin >> daftar[i].id;
        cout << "Nama         : "; cin.ignore(); getline(cin, daftar[i].nama);
        cout << "Gaji         : "; cin >> daftar[i].gaji;

        int pilihanJabatan;
        cout << "Jabatan (0:Staf, 1:Manager, 2:Direktur): ";
        cin >> pilihanJabatan;
        daftar[i].jabatan = static_cast<Jabatan>(pilihanJabatan);

        totalGaji += daftar[i].gaji;
    }

    // Cari gaji tertinggi
    int indexGajiTertinggi = 0;
    for (int i = 1; i < JUMLAH; i++) {
        if (daftar[i].gaji > daftar[indexGajiTertinggi].gaji) {
            indexGajiTertinggi = i;
        }
    }

    double rataGaji = totalGaji / JUMLAH;

    cout << "\n=== Laporan Karyawan ===" << endl;
    cout << fixed << setprecision(2);
    cout << "Rata-rata Gaji: Rp" << rataGaji << endl;

    cout << "\nKaryawan dengan Gaji Tertinggi:" << endl;
    cout << "Nama   : " << daftar[indexGajiTertinggi].nama << endl;
    cout << "Gaji   : Rp" << daftar[indexGajiTertinggi].gaji << endl;
    cout << "Jabatan: " << getNamaJabatan(daftar[indexGajiTertinggi].jabatan) << endl;

    return 0;
}
