#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat node baru
Node* newNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Preorder Traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder Traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    // Membentuk Tree
    //     10
    //    /  \
    //   5    20
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);

    // Menambah beberapa node lagi
    //       10
    //      /  \
    //     5    20
    //    / \     \
    //   3   7    30
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(30);

    cout << "Preorder  : ";
    preorder(root);
    cout << endl;

    cout << "Inorder   : ";
    inorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    return 0;
}
