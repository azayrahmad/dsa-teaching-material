#include <iostream>

using namespace std;

int main() {

	string kost[3];
	kost[0] = "Adi";
	kost[1] = "Budi";
	kost[2] = "Citra";
	
	string *pointerKost;
	
	pointerKost = kost;
	pointerKost = pointerKost + 2;
	
	cout<<pointerKost;
	
	return 0;
}

