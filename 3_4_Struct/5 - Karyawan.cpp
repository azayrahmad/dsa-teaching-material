#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Mini Project: Sistem Data Karyawan (SKELETON)
 *
 * TUGAS:
 * 1. Definisikan enum Jabatan (STAF, MANAGER, DIREKTUR).
 * 2. Definisikan struct Karyawan dengan field: id, nama, gaji, dan jabatan.
 * 3. Implementasikan input untuk 3 karyawan.
 * 4. Hitung rata-rata gaji.
 * 5. Cari dan tampilkan karyawan dengan gaji tertinggi.
 */

// TODO 1: Definisikan enum Jabatan di sini


// TODO 2: Definisikan struct Karyawan di sini


// Helper untuk menampilkan nama jabatan
string getNamaJabatan(/* parameter enum */) {
    // TODO: Implementasikan switch-case untuk mengembalikan string jabatan
    return "";
}

int main() {
    const int JUMLAH = 3;
    // TODO 3: Buat array of struct untuk menyimpan data karyawan

    cout << "=== Input Data Karyawan ===" << endl;
    for (int i = 0; i < JUMLAH; i++) {
        cout << "\nKaryawan ke-" << i + 1 << endl;
        // TODO 4: Implementasikan input data (ID, Nama, Gaji, Jabatan)
        // Gunakan static_cast untuk mengkonversi input angka ke enum Jabatan
    }

    // TODO 5: Hitung rata-rata gaji perusahaan


    // TODO 6: Cari index karyawan dengan gaji tertinggi


    cout << "\n=== Laporan Karyawan ===" << endl;
    cout << fixed << setprecision(2);
    // TODO 7: Tampilkan hasil rata-rata dan data karyawan gaji tertinggi

    return 0;
}
