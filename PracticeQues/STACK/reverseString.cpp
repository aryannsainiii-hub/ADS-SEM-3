#include <iostream>
#include <string>
using namespace std;

char *stack;
int top = -1;
int Stacksize;

void push(char value)
{
    if (top == Stacksize - 1)
    {
        cout << "Overflow";
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

char pop()
{
    if (top == -1)
    {
        cout << "Underflow";
        return '\0';
    }
    else
    {
        char value = stack[top];
        top--;
        return value;
    }
}

bool isEmpty()
{
    return top == -1;
}

string reverseString(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        push(str[i]);
    }

    string reverse = "";

    while (!isEmpty())
    {
        reverse = reverse + pop();
    }

    return reverse;
}

int main()
{
    string str;

    cout << "Enter string: ";
    cin >> str;

    Stacksize = str.length();

    stack = new char[Stacksize];

    cout << "Reversed string: " << reverseString(str);

    delete[] stack;

    return 0;
}