#include <iostream>
using namespace std;
int main() {
	//Deklarasi struct
	struct mahasiswa{
		string nim;
		string nama;
		float ipk;
		int nilai[3];
		float rataRata(){
			int sum = nilai[0] + nilai[1] + nilai[2];
			return sum/3;
		}
	};
	
	mahasiswa sistemInformasi[3];
	
	sistemInformasi[0].nim = "343434";
	sistemInformasi[0].nama = "Nunik";
	sistemInformasi[0].ipk = 4.0;
	sistemInformasi[0].nilai = {1,2,3;
	
	sistemInformasi[1].nim = "456456";
	sistemInformasi[1].nama = "Affu";
	sistemInformasi[1].ipk = 4.4;
	
	sistemInformasi[2].nim = "876567";
	sistemInformasi[2].nama = "Haga";
	sistemInformasi[2].ipk = 5.0;
	
	//Lanjutkan dengan cout untuk masing-masing anggota array!
for(int i=0;i<3;i++){
	cout<<sistemInformasi[i].nama<<endl;
}
	
	return 0;
}