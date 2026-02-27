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

	return(nodeBaru);

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


int main() {
	TreeNode *akar = tambahNode('F');
	akar->kiri = tambahNode('B');
	akar->kanan = tambahNode('G');
	akar->kiri->kiri = tambahNode('A');
	akar->kiri->kanan = tambahNode('D');
	akar->kiri->kanan->kiri = tambahNode('C');
	akar->kiri->kanan->kanan = tambahNode('E');
	akar->kanan->kanan = tambahNode('I');
	akar->kanan->kanan->kiri = tambahNode('H');

	traverseInOrder(akar);
	cout <<endl;
	traversePreOrder(akar);
	cout <<endl;
	traversePostOrder(akar);
	cout <<endl;




	return 0;
}