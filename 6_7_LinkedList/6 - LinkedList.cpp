
#include <iostream>

using namespace std;

struct node {
	int data;
	struct node *next;
};

int main (void) {
	node *kepala, *ekor, *saatIni;
	kepala = ekor = saatIni = NULL;

	cout<<"Selamat datang di permainan ular-ularan!"<<endl;

	node *anto = new node;

	anto -> data = 10;
	anto -> next = NULL;
	
	cout<<"Anto (10) masuk ular-ularan pertama kali"<<endl;
	kepala = anto;
	ekor = anto;

	cout<<"Ular-ularan saat ini:"<<endl;
	
	saatIni = kepala;
	while (saatIni != NULL) {
		cout<<saatIni -> data<<" ";
		saatIni = saatIni -> next;
	}
	cout<<endl;

	node *budi = new node;

	budi -> data = 20;
	budi -> next = NULL;

	cout<<"Budi (20) masuk ular-ularan dari belakang"<<endl;
	ekor -> next = budi;
	ekor = budi;

	cout<<"Ular-ularan saat ini:"<<endl;
	
	saatIni = kepala;
	while (saatIni != NULL) {
		cout<<saatIni -> data<<" ";
		saatIni = saatIni -> next;
	}
	cout<<endl;
	
	node *candra = new node;
	
	candra -> data = 30;
	candra -> next = NULL;
		
	cout<<"Candra (30) masuk ular-ularan dari depan"<<endl;
	candra -> next = kepala;
	kepala = candra;

	cout<<"Ular-ularan saat ini:"<<endl;
	
	saatIni = kepala;
	while (saatIni != NULL) {
		cout<<saatIni -> data<<" ";
		saatIni = saatIni -> next;
	}
	cout<<endl;
	
	node *dono = new node;

	dono -> data = 40;
	dono -> next = NULL;
	
	cout<<"Dono (40) masuk ular-ularan di antara Anto(10) dan Budi(20)"<<endl;
	node *posisi = kepala;
	
	while(posisi -> data != 10){
		posisi = posisi -> next;
	}
	
	posisi -> next = dono;
	dono -> next = budi;

	cout<<"Ular-ularan saat ini:"<<endl;
	
	saatIni = kepala;
	while (saatIni != NULL) {
		cout<<saatIni -> data<<" ";
		saatIni = saatIni -> next;
	}
	cout<<endl;
	
	cout<<"Anto (10) pulang"<<endl;
	
	posisi = kepala;
	while(posisi -> next -> data != 10){
		posisi = posisi -> next;
	}
	posisi -> next = posisi -> next -> next;

	cout<<"Ular-ularan saat ini:"<<endl;
	
	saatIni = kepala;
	while (saatIni != NULL) {
		cout<<saatIni -> data<<" ";
		saatIni = saatIni -> next;
	}
	cout<<endl;
	
	cout<<"Candra (30) pulang"<<endl;
	
	kepala = kepala -> next;

	cout<<"Ular-ularan saat ini:"<<endl;
	
	saatIni = kepala;
	while (saatIni != NULL) {
		cout<<saatIni -> data<<" ";
		saatIni = saatIni -> next;
	}
	cout<<endl;
	
	cout<<"Budi (20) pulang"<<endl;
	
	posisi = kepala;
	while(posisi -> next != ekor){
		posisi = posisi -> next;
	}
	posisi -> next = NULL;

	cout<<"Ular-ularan saat ini:"<<endl;
	
	saatIni = kepala;
	while (saatIni != NULL) {
		cout<<saatIni -> data<<" ";
		saatIni = saatIni -> next;
	}
	cout<<endl;
	
	return 0;
}