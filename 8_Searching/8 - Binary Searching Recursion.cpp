#include <iostream>
using namespace std;

int binarySearch(int laci[], int atas, int bawah, int num) {
	if (atas <= bawah) {
		int posisi = (atas + bawah)/2;
		if (laci[posisi] == num)
			return posisi ;
		if (laci[posisi] > num)
			return binarySearch(laci, atas, posisi-1, num);
		if (laci[posisi] < num)
			return binarySearch(laci, posisi+1, bawah, num);
	}
	return -1;
}

int main() {
	const int jumlahLaci = 7;
	int laci[jumlahLaci] = {11, 12, 34, 45, 67, 88, 98};
	int atas = 0;
	int bawah = jumlahLaci - 1;
	int posisi;
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
		posisi = binarySearch(laci, atas, bawah, n);

		//Output
		cout<<"Nomor laci: ";
		cout<<posisi<<endl<<endl;

	}
	return 0;
}