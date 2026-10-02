#include<iostream>
using namespace std;

char * stack;
int top = -1;
int stackSize;

void push (char value){
    if(top==stackSize-1){
        cout<<"overflow";
    }
    else{
        top++;
        stack[top]=value;
    }
}
 void pop(){
        if (top == -1)
    {
        cout << "Underflow";
    }
    else
    {
        top--;
    }
 }

 bool isempty(){
    return top==-1;
 }

 bool check(string exp){
    for(int i = 0; i<exp.length();i++){
        if(exp[i]=='('){
            push('(');
        }
        else if(exp[i]==')'){
            if(isempty()){
                return false;
            }
            pop();
        }
    }
    return isempty();
 }

 int main()
{
    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    stackSize = exp.length();

    stack = new char[stackSize];

    if (check(exp))
    {
        cout << "Valid Parenthesized Expression";
    }
    else
    {
        cout << "Invalid Parenthesized Expression";
    }

    delete[] stack;

    return 0;
}