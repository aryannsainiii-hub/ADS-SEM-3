//stack using linkedlist
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << top->data << " removed\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL)
            cout << "Stack Empty\n";
        else
            cout << top->data << endl;
    }

    void display() {
        Node* temp = top;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.display();

    s.pop();

    s.display();
}