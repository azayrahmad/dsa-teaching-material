#include <iostream>
using namespace std;

int binarySearch(int laci[], int awal, int akhir, int input)
{
	if(awal <= akhir){
		int tengah = (akhir + awal) / 2;

		if(laci[tengah] == input)
			return tengah;
		if(laci[tengah] < input)
			return binarySearch(laci, tengah + 1, akhir, input);
		if(laci[tengah] > input)
			return binarySearch(laci, awal, tengah - 1, input);
	}
	return -1;
}

int main() {
	const int jumlahLaci = 7;
	int laci[jumlahLaci] = {12, 5, 34, 100, 67, 200, 98};
	int input;

	//indeks pembatas
	int awal = 0;
	int akhir = jumlahLaci - 1;
	int tengah;

	//Mencetak isi array
	cout<<"Isi array"<<endl;
	for(int i = 0; i < 7; i++) {
		cout<<laci[i]<<endl;
	}

	while(true){

	//Input
	cout<<"Masukkan angka: ";
	cin>> input;

	//Binary Search
	tengah = binarySearch(laci, awal, akhir, input);

	//Output
	if(tengah == -1){
		cout << "data tidak ditemukan";

	} else {
		cout << "Nomor laci: " << tengah + 1;
	}

	cout << endl;
}
	return 0;
}