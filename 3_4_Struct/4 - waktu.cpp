#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	struct waktu {
		int menit;
		int detik;
	};
	
	waktu waktuPertama;
	waktu waktuKedua;
	waktu waktuJarak;
	
	cout << "Masukkan menit pertama!";
	cin >> waktuPertama.menit;
	cout << "Masukkan detik pertama!";
	cin >> waktuPertama.detik;
	cout << "Masukkan menit kedua!";
	cin >> waktuKedua.menit;
	cout << "Masukkan detik kedua!";
	cin >> waktuKedua.detik;
	
	cout << "Waktu pertama: ";
	cout << setw(2) << setfill('0') << waktuPertama.menit;
	cout << ":" ;
	cout << setw(2) << setfill('0') << waktuPertama.detik;
	cout << ", ";
	cout << "Waktu kedua: " << waktuKedua.menit << ":" << waktuKedua.detik << endl;
	
	
	//Hitung jarak waktu
	if(waktuKedua.detik < waktuPertama.detik){
		waktuKedua.menit--;
		waktuKedua.detik += 60;
	}
	
	waktuJarak.menit = waktuKedua.menit - waktuPertama.menit;
	waktuJarak.detik = waktuKedua.detik - waktuPertama.detik;
	
	
	
	cout << "Selisih waktu adalah " << waktuJarak.menit << " menit, " << waktuJarak.detik << " detik.";
	return 0;
}