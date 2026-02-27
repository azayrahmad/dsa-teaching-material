#include <iostream>
#define MAX 5
using namespace std;

struct Stack {
	int top;
	int data[MAX];
};

Stack tumpukan;

void push(int input) {
	tumpukan.top++;
	tumpukan.data[tumpukan.top]=input;
}

void pop(){
	tumpukan.top--;
}


void tampilkanIsiStack() {
	if (tumpukan.top == -1) {
		cout << "Tumpukan kosong";
	} else {
		cout << "Tumpukan : " << endl;
		for (int i = tumpukan.top; i >= 0; i--)
			cout << tumpukan.data[i] << endl;
	}
	cout<<endl;
}




int main() {
	tumpukan.top = -1;

	tampilkanIsiStack();
	push(53);
	tampilkanIsiStack();
	push(45);
	tampilkanIsiStack();
	pop();
	tampilkanIsiStack();

}
