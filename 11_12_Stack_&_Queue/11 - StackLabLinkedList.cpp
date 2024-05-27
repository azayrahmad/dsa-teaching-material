#include <iostream>
using namespace std;

//Deklarasikan struct Stack
struct Node{
	int data;
	struct Node *next;
};

Node *top;

//Fungsi untuk memberitahu apakah stack masih kosong
bool isEmpty() {
	return top == NULL;
}

//Fungsi untuk menambah isi stack teratas
void push(int kue) {
	struct Node *baru;
	baru = new Node;
	baru -> data = kue;
	baru -> next = top;
	
	top = baru;

}

//Fungsi untuk mengeluarkan isi stack teratas
void pop() {
	if(isEmpty()){
		cout << "Toples kosong!" << endl;
	}
	else{
		top = top -> next;
	}

}

void tampilkanIsiStack() {
	Node* saatIni;
	saatIni = top;
	while(saatIni != NULL){
		cout << saatIni -> data << endl;
		saatIni = saatIni -> next;
	}

}

int main() {
top = NULL;
	push(45);
	push(57);
	push(23);
	push(17);
	push(25);
	push(68);

	tampilkanIsiStack();


	return 0;
}