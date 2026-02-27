#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array
void printArray(int array[], int panjangArray) {
	for(int i = 0; i < panjangArray; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

// Fungsi untuk menukar elemen array
void tukarIsiLaci(int laci[], int noLaciA, int noLaciB) {
	int temp = laci[noLaciA];
	laci[noLaciA] = laci[noLaciB];
	laci[noLaciB] = temp;
	cout << "Terjadi pertukaran" << endl;
}

// Fungsi untuk mengurutkan menggunakan metode Bubble Sort
void bubbleSort(int array[], int panjangArray) {
	bool adaPertukaran = true;
	int hitungLoop = 0;

	while(adaPertukaran) {
		adaPertukaran = false;
		for (int i = 0; i < panjangArray - 1; i++) {
			if(array[i] > array[i + 1]) {
				tukarIsiLaci(array, i, i + 1);
				adaPertukaran = true;
			}
		}
		hitungLoop++;
		cout << "Array setelah bubble sort ke-" << hitungLoop << ":" << endl;
		printArray(array, panjangArray);
	}
}

// Fungsi untuk mengurutkan menggunakan metode Insertion Sort
void insertionSort(int array[], int panjangArray) {
	for (int i = 1; i < panjangArray; i++) {
		int isi = array[i];
		int posisi = i;

		while(posisi > 0 && isi < array[posisi-1]) {
			array[posisi] = array[posisi - 1];
			posisi--;
		}
		if(posisi != i) {
			array[posisi] = isi;
		}

		cout<< "Array setelah insertion sort ke-" << i << ":" << endl;
		printArray(array, panjangArray);
	}
}

// Fungsi untuk mengurutkan menggunakan metode Selection Sort
void selectionSort(int array[], int panjangArray) {
	int terkecil;

	for(int i = 0; i < panjangArray; i++) {
		terkecil = i;
		for(int cek = i + 1; cek < panjangArray; cek++) {
			if(array[cek] < array[terkecil]) {
				terkecil = cek;
			}
		}
		if(terkecil != i) {
			tukarIsiLaci(array, terkecil, i);
		}

		cout << "Array setelah selection sort ke-" << i + 1 << ": " << endl;
		printArray(array, panjangArray);
	}
}

// Fungsi untuk mengurutkan menggunakan metode Shell Sort
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

// Fungsi-fungsi untuk mengurutkan menggunakan metode Merge Sort
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

// Fungsi-fungsi untuk mengurutkan menggunakan metode Quick Sort
int partition(int laci[], int depan, int belakang) {
	int isiPivot = laci[belakang];

	int pivot = depan - 1;

	for (int j = depan; j < belakang; j++){
		if(laci[j] <= isiPivot){
			pivot++;
			tukarIsiLaci(laci, pivot, j);
		}
	}
	pivot++;
	tukarIsiLaci(laci, pivot, belakang);

	return pivot;
}
void quickSort(int laci[], int depan, int belakang) {
	if (depan < belakang) {
		int pivot = partition(laci, depan, belakang);

		quickSort(laci, depan, pivot - 1);
		quickSort(laci, pivot + 1, belakang);
	}
}

int main() {
	int pilihan;

	const int jumlahLaci = 5;
	int laci[jumlahLaci] = {32, 11, 93, 88, 76};

	cout << "Array sebelum disort:" << endl;
	printArray(laci, jumlahLaci);

	cout<<"Urutkan menggunakan:" << endl;
	cout<<"1) Bubble Sort"<<endl;
	cout<<"2) Insertion Sort"<<endl;
	cout<<"3) Selection Sort"<<endl;
	cout<<"4) Shell Sort"<<endl;
	cout<<"5) Merge Sort"<<endl;
	cout<<"6) Quick Sort"<<endl;

	cin>>pilihan;
	switch (pilihan) {
		case 1:
			bubbleSort(laci, jumlahLaci);
			break;
		case 2:
			insertionSort(laci, jumlahLaci);
			break;
		case 3:
			selectionSort(laci, jumlahLaci);
			break;
		case 4:
			shellSort(laci, jumlahLaci);
			break;
		case 5:
			mergeSort(laci, 0, jumlahLaci);
			break;
		case 6:
			quickSort(laci, 0, jumlahLaci);
			break;
		default:
			cout<<"Salah angka"<<endl;
	}

	cout << "Hasil akhir sort: " << endl;
	printArray(laci, jumlahLaci);

	return 0;
}