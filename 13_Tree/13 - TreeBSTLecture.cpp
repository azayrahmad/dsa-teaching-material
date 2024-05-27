#include <iostream>
using namespace std;

struct TreeNode {
	char data;
	struct TreeNode * kiri;
	struct TreeNode * kanan;
};

//Fungsi untuk membuat node baru untuk Tree
TreeNode * tambahNode(char dataBaru){
	TreeNode * nodeBaru = new TreeNode;
	nodeBaru -> data = dataBaru;
	nodeBaru -> kiri = NULL;
	nodeBaru -> kanan = NULL;
	
	return nodeBaru;
	
}

//Fungsi untuk menambah node baru ke dalam Binary Search Tree
TreeNode * tambahNodeBST(TreeNode * induk, char dataBaru){
	if (induk == NULL){
		return tambahNode(dataBaru);
	}
	if (dataBaru < induk -> data){
		induk -> kiri = tambahNodeBST(induk -> kiri, dataBaru);
	} else {
		induk -> kanan = tambahNodeBST(induk->kanan, dataBaru);
	}
	
	return induk;
}

//Fungsi untuk mencari data tertentu di dalam Binary Search Tree
TreeNode * cariNodeBST(TreeNode * induk, char dataDicari){
	if (induk == NULL){
		cout << dataDicari << " tidak ditemukan!" << endl;
		return induk;
	}
	if (induk -> data == dataDicari){
		cout << dataDicari << " ditemukan!" << endl;
		return induk;
	}
	if (dataDicari < induk -> data){
		return cariNodeBST(induk -> kiri, dataDicari);
	}
	return cariNodeBST(induk -> kanan, dataDicari);
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
	//Membangun Binary Search Tree
	TreeNode * akar = NULL;
	akar = tambahNodeBST(akar, 'A');
	akar = tambahNodeBST(akar, 'B');
	akar = tambahNodeBST(akar, 'C');
	akar = tambahNodeBST(akar, 'D');
	akar = tambahNodeBST(akar, 'E');
	
	//Traversal
	cout<<"Traverse InOrder: ";
	traverseInOrder(akar);
	cout << endl;
	cout<<"Traverse PreOrder: ";
	traversePreOrder(akar);
	cout << endl;
	cout<<"Traverse PostOrder: ";
	traversePostOrder(akar);
	cout << endl;
	
	//Searching
	cariNodeBST(akar, 'C'); //Harusnya ada
	cariNodeBST(akar, 'P'); //Harusnya tidak ada
	return 0;
	
}