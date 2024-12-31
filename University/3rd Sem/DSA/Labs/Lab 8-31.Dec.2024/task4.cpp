#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
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

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void sortedInsert(Stack& s, int value) {
    if (s.isEmpty() || value > s.peek()) {
        s.push(value);
        return;
    }
    int temp = s.peek();
    s.pop();
    sortedInsert(s, value);
    s.push(temp);
}

void sortStack(Stack& s) {
    if (!s.isEmpty()) {
        int temp = s.peek();
        s.pop();
        sortStack(s);
        sortedInsert(s, temp);
    }
}

int main() {
    Stack s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    cout << "Original stack: ";
    s.display();

    sortStack(s);

    cout << "Sorted stack in Descending Order: ";
    s.display();

    return 0;
}
