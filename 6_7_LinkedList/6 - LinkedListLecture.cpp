
#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *next;
};

void tampilkanLinkedList(node *kepala)
{	
	node *posisi = NULL;
	
	cout<<"Susunan ular-ularan saat ini:"<<endl;
	posisi = kepala;
	
	while( posisi != NULL){ 		//selama masih ada node (pemain)
		cout<<posisi -> data<<" "; 	//tampilkan data (nomor kaos)
		posisi = posisi -> next; 	//pindah ke node (pemain) di belakangnya
	}
	cout<<endl;
	cout<<endl;
}

int main (void) {
	//Inisialisasi linked list (ular-ularan)
	node *kepala = NULL;
	node *ekor = NULL;
	node *posisi = NULL;
	
	//Anto datang
	node *anto = new node;
	anto -> data = 10; //nomor kaos
	anto -> next = NULL;
	
	//Anto masuk ular-ularan
	kepala = anto;
	ekor = anto;
	
	cout<<"Anto (10) masuk"<<endl;
	//Menampilkan susunan ular-ularan saat ini
	tampilkanLinkedList(kepala);
	
	//Budi datang
	node *budi = new node;
	budi -> data = 20; //nomor kaos
	budi -> next = NULL;
	
	//Budi masuk ular-ularan dari belakang
	ekor -> next = budi;
	ekor = budi;
	cout<<"Budi (20) masuk dari belakang"<<endl;
	//Menampilkan susunan ular-ularan saat ini
	tampilkanLinkedList(kepala);
	
	//Candra datang
	node *candra = new node;
	candra -> data = 30; //nomor kaos
	candra -> next = NULL;
	
	//Candra masuk ular-ularan dari depan
	candra -> next = kepala;
	kepala = candra; 
	cout<<"Candra (30) masuk dari depan"<<endl;
	
	//Menampilkan susunan ular-ularan saat ini
	tampilkanLinkedList(kepala);
	
	//Dono datang
	node *dono = new node;
	dono -> data = 40; //nomor kaos
	dono -> next = NULL;
	
	//Dono masuk ular-ularan di belakang Anto (10)
	posisi = kepala;
	
	while( posisi -> data != 10){
		posisi = posisi -> next;
	}
	
	dono -> next = posisi -> next;
	posisi -> next = dono;
	
	cout<<"Dono (40) menyisipkan diri di belakang Anto (10)"<<endl;
	//Menampilkan susunan ular-ularan saat ini
	tampilkanLinkedList(kepala);
	
	//Candra (30) yang paling depan, pulang
	cout<<"Candra (30) pulang"<<endl;
	kepala = kepala -> next;

	//Menampilkan susunan ular-ularan saat ini
	tampilkanLinkedList(kepala);
	
	//Budi (20) yang paling depan, pulang
	cout<<"Budi (20) pulang"<<endl;
	posisi = kepala;
	
	while(posisi -> next != ekor){
		posisi = posisi -> next;
	}
	posisi -> next = NULL;
	ekor = posisi; 
	
	
	//Menampilkan susunan ular-ularan saat ini
	tampilkanLinkedList(kepala);
	return 0;
}