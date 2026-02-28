#include <iostream>

using namespace std;

//deklarasi stack
struct Node{
    string rasa;
    struct Node * next;
};

Node * top; // elemen teratas

//Fungsi untuk memberitahu apabila stack kosong
bool isEmpty(){
    return top == NULL;
}

//Fungsi untuk menambahkan data ke dalam stack
void push(string data){
    //Deklarasi elemen baru
    struct Node *biskuit;
    biskuit = new Node;
    biskuit -> rasa = data;
    biskuit -> next = top;

    //Elemen baru selalu menjadi top
    top = biskuit;
    cout << "Biskuit rasa " << data << " masuk." << endl;

}

//Fungsi untuk mengeluarkan isi stack
void pop(){
    if(isEmpty()){
        cout << "Toples kosong!" << endl;
    } else {
        cout << "Biskuit rasa " << top -> rasa << " dikeluarkan." << endl;
        top = top -> next;
    }

}

// Fungsi untuk menampikan isi stack dari top sampai bawah
void printStack(){
    cout << "Isi toples saat ini:" << endl;

    if(isEmpty()){
        cout << "Kosong" << endl;
    }

    Node * posisi;
    posisi = top;
    while(posisi != NULL){
        cout << posisi -> rasa << endl;
        posisi = posisi -> next;
    }
}

int main() {
    int input;
    string rasa;

    //stack belum ada isi
    top = NULL;

    while(true){
        cout << "Selamat datang di Biskuit STACK" << endl;
        cout << "1. Tambah biskuit" << endl;
        cout << "2. Ambil biskuit" << endl;
        cout << "3. Tampilkan isi" << endl;
        cin >> input;
        switch(input){
            case 1:
                cout << "Apa rasa biskuit yang akan ditambah?" << endl;
                cin >> rasa;
                push(rasa);
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
        }
    }



    return 0;
}