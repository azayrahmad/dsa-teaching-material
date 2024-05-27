#include <iostream>
using namespace std;

int main()
{
	int laci[7] = {11, 12, 34, 45, 67, 88, 98};
	int lokasi = 0;
	int input;
	
	//Mencetak isi array
	cout<<"Isi array"<<endl;
	for(int i = 0; i < 7; i++){
		cout<<laci[i]<<endl;
	}
	
	//Input
	cout<<"Masukkan angka: ";
	cin>>input;
	
	//Linear search
	while(lokasi < 7 && input != laci[lokasi]){
		lokasi++;
	}
	
	//Output
	if(lokasi == 7){
		cout << "Data tidak ditemukan";
	} else {
		cout<<"Nomor laci: " << lokasi + 1;
	}
	
	
	
	
      return 0;
}