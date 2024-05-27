
#include <iostream>

using namespace std;

int main() {
	int jumlahKamar;
	cout<<"Berapa jumlah kamar di kost?"<<endl;
	cin>>jumlahKamar;

	string kost[jumlahKamar];

	for(int i=0; i<jumlahKamar; i++) {
		cout<<"Nama penghuni kamar ke-"<<i + 1<<": ";
		cin>>kost[i];
	}

	string *pointerKost;
	pointerKost = kost;
	
	cout<<endl;
	cout<<endl;
	cout<<"Daftar penghuni kost"<<endl;
	for(int i=0; i<jumlahKamar; i++) {
		cout<<"Kamar ke-"<<i + 1<<": ";
		cout<<kost[i];
		cout<<" (Alamat memori: ";
		cout<<pointerKost+i<<")"<<endl;
	}


	return 0;
}

