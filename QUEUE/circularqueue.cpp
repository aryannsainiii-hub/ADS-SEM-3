#include <iostream>
using namespace std;

class circularqueue {
private:
    int front;
    int rear;
    int size;
    int* arr;

public:
    // Constructor
    circularqueue(int s) {
        front = -1; 
        rear = -1;  
        size = s;
        arr = new int[s];
    }

    ~circularqueue() {
        delete[] arr;
    }

    void isfull() {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % size)) {
            cout << "full" << endl;
        } else {
            cout << "is'nt full" << endl;
        }
    }

    void isempty() {
        if (front == -1) { 
            cout << "empty" << endl;
        } else {
            cout << "is'nt empty" << endl;
        }
    } 

    void enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % size)) {
            cout << "Queue is full!" << endl;
            return;
        } else if (front == -1) { 
            front = rear = 0;
            arr[rear] = value;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        } else {
            rear++;
            arr[rear] = value;
        }
    }

    void dequeue() {
        if (front == -1) { 
            cout << "Queue is empty!" << endl;
            return;
        }
        int removedValue = arr[front];
        cout << "Dequeued: " << removedValue << endl;
        
        if (front == rear) {
            front = rear = -1; 
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }
    void display() {
        if (front == -1) { 
            cout << "Queue is empty!" << endl;
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
}; 
int main() {
    circularqueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();
    
    cq.dequeue();
    cq.display();
    
    cq.enqueue(60);
    cq.display();
    
    return 0;
}
