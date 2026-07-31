//write a program to implement a  linear queue using linked-list
//leetcode-80 , 232 , 225 , 1472
#include<iostream>
using namespace std;

 struct node{
    int data;
    node*next;
 };

 node* front = NULL;
 node* rear = NULL;

 void enqueue(int value){
    node* newnode = new node;
    newnode->data = value;
    newnode->next = NULL;

    if(front==NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
                rear = newnode;

    }
    cout<<value<<endl;
 }
  void dequeue(int value){

    if(front==NULL){
        cout<<"empty"<<endl;
        return;
        }
        node* temp  = front;
        cout<<front->data<<endl;

        front = front->next;

        if(front==NULL){
            rear = NULL;
        }
        delete temp;
    }
 void display() {
    if (front == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    node* temp = front;

    cout << "Queue: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

    int main(){
        enqueue(10);
        enqueue(20);
        enqueue(30);
        
        display();
        dequeue(10);
        display();

        return 0;
    }