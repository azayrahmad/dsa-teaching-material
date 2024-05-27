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
		
		//Deklarasi node
		node * baru = new node;
		baru -> data = antrian;
		baru -> next = NULL;
		
		//tambahkan di belakang
		if(kepala == NULL){
			kepala = baru;
			ekor = baru;
		
		} else {
			ekor -> next = baru;
			ekor = baru;
		}
		
		cout << "Antrian saat ini:" << endl;
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