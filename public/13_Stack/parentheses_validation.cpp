#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            if (c == ')' && st.top() != '(') return false;
            if (c == '}' && st.top() != '{') return false;
            if (c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string input;
    cout << "=== VALIDASI TANDA KURUNG ===" << endl;
    cout << "Masukkan urutan tanda kurung (cth: ({[]})): ";
    cin >> input;

    if (isValid(input)) {
        cout << "Valid!" << endl;
    } else {
        cout << "Tidak Valid!" << endl;
    }

    return 0;
}
