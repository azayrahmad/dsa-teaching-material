#include <iostream>
using namespace std;

void printArray(int array[], int panjangArray) {
	for(int i = 0; i < panjangArray; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int laci[], int jumlahLaci) {
	bool adaPertukaran = true;
	int hitungLoop = 0;

	while(adaPertukaran) {
		adaPertukaran = false;
		for(int i = 0; i < jumlahLaci - 1; i++) {
			if(laci[i] > laci[i + 1]) {
				int temp = laci[i];
				laci[i] = laci[i + 1];
				laci[i + 1] = temp;
				adaPertukaran = true;
			}
		}
		hitungLoop++;
		cout << "Array setelah bubble sort ke-" << hitungLoop << ":" << endl;
		printArray(laci, jumlahLaci);
	}
}

void insertionSort(int laci[], int jumlahLaci) {
	for (int i = 1; i < jumlahLaci; i++) {
		int isi = laci[i];
		int sebelum = i - 1;
		while(sebelum >= 0 && isi < laci[sebelum]) {
			laci[i] = laci[sebelum];
			sebelum--;
		}
		laci[sebelum + 1] = isi;
		cout << "Array setelah insertion sort ke-" << i << ":" << endl;
		printArray(laci, jumlahLaci);
	}
}

void selectionSort(int laci[], int jumlahLaci) {
	int terkecil;

	for(int ini = 0; ini < jumlahLaci; ini++) {
		terkecil = ini;
		for(int cek = ini + 1; cek < jumlahLaci; cek++) {
			if(laci[cek] < laci[terkecil]) {
				terkecil = cek;
			}
		}
		if(terkecil != ini) {
			int temp = laci[ini];
			laci[ini] = laci[terkecil];
			laci[terkecil] = temp;
		}

		cout << "Array setelah selection sort ke-" << ini + 1 << ":" << endl;
		printArray(laci, jumlahLaci);
	}
}

void merge(int laci[], int depan, int belakang, int tengah) {
	//Pisahkan isi laci jadi dua, depan dan belakang
	int jmlDepan = tengah - depan + 1;
	int jmlBelakang = belakang - tengah;

	int laciDepan[jmlDepan], laciBelakang[jmlBelakang];

	for (int i = 0; i < jmlDepan; i++) {
		laciDepan[i] = laci[depan + i];
	}
	for (int j = 0; j < jmlBelakang; j++) {
		laciBelakang[j] = laci[tengah + 1 + j];
	}

	//Kembalikan isi laci dengan mendahulukan isi terkecil
	int i = 0;
	int j = 0;
	int posisi = depan;

	while(i < jmlDepan && j < jmlBelakang) {
		if(laciDepan[i] <= laciBelakang[j]) {
			laci[posisi] = laciDepan[i];
			i++;
		} else {
			laci[posisi] = laciBelakang[j];
			j++;
		}
		posisi++;
	}

	//Jika ada yang belum dikembalikan, masukkan sekarang
	while (i < jmlDepan) {
		laci[posisi] = laciDepan[i];
		i++;
		posisi++;
	}

	while (j < jmlBelakang) {
		laci[posisi] = laciBelakang[j];
		j++;
		posisi++;
	}
}
void mergeSort(int laci[], int depan, int belakang) {
	int tengah;
	if (depan < belakang) {
		tengah = (depan + belakang) / 2;
		mergeSort(laci, depan, tengah);
		mergeSort(laci, tengah + 1, belakang);

		merge(laci, depan, belakang, tengah);
	}

}

void shellSort(int laci[], int jumlahLaci) {
	int interval = jumlahLaci / 2;
	
	while (interval > 0){
		for (int i = interval; i < jumlahLaci; i++){
			int isi = laci[i];
			int posisi = i;
			while(posisi >= interval && isi < laci[posisi - interval]){
				laci[posisi] = laci[posisi - interval];
				posisi-= interval;
			}
			laci[posisi] = isi;
		}
		interval /= 2;
	}

}

int main() {
	const int jumlahLaci = 8;
	int laci[jumlahLaci] = {14, 33, 27, 10, 35, 19, 42, 44};

	cout << "Array sebelum sorting:" << endl;
	printArray(laci, jumlahLaci);

	shellSort(laci, jumlahLaci);
	
	cout << "Array setelah sort" << endl;
	printArray(laci, jumlahLaci);
	return 0;
}