#include <iostream>

using namespace std;

struct node{
	int data; //Isinya
	struct node * next; //Pointer ke node selanjutnya
};

int main(){
	//Inisialisasi linked list
	node * kepala = NULL;
	node * ekor = NULL;

	//Buat node baru - Anto
	node * anto = new node;
	anto -> data = 10; // data Anto
	anto -> next = NULL;// node setelah Anto - belum ada

	kepala = anto;
	ekor = anto;

	//Budi datang posisi di belakang
	node * budi = new node;
	budi -> data = 20;
	budi -> next = NULL;

	ekor -> next = budi;
	ekor = budi;

	//Candra datang posisi di depan
	node * candra = new node;
	candra -> data = 30;
	candra -> next = NULL;

	candra -> next = kepala;
	kepala = candra;

	// Dono datang ingin di belakang Anto (10)
	node * dono = new node;
	dono -> data = 40;
	dono -> next = NULL;

	//periksa satu-satu dari kepala
	node * posisi = kepala;
	while(posisi -> data != 10){
		posisi = posisi -> next;
	}

	//sisipkan Dono di belakang Anto
	dono -> next = posisi -> next;
	posisi -> next = dono;

	//Cetak semua elemen linked list!
	node * tampil = kepala;
	while(tampil != NULL){
		cout << tampil -> data;
		if(tampil != ekor)
			cout << " - ";
		tampil = tampil -> next;
	}


	return 0;
}