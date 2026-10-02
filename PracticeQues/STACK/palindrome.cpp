#include <iostream>
using namespace std;

int *stack;
int top = -1;
int stackSize;

void push(int value)
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

int pop()
{
    if (top == -1)
    {
        cout << "Underflow";
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

bool isEmpty()
{
    return top == -1;
}

bool isPalindrome(int num)
{
    int original = num;

    int temp = num;

    while (temp > 0)
    {
        int digit = temp % 10;

        push(digit);

        temp = temp / 10;
    }

    int reverse = 0;

    while (!isEmpty())
    {
        int digit = pop();

        reverse = reverse * 10 + digit;
    }

    return original == reverse;
}

int main()
{
    int num;

    cout << "Enter number: ";
    cin >> num;

    int temp = num;
    stackSize = 0;

    while (temp > 0)
    {
        stackSize++;
        temp = temp / 10;
    }

    stack = new int[stackSize];

    if (isPalindrome(num))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    delete[] stack;

    return 0;
}