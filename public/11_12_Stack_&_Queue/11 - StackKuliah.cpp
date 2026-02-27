#include <iostream>
#define MAX 5
using namespace std;

//Deklarasikan struct Stack
struct Stack {
	int top;	//Elemen di puncak stack
	int isi[MAX]; //Isi stack
};

//Deklarasikan variabel stack
Stack toples;

bool isEmpty() {
	return toples.top == -1;
}

bool isFull() {
	return toples.top == MAX - 1;
}

void peek(){
	cout<< "Kue teratas adalah kue tipe " << toples.isi[toples.top]<< endl;
}

//Fungsi untuk menambahkan data ke dalam stack
void push(int kue) {
	if(isFull()) {
		cout<<"Toples penuh!"<<endl;
	} else {
		toples.top++;
		toples.isi[toples.top] = kue;
		cout<<"Kue tipe "<< kue << " masuk."<<endl;
	}
}

//Fungsi untuk mengurangi data dari stack
void pop() {
	if(isEmpty()) {
		cout << "Toples kosong! " << endl;
	} else {
		cout<<"Kue tipe "<< toples.isi[toples.top] << " keluar."<<endl;
		toples.top--;
	}
}

void tampilkanIsiStack() {
	cout << "Isi toples: " << endl;
	for(int i = toples.top; i >= 0; i--) {
		cout << toples.isi[i] <<endl;
	}
	cout<<endl;
}

int main() {
	toples.top = -1;

	push(53);
	peek();
	push(45);
	push(67);
	tampilkanIsiStack();
	pop();
	pop();
	peek();
	pop();
	pop();
	tampilkanIsiStack();
}