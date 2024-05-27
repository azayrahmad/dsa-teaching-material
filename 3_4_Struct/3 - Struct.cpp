#include <iostream>
using namespace std;
int main() {
	//Deklarasi struct
	struct mahasiswa{
		string nim;
		string nama;
		float ipk;
	};
	
	int jumlahMhs = 3;
	mahasiswa sistemInformasi[jumlahMhs];
	
	sistemInformasi[0].nim = "343434";
	sistemInformasi[0].nama = "Nunik";
	sistemInformasi[0].ipk = 4.0;
	
	sistemInformasi[1].nim = "456456";
	sistemInformasi[1].nama = "Affu";
	sistemInformasi[1].ipk = 4.4;
	
	sistemInformasi[2].nim = "876567";
	sistemInformasi[2].nama = "Haga";
	sistemInformasi[2].ipk = 5.0;
	
	for(int i = 0; i < jumlahMhs; i++){
		cout<<sistemInformasi[i].nim<<" - "<<sistemInformasi[i].nama<<". Nilai IPK = "<<sistemInformasi[i].ipk<<endl;
	}
	
	return 0;
}