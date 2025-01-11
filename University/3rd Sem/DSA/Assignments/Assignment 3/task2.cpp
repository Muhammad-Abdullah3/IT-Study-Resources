#include <iostream>
#include <string>

using namespace std;

class MyQueue {
private:
    int* data;
    int frontIndex;
    int backIndex;
    int size;
    int capacity;

public:
    MyQueue(int cap) {
        data = new int[cap];
        frontIndex = 0;
        backIndex = -1;
        size = 0;
        capacity = cap;
    }

    ~MyQueue() {
        delete[] data;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(const int& value) {
        if (!isFull()) {
            backIndex = (backIndex + 1) % capacity;
            data[backIndex] = value;
            size++;
        } else {
            cout << "Queue is full. Cannot add more elements." << endl;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicating error
        }
        int frontValue = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return frontValue;
    }

    int getSize() {
        return size;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            cout << data[(frontIndex + i) % capacity] << " ";
        }
        cout << endl;
    }
};

void interleaveQueue(MyQueue& q) {
    int n = q.getSize();

    if (n % 2 != 0) {
        cout << "Please provide an even number of elements." << endl;
        return;
    }

    MyQueue tempQueue(n / 2);
    int halfSize = n / 2;

    for (int i = 0; i < halfSize; ++i) {
        tempQueue.enqueue(q.dequeue());
    }

    for (int i = 0; i < halfSize; ++i) {
        q.enqueue(tempQueue.dequeue());
        q.enqueue(q.dequeue());
    }
}

int main() {
    MyQueue q(10);

    cout << "Enter 6 integers: ";
    for (int i = 0; i < 6; ++i) {
        int num;
        cin >> num;
        q.enqueue(num);
    }

    cout << "Queue before interleaving: ";
    q.print();

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    q.print();

    return 0;
}