#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * Program Simulasi Undo & Redo menggunakan Stack
 * Memperlihatkan bagaimana dua stack bekerja bersama untuk mengelola history.
 */

void displayState(const string& current, stack<string> undoStack, stack<string> redoStack) {
    cout << "\n------------------------------------------" << endl;
    cout << "Editor Sekarang: \"" << current << "\"" << endl;

    cout << "Undo Stack (atas ke bawah): ";
    if (undoStack.empty()) cout << "[Kosong]";
    while (!undoStack.empty()) {
        cout << "[" << undoStack.top() << "] ";
        undoStack.pop();
    }

    cout << "\nRedo Stack (atas ke bawah): ";
    if (redoStack.empty()) cout << "[Kosong]";
    while (!redoStack.empty()) {
        cout << "[" << redoStack.top() << "] ";
        redoStack.pop();
    }
    cout << "\n------------------------------------------" << endl;
}

int main() {
    stack<string> undoStack;
    stack<string> redoStack;
    string currentText = "";
    int pilihan;
    string input;

    cout << "=== SIMULASI UNDO & REDO ===" << endl;

    do {
        displayState(currentText, undoStack, redoStack);
        cout << "1. Ketik Teks Baru (Simpan State)" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline

        switch (pilihan) {
            case 1:
                cout << "Masukkan teks: ";
                getline(cin, input);

                // Simpan state lama ke undo stack sebelum berubah
                undoStack.push(currentText);
                currentText = input;

                // Aksi baru menghapus riwayat redo
                while (!redoStack.empty()) redoStack.pop();

                cout << "State disimpan." << endl;
                break;

            case 2:
                if (!undoStack.empty()) {
                    // Pindahkan state sekarang ke redo
                    redoStack.push(currentText);
                    // Ambil state paling baru dari undo
                    currentText = undoStack.top();
                    undoStack.pop();
                    cout << "Undo berhasil." << endl;
                } else {
                    cout << "Tidak ada aksi untuk di-undo!" << endl;
                }
                break;

            case 3:
                if (!redoStack.empty()) {
                    // Pindahkan state sekarang ke undo
                    undoStack.push(currentText);
                    // Ambil state paling baru dari redo
                    currentText = redoStack.top();
                    redoStack.pop();
                    cout << "Redo berhasil." << endl;
                } else {
                    cout << "Tidak ada aksi untuk di-redo!" << endl;
                }
                break;

            case 4:
                cout << "Keluar program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}
