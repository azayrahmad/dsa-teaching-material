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
	int pivot = depan - 1;
	
	//looping untuk menyusun array
	for(int j = depan; j < belakang; j++){
		
		//jika elemen lebih kecil dari elemen pivot
		if(laci[j] <= isiPivot){
			pivot++;
			
			//tukar isi laci
			int temp = laci[pivot];
			laci[pivot] = laci[j];
			laci[j] = temp;	
		}
	}
	pivot++;
	
	//pindahkan elemen pivot dari belakang ke posisi pivot
	int temp = laci[pivot];
	laci[pivot] = laci[belakang];
	laci[belakang] = temp;	
	
	//kembalikan indeks pivot
	return pivot;
}

void quickSort(int laci[], int depan, int belakang, int jumlahLaci)
{
	if(depan < belakang){
		//tentukan indeks pivot
		int pivot = partition(laci, depan, belakang);
		
		//lakukan quicksort di kanan dan kiri pivot
		quickSort(laci, depan, pivot - 1, jumlahLaci);
		quickSort(laci, pivot + 1, belakang, jumlahLaci);
		
	}
	
}
int main() {
	const int jumlahLaci = 8;
	int laci[jumlahLaci] = {14, 33, 27, 10, 35, 19, 42, 44};

	cout << "Array sebelum sorting:" << endl;
	printArray(laci, jumlahLaci);

	quickSort(laci, 0, jumlahLaci - 1, jumlahLaci);
	
	cout << "Array setelah sorting:" << endl;
	printArray(laci, jumlahLaci);

	return 0;
}