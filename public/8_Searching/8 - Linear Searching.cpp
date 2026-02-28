#include <iostream>
using namespace std;

int main()
{
	int laci[7] = {11, 12, 34, 45, 67, 88, 98};
	int atas = 0;
	int n;

	//Mencetak isi array
	cout<<"Isi array"<<endl;
	for(int i = 0; i < 7; i++){
		cout<<laci[i]<<endl;
	}

	//Input
	cout<<"Masukkan angka: ";
	cin>>n;

	//Linear search
	while(n != laci[atas]){
		atas++;
	}

	//Output
	cout<<"Nomor laci: ";
	cout<<atas;


      return 0;
}