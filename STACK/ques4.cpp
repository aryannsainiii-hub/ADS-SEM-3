#include <iostream>
#include <stack>
using namespace std;

void reverseString(string str) {
    stack<char> s;

    for (char ch : str) {
        s.push(ch);
    }

    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Reversed string: ";
    reverseString(str);

    return 0;
}