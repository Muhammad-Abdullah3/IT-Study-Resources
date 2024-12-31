#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

class MinStack {
private:
    struct MinNode {
        int data;
        int minSoFar;
        MinNode* next;
    };
    MinNode* top;

public:
    MinStack() : top(nullptr) {}

    void push(int value) {
    int currentMin;
    if (top == nullptr) {
        currentMin = value;
    } else {
        currentMin = min(value, top->minSoFar);
    }

    MinNode* newNode = new MinNode;
    newNode->data = value;
    newNode->minSoFar = currentMin;
    newNode->next = top;

    top = newNode;
}

    int pop() {
        if (!top) {
            cout << "Stack underflow: No elements to pop" << endl;
            return -1;
        }
        int value = top->data;
        MinNode* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    int getMin() {
        if (!top) {
            cout << "Stack is empty: No minimum available" << endl;
            return -1;
        }
        return top->minSoFar;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    MinStack stack;
    stack.push(3);
    stack.push(5);
    stack.push(2);
    stack.push(1);
    stack.push(9);

    cout << "Minimum: " << stack.getMin() << endl; // Should print 1
    return 0;
}
