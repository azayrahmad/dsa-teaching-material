#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

bool isFull() {
    return (front == (rear + 1) % MAX);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = data;
        cout << "Berhasil memasukkan " << data << " ke queue." << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Kosong (Underflow)!" << endl;
    } else {
        cout << "Berhasil mengeluarkan " << queue[front] << " dari queue." << endl;
        if (front == rear) {
            front = rear = -1; // Reset jika tinggal satu elemen
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue Kosong." << endl;
    } else {
        cout << "Isi Queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
        cout << "Front Index: " << front << " (" << queue[front] << ")" << endl;
        cout << "Rear Index: " << rear << " (" << queue[rear] << ")" << endl;
    }
}

int main() {
    int pilihan, data;

    do {
        cout << "\n=== MENU CIRCULAR QUEUE ===" << endl;
        cout << "1. Enqueue (Masuk)" << endl;
        cout << "2. Dequeue (Keluar)" << endl;
        cout << "3. Display (Tampilkan)" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
