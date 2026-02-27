#include <iostream>
using namespace std;
int main() {

	cout<<"------------------------------------ "<<endl;
	cout<<"Program mengisi dan menampilan array"<<endl;
	cout<<"------------------------------------ "<<endl<<endl;

	int panjangArray;

	cout<<"Masukkan panjang array: ";
	cin>>panjangArray;

	int rakArray[panjangArray];

	for (int i = 0; i < panjangArray; i++) {
		cout << "Masukkan angka ke-" << i+1 << ": ";
		cin >> rakArray[i];
	 }

	cout<<endl<<"Berikut adalah angka-angka yang anda masukkan ke array: "<<endl;

	for (int i = 0; i < panjangArray; i++) {
	  cout << "Angka ke-"<<i+1<<": "<<rakArray[i] << endl;
	}

	cout<<"Selesai"<<endl;
	cout<<"Terima kasih"<<endl;
}