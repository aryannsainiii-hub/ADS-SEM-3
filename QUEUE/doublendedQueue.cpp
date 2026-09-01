#include <iostream>
using namespace std;

class deque {
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    deque(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }


    ~deque() {
        delete[] arr;
    }

    bool isFull() const {
        return count == capacity;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void insertfront(int value) {
        if (isFull()) {
            cout << "deque is full" << endl;
            return;
        }     front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        ++count;
        if (count == 1) {
            rear = front;
        }
    }

    void insertrear(int value){
        if(isFull()){
            cout<<"deque is full"<<endl;
            return;
        }
        rear = (rear + 1)% capacity;
        arr[rear]=value;
        ++count;
        if(count==1){
            front = rear;

        }
    }


    void deletefront(){
        if(isEmpty()){
            cout<<"deque is empty"<<endl;
            return;
        }
        cout<<"deleted"<<arr[front]<<endl;  
        front = (front + 1)%capacity;
        --count;
        if(count==0){
            front = 0;
            rear = -1;
        }
    }
        void deleterear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deleted: " << arr[rear] << endl;
        rear = (rear - 1 + capacity) % capacity;
        --count;
        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        for (int index = 0; index < count; ++index) {
            cout << arr[(front + index) % capacity] << ' ';
        }
        cout << endl;
    }
};

int main() {
    deque values(5);
    values.insertrear(20);
    values.insertrear(30);
    values.insertfront(10);
    values.display();
    values.deletefront();
    values.deleterear();
    values.display();

    return 0;
}
    

