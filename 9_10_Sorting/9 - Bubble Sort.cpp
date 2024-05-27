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

int main() {
	const int jumlahLaci = 5;
	int laci[jumlahLaci] = {14, 33, 27, 35, 10};

	cout << "Array sebelum sorting:" << endl;
	printArray(laci, jumlahLaci);

	
	bubbleSort(laci, jumlahLaci);


	return 0;
}