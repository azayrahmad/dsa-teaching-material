#include <iostream>

using namespace std;

// Slide 3: Struktur Node
struct Node {
    int data;
    Node* next;
};

// Slide 8: Kode Insert Depan
void insertDepan(Node*& head, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = head;
    head = baru;
}

// Slide 10: Kode Insert Belakang
void insertBelakang(Node*& head, int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
}

// Slide 11: Insert Setelah Node
void insertSetelah(Node* target, int nilai) {
    if (target == NULL) return;
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = target->next;
    target->next = baru;
}

// Slide 13: Kode Delete Depan
void deleteDepan(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Slide 14: Delete Node Tertentu (by value)
void deleteNode(Node*& head, int nilai) {
    if (head == NULL) return;

    if (head->data == nilai) {
        deleteDepan(head);
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL && curr->data != nilai) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) return; // Tidak ketemu

    prev->next = curr->next;
    delete curr;
}

// Fungsi untuk menampilkan isi Linked List
void tampilkan(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    cout << "--- Linked List Lanjutan ---" << endl;

    // Slide 17: Latihan Analisis
    cout << "Operasi: insertDepan(10), insertDepan(5), deleteDepan()" << endl;
    insertDepan(head, 10);
    insertDepan(head, 5);
    deleteDepan(head);

    cout << "Hasil akhir: ";
    tampilkan(head);

    // Demonstrasi Operasi Lainnya
    cout << "\nDemonstrasi Operasi Lainnya:" << endl;
    insertBelakang(head, 20);
    insertSetelah(head, 15); // Setelah 10
    insertBelakang(head, 30);
    cout << "Setelah Insert Belakang & Tengah: ";
    tampilkan(head);

    deleteNode(head, 15);
    cout << "Setelah Hapus 15: ";
    tampilkan(head);

    return 0;
}
