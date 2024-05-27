#include <iostream>
using namespace std;

int main() {
	const int jumlahLaci = 7;
	int laci[jumlahLaci] = {11, 12, 34, 45, 67, 88, 98};
	int atas = 0;
	int bawah = jumlahLaci - 1;
	int n;

	//Mencetak isi array
	cout<<"Isi array"<<endl;
	for(int i = 0; i < 7; i++) {
		cout<<laci[i]<<endl;
	}
	while(1==1) {

		//Input
		cout<<"Masukkan angka: ";
		cin>>n;

		//Binary Search
		int posisi = ((bawah - atas) / 2) + atas;
		while(n != laci[posisi]) {
			if(laci[posisi] < n) {
				atas = posisi++;
			} else {
				bawah = posisi--;
			}


		}

		//Output
		cout<<"Nomor laci: ";
		cout<<posisi;

	}
	return 0;
}