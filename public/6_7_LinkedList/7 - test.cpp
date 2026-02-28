#include <iostream>

using namespace std;

//Deklarasi node
struct node{
	string data;//data node
	struct node * next; //pointer ke node selanjutnya
};

int main(){
	//Inisialisasi linked list
	node * kepala = NULL;
	node * ekor = NULL;
	string antrian;

	while(1 == 1){
		cout << "Masukkan antrian: ";
		cin >> antrian;

			node * budi = new node;
			budi -> data = antrian;
			budi -> next = NULL;

			//Budi masuk ke belakang
			if(kepala == NULL){
				kepala = budi;
			}

			if(ekor == NULL){
				ekor = budi;
			} else {
				ekor -> next = budi;
				ekor = budi;
			}
			cout << "Antrian saat ini" << endl;
			//Cetak
			node * cetak = kepala;
			while(cetak != NULL){
				cout << cetak -> data;
				if (cetak -> next != NULL)
					cout << " - ";
				cetak = cetak -> next;
			}

			cout << endl;
	}
}