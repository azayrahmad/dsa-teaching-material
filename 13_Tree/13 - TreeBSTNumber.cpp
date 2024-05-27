#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	struct TreeNode * kiri;
	struct TreeNode * kanan;
};

TreeNode * tambahNode(int dataBaru) {

	TreeNode * nodeBaru = new TreeNode;
	nodeBaru -> data = dataBaru;
	nodeBaru -> kiri = NULL;
	nodeBaru -> kanan = NULL;

	return nodeBaru;

}

TreeNode * tambahNodeBST(TreeNode * induk, int dataBaru) {
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

TreeNode * cariNodeBST(TreeNode * induk, int dataDicari) {
	if (induk == NULL)
	{
		cout << dataDicari << " tidak ada!"<< endl;
		return induk;
	}
	if (induk -> data == dataDicari)
	{
		cout << dataDicari << " ditemukan!"<< endl;
		return induk;
	}
	if (dataDicari < induk -> data){
		cout << "Induk saat ini setelah yaitu " << induk -> data << ". Cari di subtree sebelah kiri."<< endl;
		return cariNodeBST(induk -> kiri, dataDicari);
	}
	
	cout << "Induk saat ini sebelum yaitu " << induk -> data << ". Cari di subtree sebelah kanan."<< endl;
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

		traversePostOrder(induk -> kiri);
		traversePostOrder(induk -> kanan);
		cout << induk -> data << " ";
	}
}

void cetakTree(const string& cabang, TreeNode * induk, bool isLeft){
	if(induk != NULL){
		cout << cabang;
		cout << (isLeft ? "|--" : "L--");
		cout << induk->data<<endl;
		cetakTree(cabang + (isLeft ? "|   " : "    "), induk -> kiri, true);
		cetakTree(cabang + (isLeft ? "|   " : "    "), induk -> kanan, false);
		
	}
}

int main() {
	TreeNode *akar = NULL;
	akar = tambahNodeBST(akar, 72);
	akar = tambahNodeBST(akar, 54);
	akar = tambahNodeBST(akar, 83);
	akar = tambahNodeBST(akar, 34);
	akar = tambahNodeBST(akar, 5);
	akar = tambahNodeBST(akar, 47);
	akar = tambahNodeBST(akar, 75);
	akar = tambahNodeBST(akar, 88);
	akar = tambahNodeBST(akar, 101);
	akar = tambahNodeBST(akar, 94);
	
	akar = tambahNodeBST(akar, 27);
	akar = tambahNodeBST(akar, 15);
	akar = tambahNodeBST(akar, 63);
	akar = tambahNodeBST(akar, 99);
	akar = tambahNodeBST(akar, 70);
	akar = tambahNodeBST(akar, 85);
	
	
	cetakTree("", akar, false);
	
	traversePreOrder(akar);
	cout << endl;
	traverseInOrder(akar);
	cout << endl;
	traversePostOrder(akar);
	




	return 0;
}