#include <iostream>
#include <string>

using namespace std;

#define MAX 5 // Ukuran maksimal stack

int stack[MAX];
int top = -1;

// Fungsi untuk mengecek apakah stack penuh
bool isFull() {
    return top == MAX - 1;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return top == -1;
}

// Fungsi untuk menambah data ke stack
void push(int data) {
    if (isFull()) {
        cout << "Stack Overflow! Tidak dapat menambah data: " << data << endl;
    } else {
        top++;
        stack[top] = data;
        cout << "Data " << data << " berhasil di-push ke stack." << endl;
    }
}

// Fungsi untuk mengambil data teratas dari stack
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack kosong, tidak ada data untuk di-pop." << endl;
    } else {
        cout << "Data " << stack[top] << " berhasil di-pop dari stack." << endl;
        top--;
    }
}

// Fungsi untuk melihat data teratas tanpa menghapusnya
int peek() {
    if (isEmpty()) {
        cout << "Stack kosong." << endl;
        return -1;
    }
    return stack[top];
}

// Fungsi untuk menampilkan seluruh isi stack
void display() {
    if (isEmpty()) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Isi stack (dari atas ke bawah):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << "| " << stack[i] << " |" << (i == top ? " <- top" : "") << endl;
        }
        cout << "-------" << endl;
    }
}

int main() {
    int pilihan, data;

    do {
        cout << "\n=== MENU STACK ARRAY ===" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data (angka): ";
                cin >> data;
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    cout << "Elemen teratas adalah: " << data << endl;
                }
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
