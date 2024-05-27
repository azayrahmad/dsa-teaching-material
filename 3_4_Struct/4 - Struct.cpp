#include <iostream>
#include <string>

using namespace std;

int main(){
	//Deklarasi struct satuan
	
	struct {
		int nim;
		string nama;
	} mahasiswa, mahasiswa_budi;
	
	mahasiswa.nim = 123;
	mahasiswa.nama = "Andi";
	
	mahasiswa_budi.nim = 456;
	mahasiswa_budi.nama = "Budi";
	
	//cout << mahasiswa_budi.nama;
	
	//Deklarasi named structure (struktur bernama)
	struct mhsPrimakara {
		char nim[10];
		string nama;
	};
	
	int a = 10;
	mhsPrimakara citra;
	strcpy(citra.nim, "789");
	citra.nama = "Citra";
	
	cout << citra.nim;
	
	mhsPrimakara informatika[3];
	strcpy(informatika[0].nim, "234");
	informatika[0].nama = "Damar";
	strcpy(informatika[0].nim, "567");
	informatika[1].nama = "Erna";
	strcpy(informatika[0].nim, "890");
	informatika[2].nama = "Fahmi";
	
	cin >> informatika[0].nim;
	cout << informatika[0].nim;
	
	return 0;
}