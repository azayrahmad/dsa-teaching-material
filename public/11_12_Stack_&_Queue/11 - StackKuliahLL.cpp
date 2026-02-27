#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node *top;

bool isEmpty() {
	return top == NULL;
}


//Fungsi untuk menambahkan data ke dalam stack
void push(int input) {
	struct Node *baru;
	baru = new Node;
	baru -> data = input;
	baru -> next = top;

	top = baru;

}

//Fungsi untuk mengurangi data dari stack
void pop() {
	if(isEmpty()) {
		cout << "Tumpukan kosong! " << endl;
	} else {
		top = top -> next;
	}
}

void tampilkanIsiStack() {
	Node* saatIni;
	saatIni = top;
	while (saatIni != NULL) {
		cout<<saatIni -> data<<endl;
		saatIni = saatIni -> next;
	}
}

int main() {
	top = NULL;

	push(53);
	push(63);
	pop();
	tampilkanIsiStack();

}