#include <iostream>
using namespace std;
int main() {
	
	int dataBaru = 45;
	int rakHitam[4] = {45, 78, 92};
	rakHitam[3] = 123;
	
	int rakCoklat[4][2] = {{32, 45},
							{46, 67},
							{98, 12},
							{13, 50}};

	
	cout<<rakCoklat[2][1]<<endl;


	return 0;
}