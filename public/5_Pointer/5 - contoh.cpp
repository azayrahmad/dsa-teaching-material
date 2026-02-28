#include<iostream>
#include<string>

using namespace std;

int main(){
	string rumah = "Budi"; //Deklarasi
	string &alamat = rumah; //Alamat mereferensikan rumah
	alamat = "Ibu Budi";// alamat diganti isinya, variabel rumah juga berganti

	string *pointerRumah = &alamat;


	//cout << pointerRumah; //menampilkan alamat memori (hexa)
	//cout << *pointerRumah; //menampilkan isi dari alamat tersebut
	*pointerRumah = "Ayah Budi";

	//cout << rumah;

	string kos[3];
	kos[0] = "Andi";
	kos[1] = "Budi";
	kos[2] = "Chandra";
	string *pointerKost;
	pointerKost = kos;
	pointerKost += 2;
	cout << pointerKost;
}