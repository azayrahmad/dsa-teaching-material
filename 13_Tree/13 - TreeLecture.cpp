#include <iostream>
using namespace std;

//Fungsi untuk membuat node baru untuk Tree
struct TreeNode {
	char data;
	struct TreeNode * kiri;
	struct TreeNode * kanan;
};

//Fungsi untuk menambah node baru ke dalam Binary Search Tree
TreeNode * tambahNode(char dataBaru){
	TreeNode * nodeBaru = new TreeNode;
	nodeBaru -> data = dataBaru;
	nodeBaru -> kiri = NULL;
	nodeBaru -> kanan = NULL;
	
	return nodeBaru;
	
}

//Fungsi untuk menelusuri tiap node dalam tree menggunakan prinsip In Order (kiri - akar - kanan)
void traverseInOrder(TreeNode * induk){
	if(induk != NULL){
		traverseInOrder(induk -> kiri); //Subtree kiri
		cout << induk -> data << " ";	//akar
		traverseInOrder(induk -> kanan);// Subtree kanan
	}
}

//Fungsi untuk menelusuri tiap node dalam tree menggunakan prinsip Pre Order (akar - kiri - kanan)
void traversePreOrder(TreeNode * induk){
	if(induk != NULL){
		cout << induk -> data << " ";	//akar
		traversePreOrder(induk -> kiri); //Subtree kiri
		traversePreOrder(induk -> kanan);// Subtree kanan
	}
}

//Fungsi untuk menelusuri tiap node dalam tree menggunakan prinsip Post Order (kiri - kanan - akar)
void traversePostOrder(TreeNode * induk){
	if(induk != NULL){
		traversePostOrder(induk -> kiri); //Subtree kiri
		traversePostOrder(induk -> kanan);// Subtree kanan
		cout << induk -> data << " ";	//akar
	}
}

int main(){
	//Bangun Tree
	TreeNode * akar = tambahNode('A');
	akar -> kiri = tambahNode('B');
	akar -> kanan = tambahNode('C');
	akar -> kiri -> kiri = tambahNode('D');
	akar -> kiri -> kanan = tambahNode('E');
	akar -> kanan -> kanan = tambahNode('F');
	
	//Traverse
	cout<<"Traverse InOrder: ";
	traverseInOrder(akar);
	cout << endl;
	cout<<"Traverse PreOrder: ";
	traversePreOrder(akar);
	cout << endl;
	cout<<"Traverse PostOrder: ";
	traversePostOrder(akar);
	cout << endl;
	
	return 0;
	
}