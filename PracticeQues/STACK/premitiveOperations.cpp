#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Overflow";
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Underflow";
    }
    else
    {
        cout << stack[top];
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Empty";
    }
    else
    {
        cout << stack[top];
    }
}

int main()
{
    push(10);
    push(20);
    peek();
    pop();

    return 0;
}