#include <iostream>

using namespace std;

//Deklarasi node
struct node{
	int data;//data node
	struct node * next; //pointer ke node selanjutnya
};

int main(){
	//Inisialisasi linked list
	node *kepala = NULL;
	node *ekor = NULL;
	
	//Deklarasi node baru - Anto
	node * anto = new node;
	anto -> data = 10; //data anto
	anto -> next = NULL; //node setelah anto - belum ada
	
	kepala = anto;
	ekor = anto;
	
	//Deklarasi budi
	node * budi = new node;
	budi -> data = 20;
	budi -> next = NULL;
	
	//Budi masuk ke belakang
	ekor -> next = budi;
	ekor = budi;
	
	node * farhan = new node;
	farhan -> data = 30;
	farhan -> next = NULL; 
	
	ekor -> next = farhan;
	ekor = farhan;
	
	node * candra = new node;
	candra -> data = 40;
	candra -> next = NULL;
	
	candra -> next = kepala;
	kepala = candra;
	
	//Dono datang 
	node * dono = new node;
	dono -> data = 50;
	dono -> next = NULL;
	
	//Dono ingin menyisipkan diri di belakang Budi (20)
	node * posisi = kepala;
	while(posisi -> data != 20){
		posisi = posisi -> next;
	}
	
	dono -> next = posisi -> next;
	posisi -> next = dono;
	
	//Tambah 60 di belakang
	node * reyhan = new node;
	reyhan -> data = 60;
	reyhan -> next = NULL;
	
	ekor -> next = reyhan;
	ekor = reyhan;
	
	//Hapus yang terdepan
	kepala = kepala -> next;
	
	//Hapus yang bernilai 50
	node * hapus = kepala;
	while(hapus -> next -> data != 50){
		hapus = hapus -> next;
	}
	
	hapus -> next = hapus -> next-> next; 
	
	//hapus ekor
	hapus = kepala;
	while(hapus -> next != ekor){
		hapus = hapus -> next;
	} 
	
	ekor = hapus;
	hapus -> next= NULL; 
	
	//Cetak
	node * cetak = kepala;
	while(cetak != NULL){
		cout << cetak -> data;
		if (cetak -> next != NULL)
			cout << " - ";
		cetak = cetak -> next;
	}
}