#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertDepan(Node*& head, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = head;
    head = baru;
}

void tampilkan(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/**
 * LATIHAN:
 * 1. Implementasikan fungsi insertBelakang(Node*& head, int nilai)
 * 2. Implementasikan fungsi deleteDepan(Node*& head)
 */

int main() {
    Node* head = NULL;

    // Masukkan kode latihan di sini
    cout << "Selamat mengerjakan latihan Linked List Lanjutan!" << endl;

    return 0;
}
