#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        int minData;
        Node* next;
        Node(int value, int minVal) : data(value), minData(minVal), next(nullptr) {}
    };
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        int minVal = isEmpty() ? value : min(value, top->minData);
        Node* newNode = new Node(value, minVal);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        return isEmpty() ? -1 : top->data;
    }

    int getMin() {
        return isEmpty() ? -1 : top->minData;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);
    cout << "Minimum: " << s.getMin() << endl;
    s.pop();
    s.pop();
    cout << "Top Element: " << s.peek() << endl;

    return 0;
}
