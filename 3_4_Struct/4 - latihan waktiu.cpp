#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	//Deklarasi struct
	struct waktu{
		int menit;
		float detik;
	};
	
	//Deklarasi variabel
	waktu waktuPertama, waktuKedua, waktuSelisih;
	
	//Menerima input waktu pertama dan kedua
	cout << "Masukkan menit pertama!";
	cin >> waktuPertama.menit;
	cout << "Masukkan detik pertama!";
	cin >> waktuPertama.detik;
	cout << "Masukkan menit kedua!";
	cin >> waktuKedua.menit;
	cout << "Masukkan detik kedua!";
	cin >> waktuKedua.detik;
	
	//Tampilkan data yang baru diinput
	cout << "Waktu pertama: ";
	cout << setw(2) << setfill('0') << waktuPertama.menit;
	cout << ":" ;
	cout << setw(2) << setfill('0') <<  waktuPertama.detik;
	cout << ", ";
	cout << "Waktu kedua: ";
	cout << setw(2) << setfill('0') << waktuKedua.menit;
	cout << ":" ;
	cout << setw(2) << setfill('0') <<  waktuKedua.detik;
	cout << endl;

	
	//Meminjam menit jika detik kedua lebih kecil
	if(waktuKedua.detik < waktuPertama.detik){
		waktuKedua.menit--;
		waktuKedua.detik += 60;
	}
	
	//Perhitungan selisih waktu
	waktuSelisih.menit = waktuKedua.menit - waktuPertama.menit;
	waktuSelisih.detik = waktuKedua.detik - waktuPertama.detik;
	
	cout << "Selisih waktu adalah " << waktuSelisih.menit << " menit, " << waktuSelisih.detik << " detik.";
	
	
	return 0;
}
