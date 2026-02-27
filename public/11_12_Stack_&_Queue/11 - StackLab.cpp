#include <iostream>
#define MAX 5
using namespace std;

//Deklarasikan struct Stack
struct Stack {
	int top;			//Elemen teratas
	int isi[MAX];		//Array yang merupakan isi stack
};

Stack toples;			//Deklarasi variabel stack

//Fungsi untuk memberitahu apakah stack sudah penuh
bool isFull() {
	return toples.top == MAX - 1;
}

//Fungsi untuk memberitahu apakah stack masih kosong
bool isEmpty() {
	return toples.top == -1;
}

//Fungsi untuk menambah isi stack teratas
void push(int kue) {
	if(isFull()) {
		cout << "Toples penuh!" << endl;
	} else {
		toples.top++;
		toples.isi[toples.top] = kue;
		cout<< "Kue nomor " << kue << " masuk." <<endl;
	}
}

//Fungsi untuk mengeluarkan isi stack teratas
void pop() {
	if(isEmpty()) {
		cout << "Toples kosong!" << endl;
	} else {
		cout<<"Kue nomor " << toples.isi[toples.top] << " keluar." <<endl;
		toples.top--;
	}
}

void tampilkanIsiStack() {
	cout<<"Isi toples:"<<endl;
	for(int i = toples.top; i >= 0; i--) {
		cout<<toples.isi[i]<<endl;
	}
}

int main() {
	toples.top = -1;

	push(45);
	push(57);
	push(23);
	push(17);
	push(25);
	push(68);
	pop();
	tampilkanIsiStack();


	return 0;
}