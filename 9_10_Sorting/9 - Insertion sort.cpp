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

void insertionSort(int laci[], int jumlahLaci){
	for (int i = 1; i < jumlahLaci; i++){
		int isi = laci[i];
		int sebelum = i - 1;
		while(sebelum >= 0 && isi < laci[sebelum]){
			laci[i] = laci[sebelum];
			sebelum--;
		}
		laci[sebelum + 1] = isi;
		cout << "Array setelah insertion sort ke-" << i << ":" << endl;
		printArray(laci, jumlahLaci);
	}
}

int main() {
	const int jumlahLaci = 8;
	int laci[jumlahLaci] = {14, 33, 27, 10, 35, 19, 42, 44};

	cout << "Array sebelum sorting:" << endl;
	printArray(laci, jumlahLaci);
	
	insertionSort(laci, jumlahLaci);

	return 0;
}