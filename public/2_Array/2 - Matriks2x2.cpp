#include <iostream>
using namespace std;

int main () {
	const int matrixSize = 2;
	int matrix[2][2];

	cout << "Silahkan masukkan elemen matriks M: " << endl;

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			cout << "M[" << i+1 << "]["<< j+1 << "]: ";
			cin >> matrix[i][j];
		}
	}

	cout<<"Matriks M adalah:"<<endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cout << matrix[i][j] <<" ";
		cout<<endl;
	}

	cout<<"Determinan matriks M adalah: ";
	cout<<(matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]) <<endl;

	return 0;

}
