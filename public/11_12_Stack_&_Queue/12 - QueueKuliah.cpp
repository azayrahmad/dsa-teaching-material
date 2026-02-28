#include <iostream>
#define MAX 5
using namespace std;

//Deklarasi struct Queue
struct Queue {
	int terDepan;		//Elemen terdepan dalam antrian
	int terBelakang;	//Elemen paling belakang dalam antrian
	int isi[MAX];		//Array yang digunakan untuk mengisi antrian
};

Queue antrian;			//Deklarasi variabel queue

//Fungsi untuk memberitahu apakah queue sudah penuh
bool isFull() {
	return antrian.terBelakang == MAX - 1;
}

//Fungsi untuk memberitahu apakah queue masih kosong
bool isEmpty() {
	return antrian.terDepan == -1;
}

//Fungsi untuk menambahkan elemen baru ke belakang antrian
void enQueue(int nasabah) {
	if(isFull()) {
		cout << "Antrian penuh!" << endl;
	} else {
		if(isEmpty()) {
			antrian.terDepan = 0;
		}
		antrian.terBelakang++;
		antrian.isi[antrian.terBelakang] = nasabah;
		cout << "Nasabah nomor " << nasabah << " telah masuk antrian." << endl;
	}
}

//Fungsi untuk mengeluarkan elemen terdepan dari antrian
void deQueue() {
	if(isEmpty()) {
		cout << "Antrian kosong!" << endl;
	} else {
		if(antrian.terDepan >= antrian.terBelakang) {	//Antrian sudah habis
			antrian.terDepan = -1;
			antrian.terBelakang = -1;
		} else {
			cout << "Nasabah nomor " << antrian.isi[antrian.terDepan] << " sudah selesai." << endl;
			antrian.terDepan++;
		}

	}
}

void tampilkanAntrian() {
	cout << "Antrian saat ini:" << endl;
	if(isEmpty()) {
		cout << "Kosong";
	} else {

		for(int i = antrian.terDepan; i <= antrian.terBelakang; i++) {
			cout << antrian.isi[i] << " ";
		}
	}
	cout << endl;
}


int main() {
	//Inisialisasi
	antrian.terDepan = -1;
	antrian.terBelakang = -1;

	enQueue(10);		//Nasabah no 10 masuk
	enQueue(20);		//Nasabah no 20 masuk di belakang 10 [10 20]
	enQueue(30);		//Nasabah no 30 masuk di belakang 20 [10 20 30]
	deQueue();			//Nasabah no 10 keluar [20 30]
	deQueue();			//Nasabah no 20 keluar [30]
	deQueue();			//Nasabah no 30 keluar [kosong]
	deQueue();			//Antrian kosong
	enQueue(11);
	enQueue(21);
	enQueue(31);
	enQueue(41);
	enQueue(51);
	enQueue(61);		//Antrian penuh
	tampilkanAntrian();	//[11 21 31 41 51]

	return 0;
}