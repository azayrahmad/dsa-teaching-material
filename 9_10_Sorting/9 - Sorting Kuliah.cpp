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

int main() {
	int pilihan;
	
	const int jumlahLaci = 8;
	int laci[jumlahLaci] = {14, 33, 27, 10, 35, 19, 42, 44};

	cout << "Array sebelum disort:" << endl;
	printArray(laci, jumlahLaci);

	cout << "Urutkan menggunakan:" << endl;
	cout<<"1) Bubble Sort"<<endl;
	cout<<"2) Insertion Sort"<<endl;
	cout<<"3) Selection Sort"<<endl;

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
		default:
			cout<<"Salah angka"<<endl;
	}


	//bubbleSort(laci, jumlahLaci);
	//insertionSort(laci, jumlahLaci);
	//selectionSort(laci, jumlahLaci);



	return 0;
}