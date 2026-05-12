#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array
void printArray(int array[], int panjangArray) {
	for(int i = 0; i < panjangArray; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

}

int partition(int laci[], int depan, int belakang){
	//pilih elemen paling belakang sebagai pivot
	int isiPivot = laci[belakang];

	//penanda posisi akhir pivot
	int left = depan - 1;

	//looping untuk menyusun array
	for(int right = depan; right < belakang; right++){

		//jika elemen lebih kecil atau sama dengan elemen pivot
		if(laci[right] <= isiPivot){
			left++;

			//tukar isi laci
			int temp = laci[left];
			laci[left] = laci[right];
			laci[right] = temp;
		}
	}
	left++;

	//pindahkan elemen pivot dari belakang ke posisi pivot
	int temp = laci[left];
	laci[left] = laci[belakang];
	laci[belakang] = temp;

	//kembalikan indeks pivot
	return left;
}

void quickSort(int laci[], int depan, int belakang)
{
	if(depan < belakang){
		//tentukan indeks pivot
		int pivotIdx = partition(laci, depan, belakang);

		//lakukan quicksort di kanan dan kiri pivot
		quickSort(laci, depan, pivotIdx - 1);
		quickSort(laci, pivotIdx + 1, belakang);

	}

}
int main() {
	const int jumlahLaci = 8;
	int laci[jumlahLaci] = {14, 33, 27, 10, 35, 19, 42, 44};

	cout << "Array sebelum sorting:" << endl;
	printArray(laci, jumlahLaci);

	quickSort(laci, 0, jumlahLaci - 1);

	cout << "Array setelah sorting:" << endl;
	printArray(laci, jumlahLaci);

	return 0;
}