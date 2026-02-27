
#include <iostream>

using namespace std;

void luasLingkaran (int diameter){
	int luas;

	luas = diameter * diameter * 22 / 7;

	cout<<luas<<endl;

}

int main (void) {
	int diameterA = 3;
	int diameterB = 5;
	int diameterC = 8;
	int diameterD = 9;

	luasLingkaran(diameterA);
	luasLingkaran(diameterB);
	luasLingkaran(diameterC);
	luasLingkaran(diameterD);

	return 0;
}
