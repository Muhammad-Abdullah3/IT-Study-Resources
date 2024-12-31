#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
        Node(char value) : data(value), next(nullptr) {}
    };
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(char value) {
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

    char peek() {
        return isEmpty() ? '\0' : top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

string reverseString(const string& str) {
    Stack s;
    for (char ch : str) s.push(ch);

    string reversed = "";
    while (!s.isEmpty()) {
        reversed += s.peek();
        s.pop();
    }
    return reversed;
}

int main() {
    string input = "Abdullah";
    cout << "Original: " << input << endl;
    cout << "Reversed: " << reverseString(input) << endl;
    return 0;
}
