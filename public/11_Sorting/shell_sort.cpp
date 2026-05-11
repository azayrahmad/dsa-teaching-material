#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array
void printArray(int array[], int panjangArray) {
	for(int i = 0; i < panjangArray; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}


void shellSort(int laci[], int jumlahLaci) {
	//menghitung interval, dimulai dari panjang array : 2
	int interval = jumlahLaci / 2;

	//selama interval belum kurang dari 1
	while(interval >= 1) {
		//Mulai dari tengah ke belakang
		for(int i = interval; i < jumlahLaci; i++) {
			int isi = laci[i];
			int posisi = i;

			//Operasi insertion sort per interval
			while(posisi >= interval && isi < laci[posisi - interval]) {

				//jika di depan lebih besar, yang besar mundur
				laci[posisi] = laci[posisi - interval];
				posisi = posisi - interval;
			}
			//insert isi ke posisi yang benar
			laci[posisi] = isi;
		}
		//perkecil interval
		interval = interval / 2;
	}

	cout << "Array setelah disort:" << endl;
	printArray(laci, jumlahLaci);
}


int main() {
	const int jumlahLaci = 8;
	int laci[jumlahLaci] = {14, 33, 27, 10, 35, 19, 42, 44};

	cout << "Array sebelum sorting:" << endl;
	printArray(laci, jumlahLaci);

	shellSort(laci, jumlahLaci);

	return 0;
}