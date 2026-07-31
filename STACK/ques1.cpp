// implementation of stack using array
#include<iostream>
using namespace std;

#define size 5
int stack[size];
int top = -1;

void push(int value){
    if(top==size-1){
        cout<<"overflow";
    }
    else{
        top++;
        stack[top]=value;
        cout<<value<<" ";
    }
}
    void pop(){
        if(top==-1){
            cout<<"underflow";
        }
        else{
            cout<<stack[top]<<" ";
            top--;
        }
    }
    void peak(){
        if(top==-1){
            cout<<"empty";
        }
        else{
            cout<<stack[top]<<" ";
        }
    }
    bool isempty(){
        return (top==-1);
    }
    bool isfull(){
        return (top==size-1);
    }
    int main(){
        push(10);
        push(20);
        push(30);
        peak();
        pop();

        return 0;
    }
