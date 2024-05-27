#include <iostream>
#define MAX 5
using namespace std;

//Deklarasikan struct Stack
struct Queue {
	int depan;			//Elemen terdepan
	int belakang;		//Elemen terbelakang
	int isi[MAX];		//Array yang merupakan isi stack
};

Queue antrian;			//Deklarasi variabel queue

//Fungsi untuk memberitahu apakah queue sudah penuh
bool isFull() {
	return antrian.belakang == MAX - 1;
}

//Fungsi untuk memberitahu apakah queue masih kosong
bool isEmpty() {
	return antrian.depan == -1;
}

//Fungsi untuk menambah queue dari belakang
void enQueue(int nasabah) {
	if(isFull()) {
		cout << "Antrian penuh!" << endl;
	} else {
		if(isEmpty()) antrian.depan = 0;
		antrian.belakang++;
		antrian.isi[antrian.belakang] = nasabah;
		cout<< "Nasabah nomor " << nasabah << " masuk." <<endl;
	}
}

//Fungsi untuk mengurangi queue dari depan
void deQueue() {
	if(isEmpty()) {
		cout << "Antrian kosong!" << endl;
	} else {
		if(antrian.depan >= antrian.belakang) {
			antrian.depan = -1;
			antrian.belakang = -1;
		} else {
			cout<<"Nasabah nomor " << antrian.isi[antrian.depan] << " keluar." <<endl;
			antrian.depan++;
		}
	}
}

void tampilkanIsiQueue() {
	cout<<"Antrian saat ini:"<<endl;
	for(int i = antrian.depan; i <= antrian.belakang; i++) {
		cout<<antrian.isi[i]<<" ";
	}
	cout<<endl;
}

int main() {
	antrian.depan = -1;
	antrian.belakang = -1;

	enQueue(45);
	enQueue(57);
	enQueue(23);
	tampilkanIsiQueue();
	enQueue(17);
	enQueue(25);
	tampilkanIsiQueue();
	deQueue();
	deQueue();
	enQueue(68);
	enQueue(67);
	enQueue(66);
	enQueue(65);
	tampilkanIsiQueue();


	return 0;
}