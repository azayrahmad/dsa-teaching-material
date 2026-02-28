#include<iostream>
#include<string>

using namespace std;

int main(){
	int jumlah;

	cout << "Masukkan jumlah kamar ";
	cin >> jumlah;

	string kost[jumlah];
	string * pointerKost;

	pointerKost = kost;

	for(int i = 0; i < jumlah; i++){
		cout << "Masukkan penghuni kamar ke-" << i + 1 << ":";
		cin >> kost[i];
	}

	for(int i = 0; i < jumlah; i++){
		cout << "Penghuni kamar ke-" << i + 1 << ":" << kost[i] << " Alamat memori " << pointerKost << endl;
		pointerKost++;
	}

}