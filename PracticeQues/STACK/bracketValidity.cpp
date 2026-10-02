#include <iostream>
#include <string>
using namespace std;

char *stack;
int top = -1;
int stackSize;

void push(char value)
{
    if (top == stackSize - 1)
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
        top--;
    }
}

bool isEmpty()
{
    return top == -1;
}

bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;

    if (open == '[' && close == ']')
        return true;

    if (open == '{' && close == '}')
        return true;

    return false;
}

bool checkBrackets(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty())
            {
                return false;
            }

            char open = stack[top];

            if (!isMatching(open, exp[i]))
            {
                return false;
            }

            pop();
        }
    }

    return isEmpty();
}

int main()
{
    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    stackSize = static_cast<int>(exp.length());

    stack = new char[stackSize];

    if (checkBrackets(exp))
    {
        cout << "Valid Bracketed Expression";
    }
    else
    {
        cout << "Invalid Bracketed Expression";
    }

    delete[] stack;

    return 0;
}