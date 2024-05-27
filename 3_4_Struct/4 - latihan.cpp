#include <iostream>
#include <string>

using namespace std;

int main(){
	struct {
		int nim;
		string nama;
	} mahasiswa, mahasiswa2;
	
	mahasiswa.nim = 1234567890;
	mahasiswa.nama = "Andi";
	
	mahasiswa2.nim = 987654321;
	mahasiswa2.nama = "Budi";
	
	//Deklarasi struct
	struct mhsPrimakara {
		int nim;
		string nama;
	};
	
	//Deklarasi data tunggal
	mhsPrimakara citra;
	
	citra.nim = 123;
	citra.nama = "Citra";
	
	//Deklarasi array data
	mhsPrimakara informatika[3];
	informatika[0].nim = 456;
	informatika[0].nama = "Dude";

	//Print
	cout << informatika[0].nama << "(" << informatika[0].nim << ")";

	return 0;
}