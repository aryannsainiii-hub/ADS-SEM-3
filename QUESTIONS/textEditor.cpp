#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char ch) {
        data = ch;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char ch) {
        Node* newNode = new Node(ch);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Nothing to undo!\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "Text is empty\n";
            return;
        }

        displayReverse(top);
        cout << endl;
    }

    void displayReverse(Node* node) {
        if (node == nullptr)
            return;

        displayReverse(node->next);
        cout << node->data;
    }
};

int main() {
    Stack editor;

    int n;
    cin >> n;

    while (n--) {
        char operation;
        cin >> operation;

        if (operation == 'P') {
            char ch;
            cin >> ch;
            editor.push(ch);
        }
        else if (operation == 'U') {
            editor.pop();
        }
        else if (operation == 'T') {
            editor.display();
        }
    }

    return 0;
}