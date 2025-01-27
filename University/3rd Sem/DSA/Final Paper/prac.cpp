#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        // Try allocating memory for a new node
        Node* newNode = new (nothrow) Node(); // nothrow avoids throwing exceptions
        if (newNode == nullptr) { // Check if memory allocation failed
            cout << "Stack Overflow (Memory allocation failed)\n";
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed onto the stack.\n";
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow (Stack is empty)\n";
        } else {
            Node* temp = top;
            cout << temp->data << " popped from the stack.\n";
            top = top->next;
            delete temp;
        }
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    // Push elements into the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); // Output: Stack elements: 30 20 10

    // Pop elements from the stack
    stack.pop();
    stack.display(); // Output: Stack elements: 20 10

    // Check the top element
    cout << "Top element: " << stack.peek() << endl; // Output: 20

    // Pop remaining elements
    stack.pop();
    stack.pop();
    stack.pop(); // Output: Stack Underflow (Stack is empty)

    // Check if stack is empty
    cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl; // Output: Stack is empty

 return 0;
}