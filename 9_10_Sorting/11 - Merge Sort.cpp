#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array
void printArray(int array[], int panjangArray) {
	for(int i = 0; i < panjangArray; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void merge(int laci[], int depan, int belakang, int tengah){
	// hitung jumlah elemen untuk masing masing bagian, 
	// depan dan belakang
	int jmlDepan = tengah - depan + 1;
	int jmlBelakang = belakang - tengah;
	
	//Buat array baru untuk menampung data yang sudah terurut
	int laciDepan[jmlDepan];
	int laciBelakang[jmlBelakang];
	
	//isi laciDepan
	for(int i = 0; i < jmlDepan; i++){
		laciDepan[i] = laci[depan + i];
	}
	
	//isi laciBelakang
	for(int j = 0; j < jmlBelakang; j++){
		laciBelakang[j] = laci[tengah + 1 + j];
	}
	
	//Kembalikan isi laci dengan mendahulukan isi terkecil
	int i = 0;
	int j = 0;
	int posisi = depan;
	
	while(i < jmlDepan && j < jmlBelakang){
		//Bandingkan elemen terdepan dari masing-masing laci
		if(laciDepan[i] <= laciBelakang[i]){
			laci[posisi] = laciDepan[i];
			i++;
		}
		else
		{
			laci[posisi] = laciBelakang[j];
			j++;
		}
		//isi posisi selanjutnya
		posisi++;
	}
	
	//Jika ada yang belum dikembalikan, masukkan sekarang
	while(i < jmlDepan){
		laci[posisi] = laciDepan[i];
		i++;
		posisi++;
	}
	
	while(j < jmlBelakang){
		laci[posisi] = laciBelakang[j];
		j++;
		posisi++;
	}
	
}

void mergeSort(int laci[], int depan, int belakang, int jumlahLaci) {
	int tengah;
	
	//selama masih valid
	if(depan < belakang){
		//bagi dua
		tengah = (depan + belakang) / 2;
		mergeSort(laci, depan, tengah, jumlahLaci);
		mergeSort(laci, tengah + 1, belakang, jumlahLaci);
		
		//lakukan merge sort ke masing masing bagian dan gabungkan
		merge(laci, depan, belakang, tengah);
	}
}


int main() {
	const int jumlahLaci = 8;
	int laci[jumlahLaci] = {14, 33, 27, 10, 35, 19, 42, 44};

	cout << "Array sebelum sorting:" << endl;
	printArray(laci, jumlahLaci);

	mergeSort(laci, 0, jumlahLaci - 1, jumlahLaci);
	
	cout << "Array setelah sorting:" << endl;
	printArray(laci, jumlahLaci);

	return 0;
}