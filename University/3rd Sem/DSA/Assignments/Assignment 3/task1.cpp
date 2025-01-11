#include <iostream>
#include <string>

using namespace std;

class MyQueue {
private:
    string* data;
    int frontIndex;
    int backIndex;
    int size;
    int capacity;

public:
    MyQueue(int cap) {
        data = new string[cap];
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

    void push(const string& value) {
        if (!isFull()) {
            backIndex = (backIndex + 1) % capacity;
            data[backIndex] = value;
            size++;
        } else {
            cout << "Queue is full. Cannot add more elements." << endl;
        }
    }

    string front() {
        if (isEmpty()) {
            return "";
        }
        return data[frontIndex];
    }

    void pop() {
        if (!isEmpty()) {
            frontIndex = (frontIndex + 1) % capacity;
            size--;
        }
    }

    int getSize() {
        return size;
    }
};

string* generateBinaryNumbers(int n) {
    if (n <= 0) {
        return nullptr;
    }

    string* result = new string[n];
    MyQueue q(n * 2); 

    string initial = "1";
    q.push(initial);

    for (int i = 0; i < n; ++i) {
        string current = q.front();
        q.pop();
        result[i] = current;

        string zero = current + "0";
        string one = current + "1";

        q.push(zero);
        q.push(one);
    }

    return result;
}

int main() {
    int n;

    cout << "Enter the number of binary numbers to generate (positive integer only): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    string* binaryNumbers = generateBinaryNumbers(n);

    cout << "The first " << n << " binary numbers are: ";
    for (int i = 0; i < n; ++i) {
        cout << binaryNumbers[i] << " ";
    }
    cout << endl;

    delete[] binaryNumbers; 
    return 0;
}
