#include <iostream>
using namespace std;

struct TreeNode {
	char data;
	struct TreeNode * kiri;
	struct TreeNode * kanan;
};

TreeNode * tambahNode(char dataBaru) {

	TreeNode * nodeBaru = new TreeNode;
	nodeBaru -> data = dataBaru;
	nodeBaru -> kiri = NULL;
	nodeBaru -> kanan = NULL;

	return nodeBaru;

}

TreeNode * tambahNodeBST(TreeNode * induk, char dataBaru) {
	if (induk == NULL) {
		return tambahNode(dataBaru);
	}
	if (dataBaru < induk -> data) {
		induk->kiri = tambahNodeBST(induk->kiri, dataBaru);
	} else {
		induk->kanan = tambahNodeBST(induk->kanan, dataBaru);
	}

	return induk;
}

TreeNode * cariNodeBST(TreeNode * induk, char dataDicari) {
	if (induk == NULL) {
		cout << dataDicari << " tidak ada!"<< endl;
		return induk;
	}
	if (induk -> data == dataDicari) {
		cout << dataDicari << " ditemukan!"<< endl;
		return induk;
	}
	if (dataDicari < induk -> data) {
		cout << "Induk saat ini " << induk -> data << " setelah "<< dataDicari <<". Cari di subtree sebelah kiri."<< endl;
		return cariNodeBST(induk -> kiri, dataDicari);
	}

	cout << "Induk saat ini " << induk -> data << " sebelum "<< dataDicari <<". Cari di subtree sebelah kanan."<< endl;
	return cariNodeBST(induk -> kanan, dataDicari);
}

void traversePreOrder(TreeNode * induk) {
	if(induk != NULL) {

		cout << induk -> data << " ";
		traversePreOrder(induk -> kiri);
		traversePreOrder(induk -> kanan);
	}
}

void traverseInOrder(TreeNode * induk) {
	if(induk != NULL) {

		traverseInOrder(induk -> kiri);
		cout << induk -> data << " ";
		traverseInOrder(induk -> kanan);
	}
}

void traversePostOrder(TreeNode * induk) {
	if(induk != NULL) {

		traverseInOrder(induk -> kiri);
		traverseInOrder(induk -> kanan);
		cout << induk -> data << " ";
	}
}


int main() {
	TreeNode *akar = NULL;
	akar = tambahNodeBST(akar, 'F');
	akar = tambahNodeBST(akar, 'B');
	akar = tambahNodeBST(akar, 'G');
	akar = tambahNodeBST(akar, 'A');
	akar = tambahNodeBST(akar, 'D');
	akar = tambahNodeBST(akar, 'I');
	akar = tambahNodeBST(akar, 'C');
	akar = tambahNodeBST(akar, 'E');
	akar = tambahNodeBST(akar, 'H');

	traverseInOrder(akar);

	cariNodeBST(akar, 'E');
	cariNodeBST(akar, 'O');




	return 0;
}