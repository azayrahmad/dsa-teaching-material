#include <iostream>
using namespace std;

int main()
{
	int ukuran = 7;
	int laci[ukuran] = {11, 12, 34, 45, 67, 88, 98};
	int input;
	int output = 0;
	
	//Mencetak isi array
	cout<<"Isi array"<<endl;
	for(int i = 0; i < ukuran; i++)
  	{
		cout<<laci[i]<<endl;
	}
	
	//Input
	cout<<"Masukkan angka: ";
	cin>>input;

  	//Cari angka di sini
  	int left = 0;
    int right = ukuran - 1;
    
    bool ketemu = false;

    while (left <= right && !ketemu) 
	{
        int mid = left + (right - left) / 2;

        if (laci[mid] == input) {
            output = mid; // Target ditemukan di indeks 'mid'
            ketemu = true;
        } 
		else if (laci[mid] < input) 
		{
            left = mid + 1; // Cari di sebelah kanan
        } 
		else 
		{
            right = mid - 1; // Cari di sebelah kiri
        }
    }

	
	//Output
	if (ketemu)
	{
		cout<<"Nomor laci: " << output + 1;
	}
	else
	{
		cout<< "Tidak ketemu";
	}

	
	
  return 0;
}
